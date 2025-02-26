#include <Arduino.h>
#include <controller_interface.h>





ControllerInterface::ControllerInterface(){
    
}

void ControllerInterface::init(){
    
}

char ControllerInterface::getCommand(){
    if(Serial.available()){
        char a = Serial.read();
        
        return a;
    }  
}


