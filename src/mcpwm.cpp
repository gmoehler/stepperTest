#include <stdio.h>
#include "esp_attr.h"
#include "driver/mcpwm.h"
#include <Arduino.h>

#include "main.h"

esp_err_t ret;

void setup_mcpwm()
{
  int mode = 8;
  setMode(mode);

  // Connect the A output to a pin.
  ret = mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0A, MOTOR_STEP_PIN);
  ESP_ERROR_CHECK(ret);

  mcpwm_config_t pwmConfig = {};

  // time per round in sec
  int timePerRound = 1;

  // Default frequency in Hertz.
  pwmConfig.frequency = 400 * mode * timePerRound;
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

void loop_mcpwm()
{
}