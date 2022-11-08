#include <Arduino.h>
#include "constants.h"
#include "ansi.h"
#include "help.h"
#include "storage.h"

extern bool ansi_enabled;
extern uint8_t setting_volume;

void commands_init() {
}

void do_save_settings() {
  store_settings();
}

void do_scratch_settings() {
  clear_settings();
  ansi_error_ln(F("Cleared settings - please RESET device!"));
}

void do_reload_settings() {
  restore_settings();
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
  else if (handle_command(command, F("ansi test"), ansi_test));
  else if (handle_command(command, F("clear"), do_clear));
  else if (handle_command(command, F("help"), print_help));
  else if (handle_command(command, F("reload"), do_reload_settings));
  else if (handle_command(command, F("scratch"), do_scratch_settings));
  else if (handle_command(command, F("save"), do_save_settings));
  else if (handle_command(command, F("version"), print_version));
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