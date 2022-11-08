#include <Arduino.h>
#include "constants.h"
#include "settings.h"
#include "hex_display.h"

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(PIN_PWR, OUTPUT);
  analogWrite(PIN_PWR, DEFAULT_LED_PWR);
  pinMode(PIN_TURBO, INPUT);

  hex_display_init();
}

int last_turbo = -1;
int current_turbo = -1;
void loop() {
  current_turbo = digitalRead(PIN_TURBO);
  if (last_turbo != current_turbo) {
    if (current_turbo == LOW) {
      hex_display_write(0, ' ');
      hex_display_write(1, ' ');
      hex_display_write(2, 'l');
      hex_display_write(3, '0');
    } else {
      hex_display_write(0, ' ');
      hex_display_write(1, ' ');
      hex_display_write(2, 'h');
      hex_display_write(3, 'i');
    }
    last_turbo = current_turbo;
  }

  hex_display_scan();
}