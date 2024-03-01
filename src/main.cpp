#include "motor.h"
#include <Arduino.h>

motor m1(10,11);
void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  m1.driveL(255);
  delay(500);
  m1.driveR(255);
  delay(500);
}