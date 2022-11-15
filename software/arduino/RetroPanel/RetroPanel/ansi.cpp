#include <Arduino.h>
#include "ansi.h"

extern bool ansi_enabled;
extern HardwareSerial *serial_active;

/* 
* Clear the screen and return cursor to top left position.
*/
void ansi_clear() {
  if (ansi_enabled) {
    serial_active->print(F("\033[H"));
    serial_active->print(F("\033[2J"));
  }
}

/* Set the specified colour as the current foreground colour, in order to
* keep compatibility somewhat manageable only the basic 8 colours should
* be used as well as the optional bright versions of them. A specified
* background can be used instead, but the way this works is that 
* foreground will remain locked at the default color so this may not be
* all that practical.
*/
void ansi_colour(int colour, bool bright) {
  if (ansi_enabled) {
    serial_active->print(F("\033["));
    if (bright) serial_active->print(F("1;"));
    serial_active->print(colour);
    serial_active->print("m");
  }
}
void ansi_colour(const __FlashStringHelper *string, int colour, bool bright, bool back_to_default, bool newline) {
  ansi_colour(colour, bright);
  if (newline) serial_active->println(string);
  else serial_active->print(string);
  if (back_to_default) ansi_default();
}
void ansi_colour(const char *string, int colour, bool bright, bool back_to_default, bool newline) {
  ansi_colour(colour, bright);
  if (newline) serial_active->println(string);
  else serial_active->print(string);
  if (back_to_default) ansi_default();
}
void ansi_colour_ln(const __FlashStringHelper *string, int colour, bool bright, bool back_to_default) { ansi_colour(string, colour, bright, back_to_default, true); }
void ansi_colour_ln(const char *string, int colour, bool bright, bool back_to_default) { ansi_colour(string, colour, bright, back_to_default, true); }

/* 
* Reset any formatting previously set, this will affect both color and any
* applies styles.
*/
void ansi_default() { ansi_colour(COLOUR_RESET); }


/* Configure text decoration effects, but note that compatibily with actual
* terminal software is very limited - mostly bold, underline and reversed
* seem to work reliably.
*/
void ansi_decoration(int decoration) {
  if (!ansi_enabled) return;
  serial_active->print(F("\033["));
  serial_active->print(decoration);
  serial_active->print("m");
}
void ansi_decoration(const __FlashStringHelper *string, int decoration, bool back_to_default, bool newline) {
  ansi_decoration(decoration);
  if (newline) serial_active->println(string);
  else serial_active->print(string);
  if (back_to_default) ansi_default();
}
void ansi_decoration_ln(const __FlashStringHelper *string, int decoration, bool back_to_default) { ansi_decoration(string, decoration, true); }

void ansi_highlight() {
  ansi_colour(COLOUR_WHITE, true);
  ansi_decoration(TEXT_DECORATION_UNDERLINE);
}
void ansi_highlight(const __FlashStringHelper *string, bool back_to_default, bool newline) {
  ansi_highlight();
  if (newline) serial_active->println(string);
  else serial_active->print(string);
  if (back_to_default) ansi_default();
}
void ansi_highlight_ln(const __FlashStringHelper *string, bool back_to_default) { ansi_highlight(string, back_to_default, true); }

void ansi_debug() { ansi_colour(COLOUR_WHITE); }
void ansi_debug(const __FlashStringHelper *string, bool back_to_default, bool newline) { ansi_colour(string, COLOUR_WHITE, false, back_to_default, newline); }
void ansi_debug_ln(const __FlashStringHelper *string, bool back_to_default) { ansi_colour(string, COLOUR_WHITE, false, back_to_default, true); }
void ansi_debug(const char *string, bool back_to_default, bool newline) { ansi_colour(string, COLOUR_WHITE, false, back_to_default, newline); }
void ansi_debug_ln(const char *string, bool back_to_default) { ansi_colour(string, COLOUR_WHITE, false, back_to_default, true); }

void ansi_error() { ansi_colour(COLOUR_RED, true); }
void ansi_error(const __FlashStringHelper *string, bool back_to_default, bool newline) { ansi_colour(string, COLOUR_RED, true, back_to_default, newline); }
void ansi_error_ln(const __FlashStringHelper *string, bool back_to_default) { ansi_colour(string, COLOUR_RED, true, back_to_default, true); }
void ansi_error(const char *string, bool back_to_default, bool newline) { ansi_colour(string, COLOUR_RED, true, back_to_default, newline); }
void ansi_error_ln(const char *string, bool back_to_default) { ansi_colour(string, COLOUR_RED, true, back_to_default, true); }

void ansi_notice() { ansi_colour(COLOUR_CYAN); }
void ansi_notice(const __FlashStringHelper *string, bool back_to_default, bool newline) { ansi_colour(string, COLOUR_CYAN, false, back_to_default, newline); }
void ansi_notice_ln(const __FlashStringHelper *string, bool back_to_default) { ansi_colour(string, COLOUR_CYAN, false, back_to_default, true); }
void ansi_notice(const char *string, bool back_to_default, bool newline) { ansi_colour(string, COLOUR_CYAN, false, back_to_default, newline); }
void ansi_notice_ln(const char *string, bool back_to_default) { ansi_colour(string, COLOUR_CYAN, false, back_to_default, true); }

void ansi_weak() { ansi_colour(COLOUR_BLUE); }
void ansi_weak(const __FlashStringHelper *string, bool back_to_default, bool newline) { ansi_colour(string, COLOUR_BLUE, false, back_to_default, newline); }
void ansi_weak_ln(const __FlashStringHelper *string, bool back_to_default) { ansi_colour(string, COLOUR_BLUE, false, back_to_default, true); }
void ansi_weak(const char *string, bool back_to_default, bool newline) { ansi_colour(string, COLOUR_BLUE, false, back_to_default, newline); }
void ansi_weak_ln(const char *string, bool back_to_default) { ansi_colour(string, COLOUR_BLUE, false, back_to_default, true); }

void ansi_status() {
  if (ansi_enabled) {
    serial_active->print(F("\033[1;31mA\033[1;32mN\033[1;33mS\033[1;34mI"));
    ansi_default();
    serial_active->print(F(" terminal codes "));
    ansi_highlight();
    serial_active->print(F("ON"));
    ansi_default();
    serial_active->println();
  } else {
    serial_active->println(F("ANSI terminal codes OFF"));
  }
}

void ansi_on() {
  ansi_enabled = true;
  ansi_status();
}

void ansi_off() {
  ansi_enabled = false;
  ansi_status();
}

/* Test ANSI control codes by writing them out to the serial terminal,
* obviously won't work when the codes are deactivated. Verification will
* be up to the user to determine. 
*/
void ansi_test() {
  ansi_clear();

  ansi_highlight(F("HIGHLIGHT"));
  serial_active->print(" ");

  ansi_debug(F("DEBUG"));
  serial_active->print(" ");

  ansi_error(F("ERROR"));
  serial_active->print(" ");

  ansi_notice(F("NOTICE"));
  serial_active->print(" ");

  ansi_weak(F("WEAK"));
  serial_active->println();

  ansi_decoration(F("BOLD"), TEXT_DECORATION_BOLD);
  serial_active->print(" ");

  ansi_decoration(F("DIM"), TEXT_DECORATION_DIM);
  serial_active->print(" ");

  ansi_decoration(F("ITALIC"), TEXT_DECORATION_ITALIC);
  serial_active->print(" ");

  ansi_decoration(F("UNDERLINE"), TEXT_DECORATION_UNDERLINE);
  serial_active->print(" ");

  ansi_decoration(F("BLINK"), TEXT_DECORATION_BLINK);
  serial_active->print(" ");

  ansi_decoration(F("REVERSED"), TEXT_DECORATION_REVERSED);
  serial_active->print(" ");

  ansi_decoration(F("STRIKETHROUGH"), TEXT_DECORATION_STRIKETHROUGH);
  serial_active->println();

  for (int i = COLOUR_BLACK; i <= COLOUR_WHITE; i++) {
    ansi_colour(i);
    serial_active->print(i);
    serial_active->print(" ");
  }
  ansi_default();
  serial_active->println();

  for (int i = COLOUR_BLACK; i < COLOUR_WHITE; i++) {
    ansi_colour(i, true);
    serial_active->print(i);
    serial_active->print(" ");
  }
  ansi_default();
  serial_active->println();

  for (int i = COLOUR_BG_BLACK; i <= COLOUR_BG_WHITE; i++) {
    ansi_colour(i);
    serial_active->print(i);
    serial_active->print(" ");
  }
  ansi_default();
  serial_active->println();

  for (int i = COLOUR_BG_BLACK; i < COLOUR_BG_WHITE; i++) {
    ansi_colour(i, true);
    serial_active->print(i);
    serial_active->print(" ");
  }
  ansi_default();
  serial_active->println();
}