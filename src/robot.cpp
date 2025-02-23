#include <Arduino.h>
#include <Motor.h>
#include <Robot.h>
#include <SoftPWM.h>

#define FORWARD_TILTING_THRES 0.4
#define BACKWARD_TILTING_THRES -0.4
#define POSTIVE_HORIZONTAL_THRES 0.08
#define NEGATIVE_HORIZONTAL_THRES -0.08


Robot::Robot(){

}

void Robot::init(){
    Wire.begin();
    innerMotorLeft.init();
    innerMotorRight.init();
    outerMotorLeft.init();
    outerMotorRight.init();
    innerMPU.init();  
    outerMPU.init();
    
}




void Robot::stair_climb(int8_t speed){

   if(innerMPU.accelX>0.4){
    while (innerMPU.accelX>0.08)
    {
        innerMPU.readAccel();
        outerMPU.readAccel();
        innerMPU.print();
        outerMPU.print();
        innerMotorLeft.forward();
        innerMotorRight.forward();
        outerMotorLeft.stop();
        outerMotorRight.stop();
    }
   }

   else if(outerMPU.accelX>0.4){
    while (outerMPU.accelX>0.08)
    {
        innerMPU.readAccel();
        outerMPU.readAccel();
        innerMPU.print();
        outerMPU.print();
        outerMotorLeft.forward();
        outerMotorRight.forward();
        innerMotorLeft.stop();
        innerMotorRight.stop();
    }
   }

   else if(innerMPU.accelX<-0.4){
    while (innerMPU.accelX<-0.08)
    {
        innerMPU.readAccel();
        outerMPU.readAccel();
        innerMPU.print();
        outerMPU.print();
        outerMotorLeft.stop();
        outerMotorRight.stop();
        innerMotorLeft.backward();
        innerMotorRight.backward();
    }
   }

   else if(outerMPU.accelX<-0.4){
    while (outerMPU.accelX<-0.08)
    {
        innerMPU.readAccel();
        outerMPU.readAccel();
        innerMPU.print();
        outerMPU.print();
        outerMotorLeft.backward();
        outerMotorRight.backward();
        innerMotorLeft.stop();
        innerMotorRight.stop();
        
    }
   }
   else{
    innerMotorLeft.forward();
    innerMotorRight.forward();
    outerMotorLeft.forward();
    outerMotorRight.forward();
   }


        
    
}