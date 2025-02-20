#include <Arduino.h>
#include <Motor.h>
#include <Robot.h>
#include <SoftPWM.h>

Robot::Robot(){

}

void Robot::init(){
    innerMotor.init();
    outerMotor.init();
    innerMPU.init();  
    outerMPU.init();
}

void Robot::move(int8_t speed){
    innerMotor.Speed(speed);
    outerMotor.Speed(speed);
}

void Robot::stair_climb(int8_t speed){

    innerPID.setError(innerMPU.accelX);
    outerPID.setError(outerMPU.accelX);
    innerPID.calculate();
    outerPID.calculate();

    Serial.print("innerPID: " + String(innerPID.PID_value) + " outerPID: " + String(outerPID.PID_value) + "\n");


    if(innerPID.PID_value > 0){
        outerMotor.Speed(speed - innerPID.PID_value);
        innerMotor.Speed(speed);
    }
    
    else if(innerPID.PID_value < 0){
        innerMotor.Speed(speed - outerPID.PID_value);
        outerMotor.Speed(speed);
    }
    
    if(outerPID.PID_value > 0){
        innerMotor.Speed(speed - outerPID.PID_value);
        outerMotor.Speed(speed);
    }
    else if(outerPID.PID_value < 0){
        outerMotor.Speed(speed - innerPID.PID_value);
        innerMotor.Speed(speed);
    }


}


