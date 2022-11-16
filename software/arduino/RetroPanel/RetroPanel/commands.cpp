#include <Arduino.h>
#include "constants.h"
#include "settings.h"
#include "ansi.h"
#include "help.h"
#include "storage.h"
#include "hex_display.h"
#include "clock.h"

extern bool ansi_enabled;
extern bool turbo_enabled;
extern bool boot_enabled;
extern bool clock_enabled;
extern bool clock_blinking;
extern bool rs232_enabled;
extern uint8_t display_type;
extern char str_lo[4];
extern char str_hi[4];
extern char str_boot[4];
extern unsigned long last_activity;
extern HardwareSerial *serial_active;

/* Called when a recognized command has been recognized, but before the
* function is actually called.
*/
void echo_command(String command) {
  ansi_colour(COLOUR_CYAN);
  serial_active->println("> "+ command);
  ansi_default();
}

/* Called when the entered command has not been recognized, we don't know
* what to do next so we'll just print it as an error instead.
*/
void echo_unknown(String command) {
  ansi_error();
  serial_active->println("? " + command);
  ansi_default();
}

void do_support() {
  serial_active->println(F("For support, please visit:"));
  serial_active->println();
  serial_active->print(' ');
  serial_active->print(' ');
  serial_active->println(F(SUPPORT_URL));
}

void clock_status() {
  serial_active->print(F("Clock is "));
  if (clock_enabled) {
    ansi_weak_ln(F("ON"));
  } else {
    ansi_error_ln(F("OFF"));
  }

  serial_active->print(F("Clock blinking is "));
  if (clock_blinking) {
    ansi_weak_ln(F("ON"));
  } else {
    ansi_error_ln(F("OFF"));
  }

  serial_active->print(F("Value: \""));
  if (clock_is_running()) {
    ansi_notice();
    clock_print();
    ansi_default();
  } else {
    ansi_error();
    serial_active->print(F("RTC NOT running."));
    ansi_default();   
  }
  serial_active->println('\"');
}

void clock_on() {
  clock_enabled = true;
  clock_init();
  clock_status();
}

void clock_off() {
  clock_enabled = false;
  clock_status();
}

void clock_blink_on() {
  clock_blinking = true;
  clock_status();
}

void clock_blink_off() {
  clock_blinking = false;
  clock_status();
}

void print_display_str(char *c) {
  for (int i = 0; i < 4; i++) {
    switch (c[i]) {
    case 0:
      serial_active->print(' ');
      break;
    
    default:
      serial_active->print(c[i]);
      break;
    }
  }
}

void boot_status() {
  serial_active->print(F("Boot message "));
  if (boot_enabled) {
    ansi_weak_ln(F("ON"));
  } else {
    ansi_error_ln(F("OFF"));
  }
  serial_active->print(F("Value: \""));
  ansi_notice();
  print_display_str(str_boot);
  ansi_default();
  serial_active->println('\"');
}

void boot_on() {
  boot_enabled = true;
  boot_status();
}

void boot_off() {
  boot_enabled = false;
  boot_status();
}

void rs232_status() {
  serial_active->print(F("RS-232 "));
  if (rs232_enabled) {
    ansi_weak_ln(F("ON"));
  } else {
    ansi_error_ln(F("OFF"));
  }
  serial_active->print(F("Baud rate: \""));
  ansi_notice();
  serial_active->print(BAUD_RATE_RS232);
  ansi_default();
  serial_active->println('\"');
}

void rs232_on() {
  rs232_enabled = true;
  rs232_status();
}

void rs232_off() {
  rs232_enabled = false;
  rs232_status();
}

void display_status() {
  serial_active->print(F("Display type set to "));
  if (display_type == DISPLAY_TYPE_CA) {
    ansi_weak_ln(F("CA"));
  } else {
    ansi_weak_ln(F("CK"));
  }
}

void display_set_ca() {
  display_type = DISPLAY_TYPE_CA;
  display_status();
}

void display_set_ck() {
  display_type = DISPLAY_TYPE_CK;
  display_status();
}

void turbo_status() {
  serial_active->print(F("Turbo feature "));
  if (turbo_enabled) {
    ansi_weak_ln(F("ON"));
  } else {
    ansi_error_ln(F("OFF"));
  }

  serial_active->print(F("Value LO: \""));
  ansi_notice();
  print_display_str(str_lo);
  ansi_default();
  serial_active->println('\"');

  serial_active->print(F("Value HI: \""));
  ansi_notice();
  print_display_str(str_hi);
  ansi_default();
  serial_active->println('\"');
}

void turbo_on() {
  turbo_enabled = true;
  turbo_status();
}

void turbo_off() {
  turbo_enabled = false;
  turbo_status();
}

void set_lo() {
  hex_display_set(str_lo);
  last_activity = millis();
}

void set_hi() {
  hex_display_set(str_hi);
  last_activity = millis();
}

void set_boot() {
  hex_display_set(str_boot);
  last_activity = millis();
}

void do_scratch_settings() {
  clear_settings();
  ansi_error_ln(F("Cleared settings - please RESET device!"));
}

void print_version() {
  serial_active->print(F(APP_TITLE));
  serial_active->print(' ');
  serial_active->println(F(APP_VERSION));
}

void print_welcome() {
  ansi_clear();
  ansi_highlight();
  print_version();
  ansi_default();
}

bool parser_error(String command, String error) {
  ansi_error();
  serial_active->print("? " + command);
  serial_active->print(" (");
  serial_active->print(error);
  serial_active->println(")");
  ansi_default();

  return false;
}

bool handle_set(String c) {
  if (c.length() != 8) return parser_error(c, F("argument format"));
  hex_display_write(0, c[4]);
  hex_display_write(1, c[5]);
  hex_display_write(2, c[6]);
  hex_display_write(3, c[7]);
  last_activity = millis();
  echo_command(c);
  return true;
}

bool handle_set_boot(String c) {
  if (c.length() != 13) return parser_error(c, F("argument format"));
  str_boot[0] = c[9];
  str_boot[1] = c[10];
  str_boot[2] = c[11];
  str_boot[3] = c[12];
  echo_command(c);
  set_boot();
  boot_status();
  return true;
}

bool handle_set_hi(String c) {
  if (c.length() != 17) return parser_error(c, F("argument format"));
  str_hi[0] = c[13];
  str_hi[1] = c[14];
  str_hi[2] = c[15];
  str_hi[3] = c[16];
  echo_command(c);
  set_hi();
  turbo_status();
  return true;
}

bool handle_set_lo(String c) {
  if (c.length() != 17) return parser_error(c, F("argument format"));
  str_lo[0] = c[13];
  str_lo[1] = c[14];
  str_lo[2] = c[15];
  str_lo[3] = c[16];
  echo_command(c);
  set_lo();
  turbo_status();
  return true;
}

bool in_range(uint8_t value, uint8_t low, uint8_t high) {
  if (value < low || value > high) return false;
  return true;
}

bool handle_set_clock(String c) {
  if (!clock_is_running()) return parser_error(c, F("clock needs to be running"));
  if (c.length() != 14 ||
      !in_range(c[10] - '0', 0, 2) ||
      !in_range(c[11] - '0', 0, 4) ||
      !in_range(c[12] - '0', 0, 5) ||
      !in_range(c[13] - '0', 0, 9)) return parser_error(c, F("clock must be specified as HHMM"));
  echo_command(c);

  clock_set_hour(((c[10] - '0') * 10) + (c[11] - '0'));
  clock_set_minutes(((c[12] - '0') * 10) + (c[13] - '0'));

  clock_status();
  return true;
}

/* Clear the serial terminal screen, but note that this won't actually do
* anything unless ANSI terminal codes are supported by the client and
* have not been explicitly disabled. Does a second echo of the command
* as the first one will disappear upon execution.
*/
void do_clear() {
  ansi_clear();
  if (ansi_enabled) echo_command(F("clear"));
}

/*
* Handle serial commands, mainly just matches the name and if it does the
* supplied function is run. Recognized commands are echoed back to the user.
*/
bool handle_command(String command, String name, void (*function)(), bool suppress_echo = false) {
  if (command == name) {
    echo_command(command);
    (*function)();
    return true;
  }
  return false;
}

void select_command_main(String command) {
       if (handle_command(command, F("ansi"), ansi_status));
  else if (handle_command(command, F("ansi on"), ansi_on));
  else if (handle_command(command, F("ansi off"), ansi_off));
  else if (handle_command(command, F("ansi test"), ansi_test));
  else if (handle_command(command, F("boot"), boot_status));
  else if (handle_command(command, F("boot on"), boot_on));
  else if (handle_command(command, F("boot off"), boot_off));
  else if (command.startsWith(F("boot set"))) handle_set_boot(command);
  else if (handle_command(command, F("clear"), do_clear));
  else if (handle_command(command, F("clock"), clock_status));
  else if (handle_command(command, F("clock on"), clock_on));
  else if (handle_command(command, F("clock off"), clock_off));
  else if (handle_command(command, F("clock blink on"), clock_blink_on));
  else if (handle_command(command, F("clock blink off"), clock_blink_off));
  else if (command.startsWith(F("clock set"))) handle_set_clock(command);
  else if (handle_command(command, F("display"), display_status));
  else if (handle_command(command, F("display ca"), display_set_ca));
  else if (handle_command(command, F("display ck"), display_set_ck));
  else if (handle_command(command, F("dump"), dump_settings));
  else if (handle_command(command, F("help"), print_help));
  else if (handle_command(command, F("reload"), restore_settings));
  else if (handle_command(command, F("rs232"), rs232_status));
  else if (handle_command(command, F("rs232 on"), rs232_on));
  else if (handle_command(command, F("rs232 off"), rs232_off));
  else if (handle_command(command, F("scratch"), do_scratch_settings));
  else if (handle_command(command, F("support"), do_support));
  else if (handle_command(command, F("test boot"), set_boot));
  else if (handle_command(command, F("test hi"), set_hi));
  else if (handle_command(command, F("test lo"), set_lo));
  else if (handle_command(command, F("turbo"), turbo_status));
  else if (handle_command(command, F("turbo on"), turbo_on));
  else if (handle_command(command, F("turbo off"), turbo_off));
  else if (command.startsWith(F("turbo set hi"))) handle_set_hi(command);
  else if (command.startsWith(F("turbo set lo"))) handle_set_lo(command);
  else if (handle_command(command, F("save"), store_settings));
  else if (handle_command(command, F("version"), print_version));
  else if (command.startsWith(F("set"))) handle_set(command);
  else {
    echo_unknown(command);
  }
}

/*
* Run the command associated with the serial command given, compared against
* all known commands (depending on the currently selected command set).
*/
void select_command(String command) {
  select_command_main(command);
}