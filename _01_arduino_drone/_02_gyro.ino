#include "_00_drone.h"
#include <Wire.h>
#define NSAMPLES 1000

void init(mpu6050_t&) {

  Wire.begin();
  Wire.beginTransmission(mpu6050. i2c_addr);
  Wire.write(mpu6050.PWR_MGMT_1);
  Wire.write(0);
  Wire.endTransmission(true);
}
void read(mpu6050_t&, gyro_raw_t&) {

  Wire.beginTransmission(mpu6050.i2c_addr);
  Wire.write(mpu6050.GYRO_XOUT_H);
  Wire.endTransmission(false);
  Wire.requestFrom(mpu6050.i2c_addr, 6, true);
  gyro_raw.x = Wire.read() << 8 | Wire.read();
  gyro_raw.y = Wire.read() << 8 | Wire.read();
  gyro_raw.z = Wire.read() << 8 | Wire.read();
}

void get(mpu6050_t& mpu6050, gyro_offset_t& gyro_offset) {

  gyro_raw_t gyro_raw = {0,};
  int32_t sumGyX = 0, sumGyY = 0, sumGyZ = 0;

  for (int i = 0; i < NSAMPLES; i++) {
    read(mpu6050, gyro_raw);

    sumGyX += gyro_raw.x;
    sumGyY += gyro_raw.y;
    sumGyZ += gyro_raw.z;
    delay(10);
  }

  gyro_offset.x = (double)sumGyX / NSAMPLES;
  gyro_offset.y = (double)sumGyY / NSAMPLES;
  gyro_offset.z = (double)sumGyZ / NSAMPLES;
}
void calc(gyro_adj_t&, gyro_raw_t&, gyro_offset_t&) {}
void calc(gyro_rate_t&, gyro_adj_t&) {}
void init(dt_t&) {}
void calc(dt_t&) {}
void calc(gyro_angle_t&, gyro_rate_t&, dt_t&) {}
