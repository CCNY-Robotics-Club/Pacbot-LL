#include "motor.h"
#include <Arduino.h>
#include <math.h>

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
 * @param speed motor speed (-255 - 255)
*/
void motor::drive(int speed)
{
    this->stop();
    this->speed = speed;
    if (speed > 0) analogWrite(pinR,speed);
    else analogWrite(pinL,-speed);
}

/**
 * Change motor speed by time and function
 * @param desired_speed desired motor speed (-255 - 255)
 * @param time period to change speed along
 * @param mode regression (1 = linear, 2 = arctan)
*/
void motor::drive(int desired_speed, int time, int mode)
{
    // Gather current state first
    int current_speed = this->speed;
    int speed_difference = abs(desired_speed - current_speed);
    float ramp_tick = time / speed_difference;
    this->stop();
    if (mode == 1) // linear regression
    {
        if (current_speed < desired_speed)
            while(current_speed < desired_speed)
            {
                this->drive(++current_speed);
                delay(ramp_tick);
            }
        else
            while(current_speed > desired_speed)
            {
                this->drive(--current_speed);
                delay(ramp_tick);
            }
    }
    else if (mode == 0) // arctangent regression
    {
        // TODO: implemtn! So just call with linear regression for now.
        this->drive(desired_speed,time,1);
    }
}

/**
 * Halt the motor.
*/
void motor::stop()
{
    analogWrite(pinL,0);
    analogWrite(pinR,0);
}