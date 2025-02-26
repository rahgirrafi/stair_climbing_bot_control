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
    leftMotor.init();
    rightMotor.init();
    innerMPU.init();  
    outerMPU.init();
    
    
}

void Robot::climb_up_inner(){
    outerMotorLeft.forward();
    outerMotorRight.forward();
    innerMotorLeft.backward();
    innerMotorRight.backward();
}

void Robot::climb_down_inner(){
    outerMotorLeft.backward();
    outerMotorRight.backward();
    innerMotorLeft.forward();
    innerMotorRight.forward();
}

void Robot::climb_up_outer(){
    outerMotorLeft.backward();
    outerMotorRight.backward();
    innerMotorLeft.forward();
    innerMotorRight.forward();
}

void Robot::climb_down_outer(){
    outerMotorLeft.forward();
    outerMotorRight.forward();
    innerMotorLeft.backward();
    innerMotorRight.backward();
}

void Robot::inner_up(){
    innerMotorLeft.forward();
    innerMotorRight.forward();
}

void Robot::inner_down(){
    innerMotorLeft.backward();
    innerMotorRight.backward();
}

void Robot::outer_up(){
    outerMotorLeft.forward();
    outerMotorRight.forward();
}

void Robot::outer_down(){
    outerMotorLeft.backward();
    outerMotorRight.backward();
}

void Robot::inner_stop(){
    innerMotorLeft.stop();
    innerMotorRight.stop();
}

void Robot::outer_stop(){
    outerMotorLeft.stop();
    outerMotorRight.stop();
}




void Robot::stair_climb_outer_first(){

   if(innerMPU.accelX>0.20){
    while (innerMPU.accelX>0.08)
    {
        innerMPU.readAccel();
        outerMPU.readAccel();
        innerMPU.print();
        outerMPU.print();
        outer_up();
        inner_stop();
    }
   }

   else if(outerMPU.accelY<-0.22){
    while (outerMPU.accelY<-0.08)
    {
        innerMPU.readAccel();
        outerMPU.readAccel();
        innerMPU.print();
        outerMPU.print();
        inner_stop();
        outer_down();
    }
   }

   else if(innerMPU.accelX<-0.20){
    while (innerMPU.accelX<-0.08)
    {
        innerMPU.readAccel();
        outerMPU.readAccel();
        innerMPU.print();
        outerMPU.print();
        outer_stop();
        inner_down();
    }
   }

   else if(outerMPU.accelY>0.20){
    while (outerMPU.accelY>0.08)
    {
        innerMPU.readAccel();
        outerMPU.readAccel();
        innerMPU.print();
        outerMPU.print();
        outer_down();
        inner_stop();
        
    }
   }
   else{
        climb_up_outer();
   
    }
}

void Robot::stair_climb_inner_first(){
    if(innerMPU.accelX>0.25){
        while (innerMPU.accelX>0.08)
        {
            innerMPU.readAccel();
            outerMPU.readAccel();
            innerMPU.print();
            outerMPU.print();
            outer_up();
            inner_stop();
        }
       }
    
       else if(outerMPU.accelY<-0.22){
        while (outerMPU.accelY<-0.08)
        {
            #define OUTER_LEFT_UP 'q'
            #define OUTER_LEFT_DOWN 'z'
            #define OUTER_RIGHT_UP 'e'
            #define OUTER_RIGHT
            innerMPU.readAccel();
            outerMPU.readAccel();
            innerMPU.print();
            outerMPU.print();
            inner_down();
            outer_stop();
        }
       }
    
       else if(innerMPU.accelX<-0.15){
        while (innerMPU.accelX<-0.08)
        {
            innerMPU.readAccel();
            outerMPU.readAccel();
            innerMPU.print();
            outerMPU.print();
            outer_stop();
            inner_down();
        }
       }
    
       else if(outerMPU.accelY>0.20){
        while (outerMPU.accelY>0.08)
        {
            innerMPU.readAccel();
            outerMPU.readAccel();
            innerMPU.print();
            outerMPU.print();
            outer_up();
            inner_stop();
            
        }
       }
       else{
            climb_up_inner();
       
        }
}

void Robot::robot_forward(){
    leftMotor.forward();
    rightMotor.forward();
}

void Robot::robot_backward(){
    leftMotor.backward();
    rightMotor.backward();
}

void Robot::robot_left(){
    leftMotor.backward();
    rightMotor.forward();
}

void Robot::robot_right(){
    leftMotor.forward();
    rightMotor.backward();
}



char Robot::getCommand(){
    if(Serial.available()){
        char a = Serial.read();
        
        return a;
    }  
}


void Robot::manualControl(){
    controlCommand = getCommand();
    // innerMPU.readAccel();
    // outerMPU.readAccel();
    // innerMPU.print();
    // outerMPU.print();
    // Serial.println(controlCommand);
    switch (controlCommand)
    {

    //profile 1
    case FORWARD:
        Serial.println("Forward");
        // innerMotorLeft.backward();
        robot_forward();
        break;
    case RIGHT:
        Serial.println("Right");
        // innerMotorLeft.forward();
        robot_right();
        break;
    case LEFT:
        Serial.println("Left");
        // innerMotorRight.forward();
        robot_left();
        break;
    case BACKWARD:
        Serial.println("Backward");
        // innerMotorRight.backward();
        robot_backward();
        break;
    
    case INNERBOTH_UP:
        innerMotorLeft.forward();
        innerMotorRight.forward();
        break;
    case INNERBOTH_DOWN:
        innerMotorLeft.backward();
        innerMotorRight.backward();
        break;
    case OUTERBOTH_UP:
        outerMotorLeft.forward();
        outerMotorRight.forward();
        break;
    case OUTERBOTH_DOWN:
        outerMotorLeft.backward();
        outerMotorRight.backward();
        break;

    case CLIMB_UP_ARM_FIRST:
        climb_up_outer();
        break;
    case CLIMB_DOWN_ARM_FIRST:
        climb_down_outer();
        break;
    case CLIMB_UP_BODY_FIRST:
        climb_up_inner();
        break;
    case CLIMB_DOWN_BODY_FIRST:
        climb_down_inner();
        break;

    //profile 2
    
    case AUTO_CLIMB_UP_ARM_FIRST:
        stair_climb_outer_first();
        break;
    case AUTO_CLIMB_UP_BODY_FIRST:
        stair_climb_inner_first();
        break;

    case STOP:
        innerMotorLeft.stop();
        innerMotorRight.stop();
        outerMotorLeft.stop();
        outerMotorRight.stop();
        break;

    //profile 3
    case OUTER_LEFT_UP:
        // Serial.println("Triangle");
        outerMotorLeft.forward();
        break;
    case OUTER_LEFT_DOWN:
        // Serial.println("Circle");
        outerMotorLeft.backward();
        break;        
    case OUTER_RIGHT_DOWN:
    // Serial.println("Square");
        outerMotorRight.backward();
        break;
    case OUTER_RIGHT_UP:
        // Serial.println("Cross");
        outerMotorRight.forward();
        break;
    case INNER_LEFT_UP:
        // Serial.println("L1");
        innerMotorLeft.forward();
        break;
    case INNER_LEFT_DOWN:
        // Serial.println("L2");
        innerMotorLeft.backward();
        break;
    case INNER_RIGHT_UP:
        // Serial.println("R1");
        innerMotorRight.forward();
        break;
    case INNER_RIGHT_DOWN:
        // Serial.println("R2");
        innerMotorRight.backward();
        break;
    default:
        innerMotorLeft.stop();
        innerMotorRight.stop();
        outerMotorLeft.stop();
        outerMotorRight.stop();
        leftMotor.stop();
        rightMotor.stop();

        // Serial.println("Stop");
        break;
    }

}