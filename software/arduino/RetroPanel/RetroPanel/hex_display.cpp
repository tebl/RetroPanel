#include <Arduino.h>
#include "constants.h"
#include "settings.h"

char hex_values[4] = {0, 0, 0, 0};
bool hex_dp[4] = {0, 0, 0, 0};
uint8_t current_digit = 0;

void hex_display_init() {
  digitalWrite(PIN_7S_DIGIT_1, LOW);
  pinMode(PIN_7S_DIGIT_1, OUTPUT);
  digitalWrite(PIN_7S_DIGIT_2, LOW);
  pinMode(PIN_7S_DIGIT_1, OUTPUT);
  digitalWrite(PIN_7S_DIGIT_3, LOW);
  pinMode(PIN_7S_DIGIT_1, OUTPUT);
  digitalWrite(PIN_7S_DIGIT_4, LOW);
  pinMode(PIN_7S_DIGIT_1, OUTPUT);

  digitalWrite(PIN_7S_A, LOW);
  pinMode(PIN_7S_A, OUTPUT);
  digitalWrite(PIN_7S_B, LOW);
  pinMode(PIN_7S_B, OUTPUT);
  digitalWrite(PIN_7S_C, LOW);
  pinMode(PIN_7S_C, OUTPUT);
  digitalWrite(PIN_7S_D, LOW);
  pinMode(PIN_7S_D, OUTPUT);
  digitalWrite(PIN_7S_E, LOW);
  pinMode(PIN_7S_E, OUTPUT);
  digitalWrite(PIN_7S_F, LOW);
  pinMode(PIN_7S_F, OUTPUT);
  digitalWrite(PIN_7S_G, LOW);
  pinMode(PIN_7S_G, OUTPUT);
  digitalWrite(PIN_7S_DP, LOW);
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

uint8_t pin_from_digit(uint8_t digit) {
  switch (digit) {
  case 0: return PIN_7S_DIGIT_1;
  case 1: return PIN_7S_DIGIT_2;
  case 2: return PIN_7S_DIGIT_3;
  default:
  case 3: return PIN_7S_DIGIT_4;
  }
}

void hex_display_next() {
  current_digit++;
  if (current_digit > 3) current_digit = 0;
}

void write_character(bool a, bool b, bool c, bool d, bool e, bool f, bool g) {
  digitalWrite(PIN_7S_A, a);
  digitalWrite(PIN_7S_B, b);
  digitalWrite(PIN_7S_C, c);
  digitalWrite(PIN_7S_D, d);
  digitalWrite(PIN_7S_E, e);
  digitalWrite(PIN_7S_F, f);
  digitalWrite(PIN_7S_G, g);
}

void hex_display_scan() {
  digitalWrite(pin_from_digit(current_digit), LOW);
  hex_display_next();

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
    default:
    case 0: write_character(0,0,0,0,0,0,0); break;
  }
  digitalWrite(PIN_7S_DP, hex_dp[current_digit]);

  digitalWrite(pin_from_digit(current_digit), HIGH);
}