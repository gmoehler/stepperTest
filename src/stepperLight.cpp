// simple high low signals with delay

#include <Arduino.h>
#include "main.h"

#define DIR MOTOR_DIRECTION_PIN
#define STEP MOTOR_STEP_PIN

int stepCounter;
int steps = 1000;
int stepDelay = 1000000 / 300; // in us

void setup_stepperlight()
{
  setMode(16);
  pinMode(STEP, OUTPUT); // Step
  pinMode(DIR, OUTPUT);  // Richtung
}

void loop_stepperlight()
{
  digitalWrite(DIR, HIGH);
  for (stepCounter = 0; stepCounter < steps; stepCounter++)
  {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(STEP, LOW);
    delayMicroseconds(stepDelay);
  }
  delayMicroseconds(1);

  digitalWrite(DIR, LOW); // gegen den Uhrzeigersinn

  for (stepCounter = 0; stepCounter < steps; stepCounter++)
  {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(STEP, LOW);
    delayMicroseconds(stepDelay);
  }
  delayMicroseconds(2 * stepDelay);
  delayMicroseconds(stepDelay);
}
