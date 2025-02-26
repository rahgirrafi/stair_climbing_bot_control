#ifndef ROBOT_H
#define ROBOT_H
#include <Arduino.h>
#include <Motor.h>
#include <MPU.h>

//profile 1
#define FORWARD 'w'
#define BACKWARD 's'
#define LEFT 'a'
#define RIGHT 'd'

#define INNERBOTH_UP 'y'
#define INNERBOTH_DOWN 'b'
#define OUTERBOTH_UP 'x'
#define OUTERBOTH_DOWN 'v'

#define CLIMB_UP_ARM_FIRST 'l'
#define CLIMB_DOWN_ARM_FIRST 'o'
#define CLIMB_UP_BODY_FIRST 'p'
#define CLIMB_DOWN_BODY_FIRST 'k'

//profile 2
#define AUTO_CLIMB_UP_ARM_FIRST 'Y'
#define AUTO_CLIMB_UP_BODY_FIRST 'X'

#define STOP 'Z'  

//profile 3: Individual Arm-body control

#define OUTER_LEFT_UP 'q'
#define OUTER_LEFT_DOWN 'z'
#define OUTER_RIGHT_UP 'e'
#define OUTER_RIGHT_DOWN 'c'

#define INNER_LEFT_UP 'u'
#define INNER_LEFT_DOWN 'j'
#define INNER_RIGHT_UP 'i'
#define INNER_RIGHT_DOWN 'h'

#define CLIMB_TYPE_ARM_FIRST 1
#define CLIMB_TYPE_BODY_FIRST 2
#define TX 2
#define RX 3

class Robot{
    public:

    uint8_t climb_type = CLIMB_DOWN_BODY_FIRST;
    Motor innerMotorLeft = Motor(5, 8);
    Motor innerMotorRight = Motor(6, 9);
    Motor outerMotorLeft = Motor(10, 11);
    Motor outerMotorRight = Motor(13, 12);

    Motor leftMotor = Motor(4, 2);
    Motor rightMotor = Motor(3, 7);
    
    
    
    MPU innerMPU = MPU(0x68, "Inner MPU");
    MPU outerMPU = MPU(0x69, "Outer MPU");



    bool innerMove = false;
    bool outerMove = false;
    
    char controlCommand;

    Robot();
    void init();
    void move();
    char getCommand();
    
    void stair_climb_outer_first();
    void stair_climb_inner_first();

    void climb_up_inner();
    void climb_down_inner();
    void climb_up_outer();
    void climb_down_outer();

    void inner_up();
    void inner_down();
    void outer_up();
    void outer_down();

    void inner_stop();
    void outer_stop();

    void manualControl();

    void robot_forward();
    void robot_backward();
    void robot_left();
    void robot_right();

    void stop();
    
};
#endif