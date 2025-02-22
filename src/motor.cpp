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
}



void Motor::forward(){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    Serial.println("Forward");
}

void Motor::backward(){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2,HIGH);
    Serial.println("Backward");
}

void Motor::stop(){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    Serial.println("Stop");
}