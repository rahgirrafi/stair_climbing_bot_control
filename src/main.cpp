#include <Arduino.h>
#include <SoftPWM.h>
#include <Motor.h>
#include <Robot.h>
#include <MPU.h>

Robot robot;

void setup() {
  robot.init();

}

void loop() {

  robot.mpu.readAccel();
  
  
  robot.mpu.print();
  

  }

