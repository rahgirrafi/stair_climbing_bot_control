#include <Arduino.h>
#include <Motor.h>
#include <Robot.h>
#include <SoftPWM.h>

Robot::Robot(){

}

void Robot::init(){
    leftMotor.init();
    rightMotor.init();
    mpu.init();  
}

void Robot::move(int8_t speed){
    leftMotor.Speed(speed);
    rightMotor.Speed(speed);
}

void Robot::move_PID(int8_t speed){

    error = mpu.accelY;
     
    error = map(error, -1,1,-100,100);
    float P = kp * error;
    float D = kd * (error - lastError);
    lastError = error;
    float PID = P + D;

    if(error>0){
        leftMotor.Speed(speed + PID);
        rightMotor.Speed(speed - PID);
    }

    else{
        leftMotor.Speed(speed - PID);
        rightMotor.Speed(speed + PID);
    }

}


