#ifndef MOTORH
#define MOTORH

class motor
{
private:
    const int MAX_SPEED = 400;
    const int MIN_SPEED = 50;

    int pinL; // left pin
    int pinR; // right pin
    int speed; // current speed
public:
    motor(int pinL, int pinR);
    void driveL(int speed);
    void driveR(int speed);
    void stop();
};

#endif