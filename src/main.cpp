#include <Arduino.h>
#include <SoftPWM.h>
#include <Motor.h>
#include <Robot.h>
#include <MPU.h>

Robot robot;

void setup() {
  Serial.begin(9600);
  robot.init();

}

void loop() {
  
  robot.innerMPU.readAccel();
  robot.outerMPU.readAccel();
  // robot.innerMPU.print();
  robot.outerMPU.print();
  // robot.stair_climb(100);

//  Serial.println("Enter Command");

  robot.manualControl();
  
  }

