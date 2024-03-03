#include <Arduino.h>
#include <FreeRTOS.h>
#include "motor.h"

motor m1(10,11);
void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  m1.drive(50,5000,1);
  delay(5000);
  m1.drive(255,5000,1);
  delay(5000);
}