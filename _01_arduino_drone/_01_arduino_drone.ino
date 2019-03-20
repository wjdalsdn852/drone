#include "_00_drone.h"


mpu6050_t mpu6050 = {
  .i2c_addr = 0x68,
  .PWR_MGMT_1 = 0x6b,
  .GYRO_XOUT_H = 0x43,
  };
gyro_raw_t gyro_raw;
gyro_offset_t gyro_offset;
gyro_adj_t gyro_adj;
gyro_rate_t gyro_rate;
dt_t dt;
gyro_angle_t gyro_angle;
target_angle_t target_angle;
balancing_force_t balancing_force;
throttle_t throttle;
motor_speed_t motor_speed;
remote_t remote;
motor_t motor;

void setup() {
  Serial.begin(115200);
  init(mpu6050);
  get(mpu6050, gyro_offset);
  init(dt);
  init(remote);
  init(motor);
}

void loop() {
  read(mpu6050, gyro_raw);
  calc(gyro_adj, gyro_raw, gyro_offset);
  calc(gyro_rate, gyro_adj);
  calc(dt);
  calc(gyro_angle, gyro_rate, dt);
  calc(balancing_force, target_angle, gyro_angle);
  add(balancing_force, gyro_rate);
  add(balancing_force, target_angle, gyro_angle, dt);
  distribute(motor_speed, throttle, balancing_force);
  check(remote, throttle, target_angle);
  update(motor, motor_speed);

  static int cnt_loop;
  cnt_loop++;
  if(cnt_loop%50 != 0) return;
  
 // print(gyro_raw);//
  print(gyro_offset);
  print(gyro_adj);
  print(gyro_rate);
  print(dt);
  print(gyro_angle);
  print(balancing_force);
  print(motor_speed);
  println();
}
