#include <Arduino.h>
#include "constants.h"
#include "settings.h"
#include "commands.h"
#include "storage.h"
#include "hex_display.h"
#include "serial_console.h"

bool ansi_enabled = DEFAULT_ANSI;
bool turbo_enabled = DEFAULT_TURBO;
bool boot_enabled = DEFAULT_BOOT;
uint8_t display_type = DEFAULT_DISPLAY_TYPE;

unsigned long last_activity = 0;
char str_lo[4] = {DEFAULT_LO_0, DEFAULT_LO_1, DEFAULT_LO_2, DEFAULT_LO_3};
char str_hi[4] = {DEFAULT_HI_0, DEFAULT_HI_1, DEFAULT_HI_2, DEFAULT_HI_3};
char str_boot[4] = {DEFAULT_BOOT_0, DEFAULT_BOOT_1, DEFAULT_BOOT_2, DEFAULT_BOOT_3};

void setup() {
  process_serial_init();
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(PIN_PWR, OUTPUT);
  analogWrite(PIN_PWR, DEFAULT_LED_PWR);
  pinMode(PIN_TURBO, INPUT);

  print_welcome();
  restore_settings();
  hex_display_init();

  if (boot_enabled) {
    hex_display_set(str_boot);
    last_activity = millis();
  }
}

int last_turbo = -1;
int current_turbo = -1;
void process_turbo() {
  if (turbo_enabled) {
    current_turbo = digitalRead(PIN_TURBO);
    if (last_turbo != current_turbo) {
      if (current_turbo == LOW) {
        hex_display_set(str_lo);
      } else {
        hex_display_set(str_hi);
      }
      last_turbo = current_turbo;
    }
  }
}

void loop() {
  process_serial();

  if (last_activity == 0 || ((millis() - last_activity) > ACTIVITY_THRESHOLD)) {
    process_turbo();
  }

  hex_display_scan();
}