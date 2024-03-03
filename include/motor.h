#ifndef MOTORH
#define MOTORH

class motor
{
private:
    const int pinL; // left pin
    const int pinR; // right pin
    int speed = 0; // current speed
public:
    motor(int pinL, int pinR);
    void drive(int speed);
    void drive(int speed, int time, int mode);
    void stop();
};

#endif