#include <Arduino.h>
#include "constants.h"
#include "settings.h"
#include "commands.h"
#include "storage.h"
#include "hex_display.h"
#include "serial_console.h"

bool ansi_enabled = DEFAULT_ANSI;
char str_lo[4] = {DEFAULT_LO_0, DEFAULT_LO_1, DEFAULT_LO_2, DEFAULT_LO_3};
char str_hi[4] = {DEFAULT_HI_0, DEFAULT_HI_1, DEFAULT_HI_2, DEFAULT_HI_3};

void setup() {
  process_serial_init();
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(PIN_PWR, OUTPUT);
  analogWrite(PIN_PWR, DEFAULT_LED_PWR);
  pinMode(PIN_TURBO, INPUT);

  print_welcome();
  restore_settings();
  hex_display_init();
}

int last_turbo = -1;
int current_turbo = -1;
void loop() {
  process_serial();

  current_turbo = digitalRead(PIN_TURBO);
  if (last_turbo != current_turbo) {
    if (current_turbo == LOW) {
      for (int i = 0; i < 4; i++) {
        hex_display_write(i, str_lo[i]);
      }
    } else {
      for (int i = 0; i < 4; i++) {
        hex_display_write(i, str_hi[i]);
      }
    }
    last_turbo = current_turbo;
  }

  hex_display_scan();
}