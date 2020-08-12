
#include <SpeedyStepper.h>
#include "main.h"

// create the stepper motor object
SpeedyStepper speedystepper;

void setup_speedy()
{
  // connect and configure the stepper motor to its IO pins
  speedystepper.connectToPins(MOTOR_STEP_PIN, MOTOR_DIRECTION_PIN);
}

void varyMicrosteps(int baseSpeed)
{
  int nModes = 4;
  // int modes[] = {1, 2, 4, 8, 16, 32};
  //int modes[] = {1, 8, 32};
  int modes[] = {2, 4, 8, 16};

  Serial.printf("Run at: %d\n", baseSpeed);
  for (int i = 0; i < nModes; i++)
  {
    int mode = modes[i];
    Serial.printf("%d ", mode);
    setMode(mode);
    int steps = baseSpeed * mode;

    speedystepper.setSpeedInStepsPerSecond(steps);
    speedystepper.setAccelerationInStepsPerSecondPerSecond(steps);
    speedystepper.moveRelativeInSteps(steps * 3);
  }
  Serial.println("");
}

void justRun(int speed, int mode)
{
  setMode(mode);
  int steps = speed * mode;
  Serial.printf("speed: %d, mode: %d, steps/s: %d\n", speed, mode, steps);

  speedystepper.setSpeedInStepsPerSecond(steps);
  speedystepper.setAccelerationInStepsPerSecondPerSecond(steps * 100);
  speedystepper.moveRelativeInSteps(steps * 3);
  delay(200);
}

void speedUp(int speedFrom, int speedTo, int mode)
{
  int step = (speedTo - speedFrom) / 3;
  for (int speed = speedFrom; speed <= speedTo; speed += step)
  {
    justRun(speed, mode);
  }
}

void loop_speedy()
{
  Serial.print("looping\n");
  //
  // Note 1: It is assumed that you are using a stepper motor with a
  // 1.8 degree step angle (which is 200 steps/revolution). This is the
  // most common type of stepper.
  //
  // Note 2: It is also assumed that your stepper driver board is
  // configured for 1x microstepping.
  //
  // It is OK if these assumptions are not correct, your motor will just
  // turn less than a full rotation when commanded to.
  //
  // Note 3: This example uses "relative" motions.  This means that each
  // command will move the number of steps given, starting from it's
  // current position.
  //
  int mode = 8; // 1/8 microstepping
  setMode(mode);
  //
  // set the speed and acceleration rates for the stepper motor
  //
  int speed = 2 * 200; // 2 rounds
  speedystepper.setSpeedInStepsPerSecond(speed * mode);
  speedystepper.setAccelerationInStepsPerSecondPerSecond(1 * speed * mode);

  //
  // Rotate the motor in the forward direction one revolution (200 steps).
  // This function call will not return until the motion is complete.
  //
  speedystepper.moveRelativeInSteps(mode * speed * 2);

  //
  // now that the rotation has finished, delay 1 second before starting
  // the next move
  //
  delay(500);

  //
  // rotate backward 1 rotation, then wait 1 second
  //
  speedystepper.moveRelativeInSteps(-mode * speed * 2);
  delay(500);

  //
  // This time speedup the motor, turning 10 revolutions.  Note if you
  // tell a stepper motor to go faster than it can, it just stops.
  //

  /* varyMicrosteps(10);
  varyMicrosteps(30);
  varyMicrosteps(100);
  varyMicrosteps(200);
  varyMicrosteps(300); */
  //varyMicrosteps(600);
  //varyMicrosteps(800);

  /*justRun(50, 16);
  justRun(100, 16);
  justRun(150, 16);
  justRun(200, 16);

  justRun(100, 8);
  justRun(200, 8);
  justRun(250, 8);
  justRun(300, 8);
  justRun(400, 8);

  justRun(200, 4);
  justRun(250, 4);
  justRun(300, 4);
  justRun(500, 4);

  justRun(200, 2);
  justRun(250, 2);
  justRun(300, 2);
  justRun(1000, 2);

  justRun(50, 1);
  justRun(300, 1);
  justRun(600, 1);
  justRun(900, 1);
  justRun(1200, 1);
  justRun(1500, 1);
  justRun(3000, 1);*/
  /*justRun(5000, 1);
  justRun(8000, 1);
  justRun(12000, 1);
  justRun(20000, 1);
  justRun(30000, 1);*/

  // TMC2008 max speeds (6-7U)
  /*justRun(105, 16);
  justRun(420, 8);
  justRun(420, 4);
  justRun(1650, 2);
  justRun(3300, 1);
  delay(1000);*/
}