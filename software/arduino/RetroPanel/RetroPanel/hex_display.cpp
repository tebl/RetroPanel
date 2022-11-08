#include <Arduino.h>
#include "constants.h"

char hex_values[4] = {0, 0, 0, 0};
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

void hex_display_write(uint8_t digit, char character) {
  if (digit < 0 || digit > 3) return;
  hex_values[digit] = character;
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

void set_segments(bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool dp) {
  digitalWrite(PIN_7S_A, a);
  digitalWrite(PIN_7S_B, b);
  digitalWrite(PIN_7S_C, c);
  digitalWrite(PIN_7S_D, d);
  digitalWrite(PIN_7S_E, e);
  digitalWrite(PIN_7S_F, f);
  digitalWrite(PIN_7S_G, g);
  digitalWrite(PIN_7S_DP, dp);
}

void hex_display_scan() {
  digitalWrite(pin_from_digit(current_digit), LOW);
  hex_display_next();

  switch (hex_values[current_digit]) {
    case '0': set_segments(1,1,1,1,1,1,0,0); break; // 0
    case '1': set_segments(0,1,1,0,0,0,0,0); break; // 1
    case '2': set_segments(1,1,0,1,1,0,1,0); break; // 2
    case '3': set_segments(1,1,1,1,0,0,1,0); break; // 3
    case '4': set_segments(0,1,1,0,0,1,1,0); break; // 4
    case '5': set_segments(1,0,1,1,0,1,1,0); break; // 5
    case '6': set_segments(1,0,1,1,1,1,1,0); break; // 6
    case '7': set_segments(1,1,1,0,0,0,0,0); break; // 7
    case '8': set_segments(1,1,1,1,1,1,1,0); break; // 8
    case '9': set_segments(1,1,1,1,0,1,1,0); break; // 9
    case 'a': set_segments(1,1,1,0,1,1,1,0); break; // A / 10
    case 'b': set_segments(0,0,1,1,1,1,1,0); break; // b / 11
    case 'c': set_segments(1,0,0,1,1,1,0,0); break; // C / 12
    case 'd': set_segments(0,1,1,1,1,0,1,0); break; // d / 13
    case 'e': set_segments(1,0,0,1,1,1,1,0); break; // E / 14
    case 'f': set_segments(1,0,0,0,1,1,1,0); break; // F / 15
    case 'g': set_segments(1,0,1,1,1,1,0,0); break; // G / 16
    case 'h': set_segments(0,1,1,0,1,1,1,0); break; // H / 17
    case 'i': set_segments(0,0,0,0,1,1,0,0); break; // I / 18
    case 'j': set_segments(0,1,1,1,1,0,0,0); break; // J / 19
    case 'l': set_segments(0,0,0,1,1,1,0,0); break; // L / 20
    case 'n': set_segments(0,0,1,0,1,0,1,0); break; // n / 21
    case 'o': set_segments(0,0,1,1,1,0,1,0); break; // o / 22
    case 'p': set_segments(1,1,0,0,1,1,1,0); break; // P / 23
    case 'q': set_segments(1,1,1,0,0,1,1,0); break; // q / 24
    case 'r': set_segments(0,0,0,0,1,0,1,0); break; // r / 25
    case 's': set_segments(1,0,1,1,0,1,1,0); break; // S / 26
    case 't': set_segments(0,0,0,1,1,1,1,0); break; // t / 27
    case 'u': set_segments(0,1,1,1,1,1,0,0); break; // U / 28
    case 'y': set_segments(0,1,1,1,0,1,1,0); break; // y / 29
    case '-': set_segments(0,0,0,0,0,0,1,0); break; // - / 30
    case '.': set_segments(0,0,0,0,0,0,0,1); break; // . / 31
    case ']': set_segments(1,1,1,1,0,0,0,0); break; // ] / 32
    case '[': set_segments(1,0,0,1,1,1,0,0); break; // [ / 33
    case '_': set_segments(0,0,0,1,0,0,0,0); break; // _ / 34
    default:
    case 0: set_segments(0,0,0,0,0,0,0,0); break;
  }

  digitalWrite(pin_from_digit(current_digit), HIGH);
}