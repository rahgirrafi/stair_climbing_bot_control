#ifndef ROBOT_H
#define ROBOT_H
#include <Arduino.h>
#include <Motor.h>
#include <MPU.h>

class Robot{
    public:

    float error1, error2 ;
    float lastError;
    Motor innerMotor = Motor(2, 3);
    Motor outerMotor = Motor(4, 7);
    
    MPU innerMPU = MPU(0x68);
    MPU outerMPU = MPU(0x69);
    
    float kp = 0.5;
    float kd = 0.5;
    float ki = 0;

    Robot();
    void init();
    void move(int8_t speed);
    void stair_climb(int8_t speed);
    void stop();
    
    struct PID{
        float kp;
        float ki;
        float kd;
        float error;
        float lastError;
        float P, D, PID_value;
        PID(float kp, float ki, float kd){
            this->kp = kp;
            this->kd = kd;
            this->ki = ki;
        }
        void calculate(){
            P = kp * error;
            D = kd * (error - lastError);
            PID_value = P + D;
            lastError = error;
        }
        void setError(float error){
            this->error = error;
        }
    };
    PID innerPID = PID(0.5, 0, 0.5), outerPID = PID(0.5, 0 , 0.5);
};
#endif