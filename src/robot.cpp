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




void Robot::stair_climb(int8_t speed){

    outerMPU.accelX = 0.05;
    outerMPU.accelZ = 1.5;
    if (innerMPU.accelX>0.40 && innerMPU.accelZ<1.07 && outerMPU.accelX<0.08 && outerMPU.accelZ>1.11){   
        innerMove = true;
        outerMove = false;
        // Serial.println("Inner Move");
    }

    else if(innerMPU.accelX<0.08 && innerMPU.accelZ>1.11 && outerMPU.accelX>0.40 && outerMPU.accelZ<1.07){
        innerMove = false;
        outerMove = true;
    }

    
    if(innerMove){
        
    if(innerMPU.accelX>0.40 && innerMPU.accelZ<1.07){
        innerMotor.stop();
        outerMotor.forward();
    }

    if(innerMPU.accelX<0.08  && innerMPU.accelZ>1.11){
        innerMotor.forward();
        outerMotor.forward();
    }

    }

    if(outerMove){
    if(outerMPU.accelX>0.40){
        innerMotor.stop();
        outerMotor.forward();
    }

    if(outerMPU.accelX<0.08){
        innerMotor.forward();
        outerMotor.forward();
    }
}
}