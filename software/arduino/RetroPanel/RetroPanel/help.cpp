#include <Arduino.h>
#include "ansi.h"
#include "constants.h"

extern HardwareSerial *serial_active;

/*
* Calculates the length of a string that has been stored in Flash memory
* instead of RAM, normally defined using the Arduino F() macro.
*/
unsigned int flash_length(const __FlashStringHelper *string) {
  const char *ptr = (const char *) string;
  int size = 0;
  while (pgm_read_byte_near(ptr++)) {
    size++;
  }
  return size;
}

/*
* Arduino lacks a way to pad strings, so then I guess we're doing it the 
* ridiculously hard way instead of leaving things somewhat sensible. Feature
* creep is a real thing, but doing this for fun, so let's just live with it!
*/
void help_command(const __FlashStringHelper *command = nullptr, 
                  const __FlashStringHelper *description = nullptr,
                  const __FlashStringHelper *parameter = nullptr,
                  const __FlashStringHelper *switch_ref = nullptr) {
  int size = 0;
  int position = 0;
  if (command != nullptr) {
    size = flash_length(command);
    ansi_notice(command);
  }

  if (parameter != nullptr) {
    size += flash_length(parameter) + 1;
    serial_active->print(' ');
    ansi_colour(parameter, COLOUR_WHITE);
  }
  for (int i = size; i < 21; i++) serial_active->print(' ');
  position = 21;

  if (description != nullptr) {
    ansi_colour(description, COLOUR_WHITE);
    position += flash_length(description);
  }

  if (switch_ref != nullptr) {
    size = TERMINAL_COLS - flash_length(switch_ref);
    for (int i = position; i < size; i++) serial_active->print(' ');
    ansi_colour(switch_ref, COLOUR_MAGENTA);
  }

  serial_active->println();
}

/*
* Run the command associated with the serial command given, compared against
* all known commands (depending on the currently selected command set).
*/
void print_help() {
  ansi_colour_ln(F("Commands supported:"), COLOUR_MAGENTA);
  help_command(F("ansi <on|off>"),        F("Enable/disable ANSI terminal code usage"));
  help_command(F("ansi test"),            F("Test ANSI terminal codes on terminal"));
  help_command(F("boot"),                 F("Boot message status"));
  help_command(F("boot <on|off>"),        F("Enable/disable boot message"));
  help_command(F("boot set <abcd>"),      F("Set boot message"));
  help_command(F("clear"),                F("Clear screen"));
  help_command(F("clock"),                F("Show DS3231 clock status"));
  help_command(F("clock <on|off>"),       F("Enable/disable clock display"));
  help_command(F("clock blink <on|off>"), F("Enable/disable blinking clock"));
  help_command(F("clock set <HHMM>"),     F("Set the time using format HHMM"));
  help_command(F("display"),              F("Show configured display type"));
  help_command(F("display <ca|ck>"),      F("Configure display type"));
  help_command(F("dump"),                 F("Show raw contents of EEPROM"));  
  help_command(F("reload"),               F("Reload settings from EEPROM"));  
  help_command(F("save"),                 F("Save current settings to EEPROM"));
  help_command(F("set <abcd>"),           F("Set message on display"));
  help_command(F("scratch"),              F("Clear settings in EEPROM (reset afterwards)"));
  help_command(F("support"),              F("Show support information"));
  help_command(F("test <hi|lo|boot>"),    F("Test stored messages on display"));
  help_command(F("turbo"),                F("Turbo message status"));
  help_command(F("turbo <on|off>"),       F("Enable/disable turbo message"));
  help_command(F("turbo set hi <abcd>"),  F("Set turbo HI message"));
  help_command(F("turbo set lo <abcd>"),  F("Set turbo LO message"));
  help_command(F("version"),              F("Prints firmware version"));
}
