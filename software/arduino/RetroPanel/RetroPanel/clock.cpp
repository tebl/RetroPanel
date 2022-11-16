#include <RTClib.h>
#include "ansi.h"
#include "hex_display.h"

extern HardwareSerial *serial_active;
extern bool clock_blinking;
extern char str_clock[6];

DS3231 rtc;
DateTime now;

bool clock_initialized = false;
void clock_init() {
  if (clock_initialized) return;
  Wire.begin();
  rtc.begin();

  if (!rtc.isrunning()) {
    ansi_error_ln(F("RTC is NOT running!"));
    rtc.adjust(DateTime(__DATE__, __TIME__));
  }

  clock_initialized = true;
}

bool clock_is_running() {
  return rtc.isrunning();
}

bool clock_dirty = false;
void set_clock_digit(uint8_t digit, char value) {
  if (str_clock[digit] != value) clock_dirty = true;
  str_clock[digit] = value;
}

bool clock_update() {
  now = rtc.now();

  clock_dirty = false;
  set_clock_digit(0, '0' + (now.hour() / 10));
  set_clock_digit(1, '0' + (now.hour() % 10));
  set_clock_digit(2, '0' + (now.minute() / 10));
  set_clock_digit(3, '0' + (now.minute() % 10));
  set_clock_digit(4, '0' + (now.second() % 10));
  set_clock_digit(5, '0' + (now.second() % 10));

  if (clock_dirty) {
    hex_display_write(0, str_clock[0], false);
    hex_display_write(1, str_clock[1], (clock_blinking ? (now.second() % 2) : true));
    hex_display_write(2, str_clock[2], false);
    hex_display_write(3, str_clock[3], false);
  }
  return clock_dirty;
}

void clock_set_hour(uint8_t hour) {
  if (!clock_is_running()) return;
  now = rtc.now();
  now.sethour(hour);
  rtc.adjust(now);
}

void clock_set_minutes(uint8_t minutes) {
  if (!clock_is_running()) return;
  now = rtc.now();
  now.setminute(minutes);
  now.setsecond(0);
  rtc.adjust(now);
}


void print_leading_zero(uint8_t number) {
  if (number < 10) serial_active->print('0');
  serial_active->print(number);
}

void clock_print() {
  if (!clock_is_running()) return;
  now = rtc.now();
  print_leading_zero(now.hour());
  serial_active->print(':');
  print_leading_zero(now.minute());
  serial_active->print(':');
  print_leading_zero(now.second());
}