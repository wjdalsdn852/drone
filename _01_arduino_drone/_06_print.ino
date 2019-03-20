#include "_00_drone.h"


void print(gyro_raw_t&) {

    Serial.print(" #RAW:GyX = ");
    Serial.print(gyro_raw.x); 
    Serial.print(" | GyY = ");
    Serial.print(gyro_raw.y);
    Serial.print(" | GyZ = ");
    Serial.print(gyro_raw.z);
  }
void println(void) {
  
  Serial.println();
  }
void print(gyro_offset_t& gyro_offset) {
  
    Serial.print(" #OFF:GyX = ");
    Serial.print(gyro_offset.x); 
    Serial.print(" | GyY = ");
    Serial.print(gyro_offset.y);
    Serial.print(" | GyZ = ");
    Serial.print(gyro_offset.z);
    }
void print(gyro_adj_t&) {}
void print(dt_t&) {}
void print(gyro_rate_t&) {}
void print(gyro_angle_t&) {}
void print(balancing_force_t&) {}
void print(motor_speed_t&) {}
