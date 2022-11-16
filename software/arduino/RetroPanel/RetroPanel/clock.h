#pragma once
void clock_init();
bool clock_is_running();
bool clock_update();

void clock_print();
void clock_set_hour(uint8_t hour);
void clock_set_minutes(uint8_t minutes);