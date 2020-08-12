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

void setModeOutput(int ms1, int ms2, int ms3 = 0)
{
  digitalWrite(MS1, ms1);
  digitalWrite(MS2, ms2);
  digitalWrite(MS3, ms3);
}

void setMode(int mode)
{

  if (driver == TMC_2208)
  {
    Serial.printf("TMC2208: 1/%d\n", mode);
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
    Serial.printf("DRV8825: 1/%d\n", mode);
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
  else
  {
    Serial.printf("No driver selected: 1/%d\n", mode);
  }
}

void setup()
{
  // some general setup
  pinMode(LED_PIN, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(MS3, OUTPUT);

  pinMode(MOTOR_STEP_PIN, OUTPUT);
  digitalWrite(MOTOR_STEP_PIN, LOW);

  pinMode(MOTOR_DIRECTION_PIN, OUTPUT);
  digitalWrite(MOTOR_DIRECTION_PIN, LOW);

  Serial.begin(115200);
  Serial.print("starting\n");

  // lib specific startup

  // setup_stepperlight();
  setup_basicstepper();
  // setup_speedy();
  setup_mcpwm();
}

void loop()
{
  // loop_stepperlight();
  loop_basicstepper();
  //loop_speedy();
  // loop_mcpwm();
}