#include <Arduino.h>
#include <Motor.h>
#include <SoftPWM.h>



//This code is for BTS7960 motor driver

Motor::Motor(uint8_t IN1, uint8_t IN2)
{
//    this->EN = EN;
   this->IN1 = IN1;
   this->IN2 = IN2;
}

void Motor::init()
{
    
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    // SoftPWMBegin();
    // SoftPWMSet(IN1, 0);
    // SoftPWMSet(IN2,0);
    // SoftPWMSetFadeTime(IN1,100,500);
    // SoftPWMSetFadeTime(IN2,100,500);
}



void Motor::Speed(int speed) {
//if speed > 0 then motor will rotate in forward direction
//if speed < 0 then motor will rotate in reverse direction

if(speed >= 0){

    // SoftPWMSetPercent(IN1, speed);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    
}
else{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    // SoftPWMSetPercent(IN2, -speed);
}

}
    
// 
// void Motor::setSpeed(uint8_t speed) {
    // this->speed = speed;
// }
// 
// uint8_t Motor::getSpeed() {
    // return speed;
// }

