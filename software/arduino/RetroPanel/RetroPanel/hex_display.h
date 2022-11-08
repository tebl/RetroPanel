#pragma once
#include <Arduino.h>

void hex_display_init();
void hex_display_write(uint8_t digit, char character, bool dp = false);
void hex_display_set(char *c);
void hex_display_scan();
