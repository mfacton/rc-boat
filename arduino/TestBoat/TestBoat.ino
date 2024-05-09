#include <Servo.h>

#define MAX_CHANNELS 5

#define RIGHT_PROP 0


const int pwmPins[MAX_CHANNELS] = {3, 5, 6, 9, 10};
Servo servos[MAX_CHANNELS];

void setup() {
  for (uint8_t c = 0; c < MAX_CHANNELS; c++) {
    servos[c].attach(pwmPins[c]);
  }
}

void loop() {
  servos[1].write(80);
  delay(1000);
  servos[1].write(100);
  delay(1000);
  // servos[1].write(90);
  // servos[2].write(90);
  // servos[3].write(90);
  // servos[4].write(90);
}
