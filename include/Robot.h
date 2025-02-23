#ifndef ROBOT_H
#define ROBOT_H
#include <Arduino.h>
#include <Motor.h>
#include <MPU.h>

class Robot{
    public:

   
   
    Motor innerMotorLeft = Motor(5, 8);
    Motor innerMotorRight = Motor(6, 9);
    Motor outerMotorLeft = Motor(10, 11);
    Motor outerMotorRight = Motor(12, 13);
    
    
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