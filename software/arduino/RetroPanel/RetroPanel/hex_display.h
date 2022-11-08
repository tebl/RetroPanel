#pragma once
#include <Arduino.h>

void hex_display_init();
void hex_display_write(uint8_t digit, char character);
void hex_display_scan();