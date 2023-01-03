#include <BMP280_DEV.h>
#include "ansi.h"
#include "hex_display.h"

extern HardwareSerial *serial_active;
extern char str_temperature[4];

BMP280_DEV bmp280;
float current_temperature;

bool temperature_initialized = false;
void temperature_init() {
  if (temperature_initialized) return;

  bmp280.begin(BMP280_I2C_ALT_ADDR);
  bmp280.setTimeStandby(TIME_STANDBY_2000MS);
  bmp280.startNormalConversion();

  temperature_initialized = true;
}

bool temperature_dirty = false;
void set_temperature_digit(uint8_t digit, char value) {
  if (str_temperature[digit] != value) temperature_dirty = true;
  str_temperature[digit] = value;
}

bool temperature_update() {
  temperature_dirty = false;

  if (bmp280.getTemperature(current_temperature)) {
    int value = (int)(current_temperature + 0.5);
    set_temperature_digit(0, '0' + (value / 10));
    set_temperature_digit(1, '0' + (value % 10));
  }

  if (temperature_dirty) {
    hex_display_write(0, str_temperature[0], false);
    hex_display_write(1, str_temperature[1], false);
    hex_display_write(2, str_temperature[2], false);
    hex_display_write(3, str_temperature[3], false);
  }

  return temperature_dirty;
}

void temperature_print() {
  serial_active->print(current_temperature);
  serial_active->print(" *C");
}