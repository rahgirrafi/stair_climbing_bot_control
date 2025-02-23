#include <Arduino.h>
#include <Motor.h>
#include <Robot.h>
#include <SoftPWM.h>

Robot::Robot(){

}

void Robot::init(){
    Wire.begin();
    innerMotor.init();
    outerMotor.init();
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
        innerMotor.forward();
        outerMotor.stop();
    }
   }

   else if(outerMPU.accelX>0.4){
    while (outerMPU.accelX>0.08)
    {
        innerMPU.readAccel();
        outerMPU.readAccel();
        innerMPU.print();
        outerMPU.print();
        outerMotor.forward();
        innerMotor.stop();
    }
   }

   else if(innerMPU.accelX<-0.4){
    while (innerMPU.accelX<-0.08)
    {
        innerMPU.readAccel();
        outerMPU.readAccel();
        innerMPU.print();
        outerMPU.print();
        innerMotor.backward();
        outerMotor.stop();
    }
   }

   else if(outerMPU.accelX<-0.4){
    while (outerMPU.accelX<-0.08)
    {
        innerMPU.readAccel();
        outerMPU.readAccel();
        innerMPU.print();
        outerMPU.print();
        outerMotor.backward();
        innerMotor.stop();
    }
   }
   else{
    innerMotor.forward();
    outerMotor.forward();
   }


        
    
}