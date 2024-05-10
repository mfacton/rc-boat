#include <Servo.h>

#define MAX_CHANNELS 5

#define RIGHT_PROP 0
#define LEFT_PROP 1 //left prop inverted

//bottom -> top
#define LEFT_DEP 2 //73 -> 173
#define RIGHT_DEP 3 //103 -> 3

const int pwmPins[MAX_CHANNELS] = {3, 5, 6, 9, 10};
Servo servos[MAX_CHANNELS];

void setup() {
  for (uint8_t c = 0; c < MAX_CHANNELS; c++) {
    servos[c].attach(pwmPins[c]);
  }
  servos[LEFT_PROP].write(0);
  servos[RIGHT_PROP].write(180);
  servos[LEFT_DEP].write(73);
  servos[RIGHT_DEP].write(103);
  delay(3000);
  servos[LEFT_DEP].write(174);
  servos[RIGHT_DEP].write(4);
  servos[LEFT_PROP].write(90);
  servos[RIGHT_PROP].write(90);
}

void loop() {
}
