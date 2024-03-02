#include <Arduino.h>
#include "motor.h"
/**
 * Instantiate a Motor Object.
 * @param pinL pin connected to left drive
 * @param pinR pin connected to right drive
*/
motor::motor(int pinL, int pinR)
{
    // Initialize Pins
    this->pinL = pinL;
    this->pinR = pinR;
}

/**
 * Change motor speed instantaneously
 * @param speed motor speed (postive CCW, negative CW)
*/
void motor::drive(int speed)
{
    this->stop();
    this->speed = speed;
    if (speed > 0) {analogWrite(pinR,speed);}
    else {analogWrite(pinL,speed);}
}

/**
 * Drive motor clockwise (right)
 * @param speed motor speed
 * TODO: range?
*/
void motor::driveR(int speed)
{
    this->stop();
    this->speed = speed;
    if (speed < 200) analogWriteFreq(500);
    else analogWriteFreq(500);
    analogWrite(pinR,speed);
}

/**
 * Halt the motor.
*/
void motor::stop()
{
    analogWrite(pinL,0);
    analogWrite(pinR,0);
}