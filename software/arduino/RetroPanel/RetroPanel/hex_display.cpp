#include <Arduino.h>
#include "constants.h"
#include "settings.h"

extern uint8_t display_type;

char hex_values[4] = {0, 0, 0, 0};
bool hex_dp[4] = {0, 0, 0, 0};
uint8_t current_digit = 3;
unsigned long last_update = 0;

/* 
 * CK, Q1-Q4 2n3904
 *   Enable digit: HIGH
 *   Enable segment: HIGH
 * 
 * CA, Q1-Q4 replaced with 2n3906 installed backwards.
 *   Enable digit: LOW
 *   Enable segment: LOW
 */
#define STATE_ON (display_type == DISPLAY_TYPE_CK ? HIGH : LOW)
#define STATE_OFF (display_type == DISPLAY_TYPE_CK ? LOW : HIGH)

void hex_display_init() {
  digitalWrite(PIN_7S_DIGIT_1, STATE_OFF);
  pinMode(PIN_7S_DIGIT_1, OUTPUT);
  digitalWrite(PIN_7S_DIGIT_2, STATE_OFF);
  pinMode(PIN_7S_DIGIT_2, OUTPUT);
  digitalWrite(PIN_7S_DIGIT_3, STATE_OFF);
  pinMode(PIN_7S_DIGIT_3, OUTPUT);
  digitalWrite(PIN_7S_DIGIT_4, STATE_OFF);
  pinMode(PIN_7S_DIGIT_4, OUTPUT);

  digitalWrite(PIN_7S_A, STATE_OFF);
  pinMode(PIN_7S_A, OUTPUT);
  digitalWrite(PIN_7S_B, STATE_OFF);
  pinMode(PIN_7S_B, OUTPUT);
  digitalWrite(PIN_7S_C, STATE_OFF);
  pinMode(PIN_7S_C, OUTPUT);
  digitalWrite(PIN_7S_D, STATE_OFF);
  pinMode(PIN_7S_D, OUTPUT);
  digitalWrite(PIN_7S_E, STATE_OFF);
  pinMode(PIN_7S_E, OUTPUT);
  digitalWrite(PIN_7S_F, STATE_OFF);
  pinMode(PIN_7S_F, OUTPUT);
  digitalWrite(PIN_7S_G, STATE_OFF);
  pinMode(PIN_7S_G, OUTPUT);
  digitalWrite(PIN_7S_DP, STATE_OFF);
  pinMode(PIN_7S_DP, OUTPUT);
}

void hex_display_write(uint8_t digit, char character, bool dp) {
  if (digit < 0 || digit > 3) return;
  hex_values[digit] = character;

  // Special handling for period
  if (character == '.') {
    hex_values[digit] = 0;
    hex_dp[digit] = 1;
  }
  else hex_dp[digit] = dp;
}

/* Output the specified character array to hex displays.
 *
 * WARNING! This does not have a delimiter and assumes that it is at least
 *          4 characters long.
 */
void hex_display_set(char *c) {
  hex_display_write(0, c[0], false);
  hex_display_write(1, c[1], false);
  hex_display_write(2, c[2], false);
  hex_display_write(3, c[3], false);
}

uint8_t pin_from_digit(uint8_t digit) {
  switch (digit) {
    case 0: return PIN_7S_DIGIT_1;
    case 1: return PIN_7S_DIGIT_2;
    case 2: return PIN_7S_DIGIT_3;
    default:
    case 3: return PIN_7S_DIGIT_4;
  }
}

void write_character(bool a, bool b, bool c, bool d, bool e, bool f, bool g) {
  digitalWrite(PIN_7S_A, (a ? STATE_ON : STATE_OFF));
  digitalWrite(PIN_7S_B, (b ? STATE_ON : STATE_OFF));
  digitalWrite(PIN_7S_C, (c ? STATE_ON : STATE_OFF));
  digitalWrite(PIN_7S_D, (d ? STATE_ON : STATE_OFF));
  digitalWrite(PIN_7S_E, (e ? STATE_ON : STATE_OFF));
  digitalWrite(PIN_7S_F, (f ? STATE_ON : STATE_OFF));
  digitalWrite(PIN_7S_G, (g ? STATE_ON : STATE_OFF));
}

void write_dp(bool enabled) {
  if (enabled) digitalWrite(PIN_7S_DP, STATE_ON);
  else digitalWrite(PIN_7S_DP, STATE_OFF);
}

void next_digit() {
  current_digit++;
  if (current_digit > 3) current_digit = 0;
}

void enable_digit() {
  digitalWrite(pin_from_digit(current_digit), STATE_ON);
}

void disable_digit() {
  digitalWrite(pin_from_digit(current_digit), STATE_OFF);
}

void hex_display_scan() {
  if (last_update == 0 || ((millis() - last_update) > DISPLAY_THRESHOLD)) {
    disable_digit();
    next_digit();

    switch (hex_values[current_digit]) {
      case '0': write_character(1,1,1,1,1,1,0); break; // 0
      case '1': write_character(0,1,1,0,0,0,0); break; // 1
      case '2': write_character(1,1,0,1,1,0,1); break; // 2
      case '3': write_character(1,1,1,1,0,0,1); break; // 3
      case '4': write_character(0,1,1,0,0,1,1); break; // 4
      case '5': write_character(1,0,1,1,0,1,1); break; // 5
      case '6': write_character(1,0,1,1,1,1,1); break; // 6
      case '7': write_character(1,1,1,0,0,0,0); break; // 7
      case '8': write_character(1,1,1,1,1,1,1); break; // 8
      case '9': write_character(1,1,1,1,0,1,1); break; // 9
      case 'a': write_character(1,1,1,0,1,1,1); break; // A / 10
      case 'b': write_character(0,0,1,1,1,1,1); break; // b / 11
      case 'c': write_character(1,0,0,1,1,1,0); break; // C / 12
      case 'd': write_character(0,1,1,1,1,0,1); break; // d / 13
      case 'e': write_character(1,0,0,1,1,1,1); break; // E / 14
      case 'f': write_character(1,0,0,0,1,1,1); break; // F / 15
      case 'g': write_character(1,0,1,1,1,1,0); break; // G / 16
      case 'h': write_character(0,1,1,0,1,1,1); break; // H / 17
      case 'i': write_character(0,0,0,0,1,1,0); break; // I / 18
      case 'j': write_character(0,1,1,1,1,0,0); break; // J / 19
      case 'l': write_character(0,0,0,1,1,1,0); break; // L / 20
      case 'n': write_character(0,0,1,0,1,0,1); break; // n / 21
      case 'o': write_character(0,0,1,1,1,0,1); break; // o / 22
      case 'p': write_character(1,1,0,0,1,1,1); break; // P / 23
      case 'q': write_character(1,1,1,0,0,1,1); break; // q / 24
      case 'r': write_character(0,0,0,0,1,0,1); break; // r / 25
      case 's': write_character(1,0,1,1,0,1,1); break; // S / 26
      case 't': write_character(0,0,0,1,1,1,1); break; // t / 27
      case 'u': write_character(0,1,1,1,1,1,0); break; // U / 28
      case 'y': write_character(0,1,1,1,0,1,1); break; // y / 29
      case '-': write_character(0,0,0,0,0,0,1); break; // - / 30
      case ']': write_character(1,1,1,1,0,0,0); break; // ] / 32
      case '[': write_character(1,0,0,1,1,1,0); break; // [ / 33
      case '_': write_character(0,0,0,1,0,0,0); break; // _ / 34
      case '*': write_character(1,1,0,0,0,1,1); break; // *
      default:
      case 0: write_character(0,0,0,0,0,0,0); break;
    }
    write_dp(hex_dp[current_digit]);

    enable_digit();
    last_update = millis();
  }
}