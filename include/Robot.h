#ifndef ROBOT_H
#define ROBOT_H
#include <Arduino.h>
#include <Motor.h>
#include <MPU.h>

class Robot{
    public:

   
   
    Motor innerMotor = Motor(2, 3);
    Motor outerMotor = Motor(4, 7);
    
    MPU innerMPU = MPU(0x68, "Inner MPU");
    MPU outerMPU = MPU(0x69, "Outer MPU");

    bool innerMove = false;
    bool outerMove = false;
    

    Robot();
    void init();
    void move(int8_t speed);
    void stair_climb(int8_t speed);
    void stop();
    
};
#endif