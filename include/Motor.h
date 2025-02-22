#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {

private:
   
    uint8_t EN;
    uint8_t IN1;
    uint8_t IN2;

public:


    uint8_t speed; 
    Motor(uint8_t IN1, uint8_t IN2);
    void init();
    void forward();
    void backward();
    void stop();
    // void setSpeed(uint8_t speed);
    // uint8_t getSpeed();

    

};

#endif

