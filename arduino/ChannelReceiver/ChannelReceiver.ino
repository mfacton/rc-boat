#include <Servo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define MAX_CHANNELS 5

const int pwmPins[MAX_CHANNELS] = {3, 5, 6, 9, 10};
Servo servos[MAX_CHANNELS];

const byte nrfAddress[6] = "00001";
RF24 radio(7, 8); // CE, CSN pins

uint8_t data[MAX_CHANNELS];

void setup() {
  for (uint8_t c = 0; c < MAX_CHANNELS; c++) {
    servos[c].attach(pwmPins[c]);
  }
  radio.begin();
  radio.openReadingPipe(1, nrfAddress);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    radio.read(data, MAX_CHANNELS);
    for (uint8_t c = 0; c < MAX_CHANNELS; c++) {
      servos[c].write(data[c]);
    }
  }
  delay(1);
}
