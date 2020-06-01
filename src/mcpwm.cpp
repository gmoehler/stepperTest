#include <stdio.h>
#include "esp_attr.h"
#include "driver/mcpwm.h"
#include <Arduino.h>

#include "main.h"

esp_err_t ret;

void setup_mcpwm()
{
  // setup the LED pin and enable print statements
  pinMode(LED_PIN, OUTPUT);
  pinMode(M0, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  Serial.begin(115200);
  Serial.print("starting\n");

  setMode(16);
}

void loop_mcpwm()
{
  // Connect the A output to a pin.
  ret = mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0A, MOTOR_STEP_PIN);
  ESP_ERROR_CHECK(ret);

  mcpwm_config_t pwmConfig = {};
  // Default frequency in Hertz.
  pwmConfig.frequency = 100;
  // Duty cycle of both outputs.
  pwmConfig.cmpr_a = 10.0f;
  pwmConfig.cmpr_b = 90.0f;
  // The counter counts up, and then resets to 0.
  pwmConfig.counter_mode = MCPWM_UP_COUNTER;
  // This enables the output.
  pwmConfig.duty_mode = MCPWM_DUTY_MODE_0;

  ret = mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_0, &pwmConfig);
  ESP_ERROR_CHECK(ret);
}