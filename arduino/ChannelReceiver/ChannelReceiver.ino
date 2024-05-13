#include <Servo.h>
#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

#define MAX_CHANNELS 4

#define RIGHT_PROP 0
#define LEFT_PROP 1 //left prop inverted

//bottom -> top
#define LEFT_DEP 2 //73 -> 173
#define RIGHT_DEP 3 //103 -> 3

const int pwmPins[MAX_CHANNELS] = {3, 5, 6, 9};
Servo servos[MAX_CHANNELS];

RF24 radio(7, 8, 1000000); // CE, CSN pins

uint8_t data[MAX_CHANNELS];

void setup() {
  for (uint8_t c = 0; c < MAX_CHANNELS; c++) {
    servos[c].attach(pwmPins[c]);
    servos[c].write(90);
  }

  radio.begin();
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);
  radio.setChannel(124);//0-125
  uint8_t address[5] = "00001";
  radio.setCRCLength(RF24_CRC_16);
  radio.setAutoAck(0);
  radio.setPayloadSize(4);
  radio.openReadingPipe(0, address);
  radio.startListening();
  Serial.begin(9600);
}

void loop() {
  if (radio.available()) {
    radio.read(data, MAX_CHANNELS); 
    for (uint8_t c = 0; c < MAX_CHANNELS; c++) {
      servos[c].write(data[c]);
    }
  }
}
