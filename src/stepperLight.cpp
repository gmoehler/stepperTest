// simple high low signals with delay

#include <Arduino.h>
#include "main.h"

#define DIR MOTOR_DIRECTION_PIN
#define STEP MOTOR_STEP_PIN

int steps;
int stepDelay;

void setup_stepperlight()
{
  int mode = 8; // i.e. 1/8 microstepping
  setMode(mode);

  // number of rounds
  float numRounds = 2;

  // one round is 200 steps in single step mode
  steps = numRounds * 200 * mode;

  // time to turn in us
  int timeToTurn = 1000000;

  // delay (2 delays per cycle) in us
  stepDelay = timeToTurn / (2 * steps);
}

void turn(int numSteps, int delay)
{
  for (int step = 0; step < numSteps; step++)
  {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(delay);
    digitalWrite(STEP, LOW);
    delayMicroseconds(delay);
  }
}

void loop_stepperlight()
{
  Serial.print("looping\n");

  // clockwise
  digitalWrite(DIR, HIGH);
  turn(steps, stepDelay);
  delayMicroseconds(1000000);

  // anti-clockwise
  digitalWrite(DIR, LOW);
  turn(steps, stepDelay);
  delayMicroseconds(1000000);
}
