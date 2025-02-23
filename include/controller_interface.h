#ifndef CONTROLLER_INTERFACE_H
#define CONTROLLER_INTERFACE_H

#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'
#define CIRCLE 'C'
#define CROSS 'X'
#define TRIANGLE 'T'
#define SQUARE 'S'
#define START 'A'
#define PAUSE 'P'

#include <Arduino.h>

class ControllerInterface{
    public:
        ControllerInterface();
        void init();
        char getCommand();
};



#endif