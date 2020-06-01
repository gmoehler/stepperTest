#include <Arduino.h>
#include "main.h"

int driver = TMC_2208;

// simple high low signals with delay
void setup_stepperlight();
void loop_stepperlight();
// basicstepper library
void setup_basicstepper();
void loop_basicstepper();
// SpeedyStepper lib
void setup_speedy();
void loop_speedy();
// using esp32 MC-PWM
void setup_mcpwm();
void loop_mcpwm();

void setModeOutput(int m0, int m1, int m2 = 0)
{
  digitalWrite(M0, m0);
  digitalWrite(M1, m1);
  digitalWrite(M2, m2);
}

void setMode(int mode)
{
  if (driver == TMC_2208)
  {
    switch (mode)
    {
    case 2:
      setModeOutput(1, 0);
      break;
    case 4:
      setModeOutput(0, 1);
      break;
    case 8:
      setModeOutput(0, 0);
      break;
    case 16:
      setModeOutput(1, 1);
      break;
    }
  }
  else if (driver == DRV_8825)
  {
    switch (mode)
    {
    case 1:
      setModeOutput(0, 0, 0);
      break;
    case 2:
      setModeOutput(1, 0, 0);
      break;
    case 4:
      setModeOutput(0, 1, 0);
      break;
    case 8:
      setModeOutput(1, 1, 0);
      break;
    case 16:
      setModeOutput(0, 0, 1);
      break;
    case 32:
      setModeOutput(1, 1, 1);
      break;
    }
  }
}

void setup()
{
  setup_stepperlight();
  // setup_basicstepper();
  //setup_speedy();
  //setup_mcpwm();
}

void loop()
{
  loop_stepperlight();
  //loop_basicstepper();
  //loop_speedy();
  // loop_mcpwm();
}