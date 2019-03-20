#ifndef _00_DRONE_H__
#define _00_DRONE_H__


typedef struct { int i2c_addr, PWR_MGMT_1, GYRO_XOUT_H; } mpu6050_t;
typedef struct { int16_t x, y, z; } gyro_raw_t;
typedef struct { int16_t x, y, z; } gyro_offset_t;
typedef struct { int dummy; } gyro_adj_t;
typedef struct { int dummy; } gyro_rate_t;
typedef struct { int dummy; } dt_t;
typedef struct { int dummy; } gyro_angle_t;
typedef struct { int dummy; } target_angle_t;
typedef struct { int dummy; } balancing_force_t;
typedef struct { int dummy; } throttle_t;
typedef struct { int dummy; } motor_speed_t;
typedef struct { int dummy; } remote_t;
typedef struct { int dummy; } motor_t;

#endif
