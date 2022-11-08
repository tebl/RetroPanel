#include <Arduino.h>
#include "constants.h"

char hex_values[4] = {0, 0, 0, 0};
uint8_t current_digit = 0;

const int num_segments = 9;
const int pin_segments[] { PIN_7S_A, PIN_7S_B, PIN_7S_C, PIN_7S_D, PIN_7S_E, PIN_7S_F, PIN_7S_G, PIN_7S_DP };
const char num_hex_chars = 37;
const char hex_characters[num_hex_chars][num_segments] { 
  { 0, 0,0,0,0,0,0,0,0},
  {' ',0,0,0,0,0,0,0,0},
  {'0',1,1,1,1,1,1,0,0}, // 0
  {'1',0,1,1,0,0,0,0,0}, // 1
  {'2',1,1,0,1,1,0,1,0}, // 2
  {'3',1,1,1,1,0,0,1,0}, // 3
  {'4',0,1,1,0,0,1,1,0}, // 4
  {'5',1,0,1,1,0,1,1,0}, // 5
  {'6',1,0,1,1,1,1,1,0}, // 6
  {'7',1,1,1,0,0,0,0,0}, // 7
  {'8',1,1,1,1,1,1,1,0}, // 8
  {'9',1,1,1,1,0,1,1,0}, // 9
  {'a',1,1,1,0,1,1,1,0}, // A / 10
  {'b',0,0,1,1,1,1,1,0}, // b / 11
  {'c',1,0,0,1,1,1,0,0}, // C / 12
  {'d',0,1,1,1,1,0,1,0}, // d / 13
  {'e',1,0,0,1,1,1,1,0}, // E / 14
  {'f',1,0,0,0,1,1,1,0}, // F / 15
  {'g',1,0,1,1,1,1,0,0}, // G / 16
  {'h',0,1,1,0,1,1,1,0}, // H / 17
  {'i',0,0,0,0,1,1,0,0}, // I / 18
  {'j',0,1,1,1,1,0,0,0}, // J / 19
  {'l',0,0,0,1,1,1,0,0}, // L / 20
  {'n',0,0,1,0,1,0,1,0}, // n / 21
  {'o',0,0,1,1,1,0,1,0}, // o / 22
  {'p',1,1,0,0,1,1,1,0}, // P / 23
  {'q',1,1,1,0,0,1,1,0}, // q / 24
  {'r',0,0,0,0,1,0,1,0}, // r / 25
  {'s',1,0,1,1,0,1,1,0}, // S / 26   looks like number 5
  {'t',0,0,0,1,1,1,1,0}, // t / 27
  {'u',0,1,1,1,1,1,0,0}, // U / 28
  {'y',0,1,1,1,0,1,1,0}, // y / 29
  {'-',0,0,0,0,0,0,1,0}, // - / 30
  {'.',0,0,0,0,0,0,0,1}, // . / 31
  {']',1,1,1,1,0,0,0,0}, // ] / 32
  {'[',1,0,0,1,1,1,0,0}, // [ / 33
  {'_',0,0,0,1,0,0,0,0}, // _ / 34
};

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

void hex_display_scan() {
  digitalWrite(pin_from_digit(current_digit), LOW);
  hex_display_next();

  bool c_found = false;
  for (int c_idx = 0; c_idx < num_hex_chars; c_idx++) {
    if (hex_values[current_digit] == hex_characters[c_idx][0]) {
      for (int p_idx = 0; p_idx < (num_segments - 1); p_idx++) {
        digitalWrite(pin_segments[p_idx], hex_characters[c_idx][p_idx + 1]);
      }
      c_found = true;
      break;
    }
  }
  if (!c_found) {
    for (int p_idx = 0; p_idx < (num_segments - 1); p_idx++) {
      digitalWrite(pin_segments[p_idx], hex_characters[0][p_idx + 1]);
    }
  }

  digitalWrite(pin_from_digit(current_digit), HIGH);
}