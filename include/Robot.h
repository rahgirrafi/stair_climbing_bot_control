#ifndef ROBOT_H
#define ROBOT_H
#include <Arduino.h>
#include <Motor.h>
#include <MPU.h>

class Robot{
    public:

        Motor leftMotor = Motor(2, 3);
        Motor rightMotor = Motor(4, 7);
        MPU mpu;

    
        Robot();
        void init();
        void move(int8_t speed);
        void move_PID(int8_t speed);
        void stop();
};
#endif