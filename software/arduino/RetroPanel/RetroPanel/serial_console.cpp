#include <Arduino.h>
#include "constants.h"
#include "settings.h"
#include "commands.h"

Serial_ serial_builtin = Serial;
HardwareSerial *serial_active;

/* Process a single received byte that was received over
 * the serial connection to the Arduino Nano, the byte
 * will be automatically echoed back to the terminal
 * application. 
 * 
 * Each line will be processed by its own function, EOL
 * will be interpreted as CR or NL as long as data has
 * previously been received. Any leading spaces will be
 * ignored.
 */
#define MAX_INPUT_SIZE 50

static char input_line[MAX_INPUT_SIZE];
static unsigned int input_pos = 0;

void process_serial_byte(const byte byte_in) {
  serial_active->print((char) byte_in);
  switch (byte_in) {
    /* Handle backspace character. Echoing will already have
    * moved the cursor back one position, but we'll need to
    * output a space and then move cursor back  again to
    * actually clear the character that was rubbed out.
    */
    case '\b':
      if (input_pos > 0) {
        input_pos--;
        serial_active->print(F(" \b"));
      }
      break;

    /* Handle end-of-line, ignore when one of them comes at the
    * start of a line to gracefully handle differences between
    * client platforms differences.
    */
    case '\n':
    case '\r':
      if (input_pos > 0) {
        input_line[input_pos] = 0;
        select_command(input_line);
        input_pos = 0;
      }
      break;

    /* Ignore any leading zeroes */
    case ' ':
    if (input_pos == 0) break;

    /* Add character to current command */
    default:
      if (input_pos < (MAX_INPUT_SIZE - 1)) {
        input_line[input_pos++] = byte_in;
      }
    break;
  }
}

void process_serial() {
  while(Serial.available() > 0) {
    serial_active = (HardwareSerial*) &serial_builtin;
    process_serial_byte(Serial.read());
  }

  while(Serial1.available() > 0) {
    serial_active = &Serial1;
    process_serial_byte(Serial1.read());
  }
}

void process_serial_init() {
  Serial.begin(BAUD_RATE_USB);
  Serial1.begin(BAUD_RATE_RS232);

  serial_active = (HardwareSerial*) &serial_builtin;
}