#ifndef MAIN_H
#define MAIN_H

// different drivers
#define A_4988 0
#define DRV_8825 1
#define TMC_2208 2

// pin assignments
const int LED_PIN = 2;
const int MOTOR_STEP_PIN = 15;
const int MOTOR_DIRECTION_PIN = 13;

const int MS1 = 21;
const int MS2 = 22;
const int MS3 = 23;

void setMode(int mode);

#endif