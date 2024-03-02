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
 * Change motor speed by time and function
 * @param dir direction (CW if true, CCW if false)
 * @param desired_speed desired motor speed
 * @param time period to change speed along
 * @param mode speed change function (linear vs arctan)
 * TODO: range?
*/
void motor::drive(int desired_speed, int time, int mode)
{
    // Gather current state first
    int current_speed = this->speed;
    int speed_difference = desired_speed - current_speed;
    int ramp_tick = time / speed_difference;
    this->stop();
    if (current_speed < desired_speed)
        while(current_speed < desired_speed) this->drive(++current_speed);
    else
        while(current_speed > desired_speed) this->drive(--current_speed);
}

/**
 * Halt the motor.
*/
void motor::stop()
{
    analogWrite(pinL,0);
    analogWrite(pinR,0);
}