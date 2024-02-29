#include <Adafruit_VL6180X.h>
#include <Wire.h>
#include <Arduino.h>

Adafruit_VL6180X mySens = Adafruit_VL6180X();

void setup() {
  mySens.begin();
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(mySens.readRange());
  Serial.print('\n');
  delay(100);
}