#ifndef CONTROLLER_INTERFACE_H
#define CONTROLLER_INTERFACE_H
#include <SoftwareSerial.h>



#define INNER_LEFT FORWARD


#include <Arduino.h>

class ControllerInterface{
    public:
        ControllerInterface();
        void init();
        char getCommand();
        
};



#endif