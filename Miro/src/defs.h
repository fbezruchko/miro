#ifndef defs_h
#define defs_h

#define MIRO_PI (3.14159265)
#define MIRO_PI2ANG (57.2957795)

#define VOLTS (0)
#define SPEED (1)
#define BREAKDELAY (2)

#define LEFT 0
#define RIGHT 1

#define SEGMENT_ANGLE (360.0/WHEEL_SEGMENTS)
#define WHEEL_TIME_MIN (360000000 / (WHEEL_ANGLE_SPEED_MAX * WHEEL_SEGMENTS))
#define WHEEL_TIME_MAX (360000000 / (WHEEL_ANGLE_SPEED_MIN * WHEEL_SEGMENTS))
#define WHEEL_TIME(speed) (360000000.0 / ((speed) * WHEEL_SEGMENTS))

#define MEAN_DEPTH (2<<MEAN_DEPTH_POWER)

#endif