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

const int MOTOR_STEP_PIN2 = 14;
const int MOTOR_DIRECTION_PIN2 = 12;

const int MOTOR_STEP_PIN3 = 16;
const int MOTOR_DIRECTION_PIN3 = 17;

const int MOTOR_STEP_PIN4 = 18;
const int MOTOR_DIRECTION_PIN4 = 19;

const int MS1 = 21;
const int MS2 = 22;
const int MS3 = 23;

void setMode(int mode);

#endif