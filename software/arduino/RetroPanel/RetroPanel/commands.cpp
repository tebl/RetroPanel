#include <Arduino.h>
#include "constants.h"
#include "ansi.h"
#include "help.h"
#include "storage.h"
#include "hex_display.h"

extern bool ansi_enabled;
extern bool turbo_enabled;
extern bool boot_enabled;
extern char str_lo[4];
extern char str_hi[4];
extern char str_boot[4];
extern unsigned long last_activity;

void print_display_str(char *c) {
  for (int i = 0; i < 4; i++) {
    switch (c[i]) {
    case 0:
      Serial.print(' ');
      break;
    
    default:
      Serial.print(c[i]);
      break;
    }
  }
}

void boot_status() {
  Serial.print(F("Boot message "));
  if (boot_enabled) {
    ansi_weak_ln(F("ON"));
  } else {
    ansi_highlight_ln(F("OFF"));
  }
  Serial.print(F("Value: \""));
  ansi_highlight();
  print_display_str(str_boot);
  ansi_default();
  Serial.println('\"');
}

void boot_on() {
  boot_enabled = true;
  boot_status();
}

void boot_off() {
  boot_enabled = false;
  boot_status();
}

void turbo_status() {
  Serial.print(F("Turbo feature "));
  if (turbo_enabled) {
    ansi_weak_ln(F("ON"));
  } else {
    ansi_highlight_ln(F("OFF"));
  }

  Serial.print(F("Value LO: \""));
  ansi_highlight();
  print_display_str(str_lo);
  ansi_default();
  Serial.println('\"');

  Serial.print(F("Value HI: \""));
  ansi_highlight();
  print_display_str(str_hi);
  ansi_default();
  Serial.println('\"');
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
  Serial.print(F(APP_TITLE));
  Serial.print(' ');
  Serial.println(F(APP_VERSION));
}

void print_welcome() {
  ansi_clear();
  ansi_highlight();
  print_version();
  ansi_default();
}

bool parser_error(String command, String error) {
  ansi_error();
  Serial.print("? " + command);
  Serial.print(" (");
  Serial.print(error);
  Serial.println(")");
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
  return true;
}

/* Called when a recognized command has been recognized, but before the
* function is actually called.
*/
void echo_command(String command) {
  ansi_colour(COLOUR_CYAN);
  Serial.println("> "+ command);
  ansi_default();
}

/* Called when the entered command has not been recognized, we don't know
* what to do next so we'll just print it as an error instead.
*/
void echo_unknown(String command) {
  ansi_error();
  Serial.println("? " + command);
  ansi_default();
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
  else if (handle_command(command, F("boot"), boot_status));
  else if (handle_command(command, F("boot on"), boot_on));
  else if (handle_command(command, F("boot off"), boot_off));
  else if (handle_command(command, F("ansi test"), ansi_test));
  else if (handle_command(command, F("clear"), do_clear));
  else if (handle_command(command, F("dump"), dump_settings));
  else if (handle_command(command, F("help"), print_help));
  else if (handle_command(command, F("reload"), restore_settings));
  else if (handle_command(command, F("scratch"), do_scratch_settings));
  else if (handle_command(command, F("test boot"), set_boot));
  else if (handle_command(command, F("test hi"), set_hi));
  else if (handle_command(command, F("test lo"), set_lo));
  else if (handle_command(command, F("turbo"), turbo_status));
  else if (handle_command(command, F("turbo on"), turbo_on));
  else if (handle_command(command, F("turbo off"), turbo_off));  
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