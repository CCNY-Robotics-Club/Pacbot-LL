#ifndef MOTORH
#define MOTORH

class motor
{
private:
    int pinL; // left pin
    int pinR; // right pin
    int speed = 0; // current speed
public:
    motor(int pinL, int pinR);
    void drive(int speed);
    void drive(int speed, int time, int mode);
    void stop();
};

#endif