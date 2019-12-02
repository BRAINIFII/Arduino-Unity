#include<Wire.h>
const int MPU2=0x69,MPU1=0x68;
int16_t AcX1,AcY1,AcZ1,Tmp1,GyX1,GyY1,GyZ1;
int16_t AcX2,AcY2,AcZ2,Tmp2,GyX2,GyY2,GyZ2;
int data;
 
//-------------------------------------------------\setup loop\------------------------------------------------------------ 
 void setup(){ 
      Wire.begin(); 
      Wire.beginTransmission(MPU1);
      Wire.write(0x6B);// PWR_MGMT_1 register 
      Wire.write(0); // set to zero (wakes up the MPU-6050)
      Wire.endTransmission(true);Wire.begin(); 
      Wire.beginTransmission(MPU2);
      Wire.write(0x6B);// PWR_MGMT_1 register 
      Wire.write(0); // set to zero (wakes up the MPU-6050)
      Wire.endTransmission(true);
      Serial.begin(115200); 
     } 
     
//---------------------------------------------------\void loop\------------------------------------------------------------
 void loop(){
   
      //get values for first mpu having address of 0x68   
      GetMpuValue1(MPU1);
      //get values for second mpu having address of 0x69
      GetMpuValue2(MPU2);
      //print data to unity
      sentunity();
     

    }
 
//----------------------------------------------\user defined functions\-------------------------------------------------- 
      
 
 void GetMpuValue1(const int MPU){ 
   
      Wire.beginTransmission(MPU); 
      Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H) 
      Wire.endTransmission(false);
      Wire.requestFrom(MPU, 14, true); // request a total of 14 registers 
      AcX1=Wire.read()<<8| Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L) 
      AcY1=Wire.read()<<8|  Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
      AcZ1=Wire.read()<<8| Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L) 
      Tmp1=Wire.read()<<8| Wire.read(); // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L) 
      GyX1=Wire.read()<<8| Wire.read(); // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L) 
      GyY1=Wire.read()<<8| Wire.read(); // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L) 
      GyZ1=Wire.read()<<8| Wire.read(); // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L) 
     }
     
     
 void GetMpuValue2(const int MPU){ 
   
      Wire.beginTransmission(MPU); 
      Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H) 
      Wire.endTransmission(false);
      Wire.requestFrom(MPU, 14, true); // request a total of 14 registers 
      AcX2=Wire.read()<<8| Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L) 
      AcY2=Wire.read()<<8|  Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
      AcZ2=Wire.read()<<8| Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L) 
      Tmp2=Wire.read()<<8| Wire.read(); // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L) 
      GyX2=Wire.read()<<8| Wire.read(); // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L) 
      GyY2=Wire.read()<<8| Wire.read(); // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L) 
      GyZ2=Wire.read()<<8| Wire.read(); // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L) 
     }
     
     void sentunity (){
        if ( Serial.available())
          {  data = Serial.read();
             if (data == 'a'){
                 //AcX1 = map(AcX1 ,-17000,17000, 0,180);
                 Serial.println(AcX1);
                }
             if (data == 'b'){
                //AcY1 = map(AcY1 ,-17000,17000, 0,180);
                Serial.println(AcY1);
                }
             if (data == 'c'){
                //AcZ1 = map(AcZ1 ,0,5000, 0,180);
                 Serial.println(AcZ1);
                }
             if (data == 'd'){
                 //GyX1 = map(GyX1 ,-17000,17000, 0 ,180);
                 Serial.println(GyX1);
                }
              if (data == 'e'){
                  //GyY1 = map(GyY1 ,-17000,17000, 0 ,180);
                  Serial.println(GyY1);
                 }
              if (data == 'f') {
                  //GyZ1 = map(GyZ1 ,-17000,17000, 0 ,180);
                  Serial.println(GyZ1);
                  }
              if (data == 'g'){
                  //AcX2 = map(AcX2 ,-17000,17000, 0,180);
                  Serial.println(AcX2);
                 }
              if (data == 'h'){
                //AcY2 = map(AcY2 ,-17000,17000, 0,180);
                Serial.println(AcY2);
                }
              if (data == 'i'){
                //AcZ2 = map(AcZ2,-17000,17000, 0,180);
                Serial.println(AcZ2);      
                }
              if (data == 'j'){ 
                  //GyX2 = map(GyX2 ,-17000,17000, 0 ,180);
                  Serial.println(GyX2);
                  }
              if (data == 'k') {
                  //GyY2 = map(GyY2 ,-17000,17000, 0 ,180); 
                  Serial.println(GyY2);
                 }
              if (data == 'l'){
                  //GyZ2 = map(GyZ2 ,-17000,17000, 0 ,180); 
                  Serial.println(GyZ2);
                 }
          }
     }

