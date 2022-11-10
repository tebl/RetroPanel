#pragma once
#define APP_TITLE "RetroPanel"
#define APP_VERSION "0.1"

#define BAUD_RATE_115200 115200
#define BAUD_RATE_38400 38400
#define BAUD_RATE_19200 19200
#define BAUD_RATE_9600 9600
#define BAUD_RATE_4800 4800
#define BAUD_RATE BAUD_RATE_115200

#define TERMINAL_COLS 80
#define PIN_SDA 2
#define PIN_SCL 3
#define PIN_PWR 9
#define PIN_TURBO 21

#define PIN_7S_A 20
#define PIN_7S_B 19
#define PIN_7S_C 18
#define PIN_7S_D 15
#define PIN_7S_E 14
#define PIN_7S_F 16
#define PIN_7S_G 10
#define PIN_7S_DP 8
#define PIN_7S_DIGIT_1 4
#define PIN_7S_DIGIT_2 5
#define PIN_7S_DIGIT_3 6
#define PIN_7S_DIGIT_4 7

#define DISPLAY_TYPE_CK 0
#define DISPLAY_TYPE_CA 1

const char STR_DONE[] PROGMEM  = "done!";
