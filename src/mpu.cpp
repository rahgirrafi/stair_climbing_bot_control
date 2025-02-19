#include <Arduino.h>
#include <MPU.h>

void MPU::init(){
    Wire.beginTransmission(0b1101000); //This is the I2C address of the MPU (b1101000/b1101001 for AC0 low/high datasheet sec. 9.2)
    Wire.write(0x6B); //Accessing the register 6B - Power Management (Sec. 4.28)
    Wire.write(0b00000000); //Setting SLEEP register to 0. (Required; see Note on p. 9)
    Wire.endTransmission();  
  Wire.beginTransmission(0b1101000); //I2C address of the MPU
  Wire.write(0x1B); //Accessing the register 1B - Gyroscope Configuration (Sec. 4.4) 
  Wire.write(0x00000000); //Setting the gyro to full scale +/- 250deg./s 
  Wire.endTransmission(); 
  Wire.beginTransmission(0b1101000); //I2C address of the MPU
  Wire.write(0x1C); //Accessing the register 1C - Acccelerometer Configuration (Sec. 4.5) 
  Wire.write(0b00000000); //Setting the accel to +/- 2g
  Wire.endTransmission(); 
  Serial.begin(9600);
    
   
}

void MPU::readAccel(){
    Wire.beginTransmission(0b1101000); //I2C address of the MPU
    Wire.write(0x3B); //Starting register for Accel Readings
    Wire.endTransmission();
  Wire.requestFrom(0b1101000,6); //Request Accel Registers (3B - 40)
  while(Wire.available() < 6);
  accelX = Wire.read()<<8|Wire.read(); //Store first two bytes into accelX
  accelY = Wire.read()<<8|Wire.read(); //Store middle two bytes into accelY
  accelZ = Wire.read()<<8|Wire.read(); //Store last two bytes into accelZ
  processAccelData();
//   mapToAngle();
}


void MPU:: processAccelData(){
    accelX= accelX / 16384;
    accelY = accelY / 16384; 
    accelZ = accelZ / 16384;

    // rollA = atan2(gForceY, gForceZ) * 180 / PI;
    // pitchA = atan2(-gForceX, sqrt(gForceY * gForceY + gForceZ * gForceZ)) * 180 / PI;
    // yawA = atan2(gForceZ, gForceX) * 180 / PI;
  }
  


float MPU::lowPassFilter(float x, float alpha){
    return alpha * x + (1 - alpha) * x;
  }

  void MPU::filterRawData() {
    float alpha = 0.96;
    accelX = lowPassFilter(accelX, alpha);
    accelY = lowPassFilter(accelY, alpha);
    accelZ = lowPassFilter(accelZ, alpha);
    gyroX = lowPassFilter(gyroX, alpha);
    gyroY = lowPassFilter(gyroY, alpha);
    gyroZ = lowPassFilter(gyroZ, alpha);
  }

  void MPU::print() {
        // Serial.print( "angleX = " + String(angleX) + '\t' + "angleY = " + String(angleY) + '\t' + "angleZ = " + String(angleZ) + '\n'); 
        // Serial.print( "roll = " + String(roll) + '\t' + "pitch = " + String(pitch) + '\t' + "yaw = " + String(yaw) + '\n');
        Serial.print( "accelX = " + String(accelX) + '\t' + "accelY = " + String(accelY) + '\t' + "accelZ = " + String(accelZ) + '\t' + "gyroX = " + String(gyroX) + '\t' + "gyroY = " + String(gyroY) + '\t' + "gyroZ = " + String(gyroZ) + '\n');
    }



