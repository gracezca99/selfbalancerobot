#include "Wire.h"
#include <MPU6050_light.h>
#include <FastPID.h>


MPU6050 mpu(Wire);
unsigned long timer = 0;
int Hz = 10; // TODO: change dis
FastPID PID(1000, 0.05, 10, Hz, 16, true);  // TODO: change dis
int setpoint = 1043 * 0;
L298N leftMotor(3, 4, 5);
L298N rightMotor(9, 6, 7);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while (status != 0) {} // stop everything if could not connect to MPU6050
  
 // mpu.upsideDownMounting = true; // uncomment this line if the MPU6050 is mounted upside-down
 // Serial.println(F("Calculating offsets, do not move MPU6050"));
 // delay(1000);
 // mpu.calcOffsets(); // gyro and accelero
  mpu.setGyroOffsets(0.05, -2.03, 0.73); // TODO: change dis
  mpu.setAccOffsets(0.04, -0.02, -0.16); // TODO: change dis
  Serial.println("Done!\n");
}

void loop() {
  mpu.update();
  
  if ((millis() - timer) > Hz) { // print data every 10ms
    int16_t output = PID.step(setpoint, 1043 * mpu.getAngleY());
    int16_t left = output;
    int16_t right = output;
    if (left >= 0) {
      leftMotor.forward();
      leftMotor.setSpeed(left);
    } else {
      leftMotor.backward();
      leftMotor.setSpeed(-left);
    }
    if (right >= 0) {
      rightMotor.forward();
      rightMotor.setSpeed(right);
    } else {
      rightMotor.backward();
      rightMotor.setSpeed(-right);
    }
    timer += Hz;
  }
}
