#include <Arduino.h>
#include <FreeRTOS.h>
#include "motor.h"

motor m1(10,11);
void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 0; i < 255; i+=5)
  {
    m1.drive(i,800,1);
    delay(2000);
  }
  m1.drive(50,5000,1);
  delay(1000);
  m1.drive(0,5000,1);
  delay(5000);
}