#ifndef MPU_H
#define MPU_H

#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include <Wire.h>



class MPU
{
public:

    const int MPU_addr = 0x68; // I2C address of the MPU-6050
    float accelX, accelY, accelZ;
float gForceX, gForceY, gForceZ;
float angleX, angleY, angleZ;

float gyroX, gyroY, gyroZ;
float rotX, rotY, rotZ;

float rollA, pitchA, yawA, rollG, pitchG, yawG, roll, pitch, yaw;
    

    void init();
    void readAccel();
    void processAccelData();
    void processGyroData();
    void filterRawData();
    float lowPassFilter(float x, float alpha);
    void print();
    
    
    
            



};

#endif