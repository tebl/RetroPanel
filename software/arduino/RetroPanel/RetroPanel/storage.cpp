#include <Arduino.h>
#include <EEPROM.h>
#include "constants.h"
#include "settings.h"
#include "ansi.h"
#include "commands.h"

#define STORAGE_LENGTH 32
#define STORAGE_BYTES (STORAGE_LENGTH - 1)
#define STORAGE_CHECKSUM STORAGE_BYTES

extern bool ansi_enabled;
extern char str_lo[4];
extern char str_hi[4];

int storage_checksum() {
    int x = 0;
    for(int i = 0; i < STORAGE_BYTES; i++) {
        x += EEPROM.read(i);
    }
    x = x % 256;
    x = ~x;
    x = x + 1;
    x = x & 0xFF;
    return x;
}

void clear_settings() {
    int value = (EEPROM.read(STORAGE_CHECKSUM) + 1) % 256;
    EEPROM.update(STORAGE_CHECKSUM, value);
}

void restore_settings() {
    Serial.println(F("Restore settings ... "));
    if (EEPROM.read(STORAGE_CHECKSUM) == storage_checksum()) {
        for (int i = 0; i < STORAGE_BYTES; i++) {
            switch (i) {
                case 0:
                    ansi_enabled = EEPROM.read(i) == 1;
                    break;

                // LO-value
                case 1: EEPROM.read(i); break;
                case 2: EEPROM.read(i); break;
                case 3: EEPROM.read(i); break;
                case 4: EEPROM.read(i); break;

                // HI-value
                case 5: EEPROM.read(i); break;
                case 6: EEPROM.read(i); break;
                case 7: EEPROM.read(i); break;
                case 8: EEPROM.read(i); break;
                
                default:
                    break;
            }
        }
        ansi_highlight_ln((__FlashStringHelper*) STR_DONE);
    } else {
        ansi_notice_ln(F("... by loading defaults ... "));
        for (int i = 0; i < STORAGE_BYTES; i++) {
            switch (i) {
                case 0:
                    ansi_enabled = DEFAULT_ANSI;
                    break;

                // LO-value
                case 1: str_lo[0] = DEFAULT_LO_0; break;
                case 2: str_lo[1] = DEFAULT_LO_1; break;
                case 3: str_lo[2] = DEFAULT_LO_2; break;
                case 4: str_lo[3] = DEFAULT_LO_3; break;

                // HI-value
                case 5: str_hi[0] = DEFAULT_HI_0; break;
                case 6: str_hi[1] = DEFAULT_HI_1; break;
                case 7: str_hi[2] = DEFAULT_HI_2; break;
                case 8: str_hi[3] = DEFAULT_HI_3; break;
                
                default:
                    break;
            }
        }
        ansi_highlight_ln((__FlashStringHelper*) STR_DONE);
    }
}

void store_settings() {
    Serial.print(F("Storing settings ... "));
    for (int i = 0; i < STORAGE_BYTES; i++) {
        switch (i) {
            case 0:
                EEPROM.update(i, ansi_enabled ? 1 : 0);
                break;
            
            // LO-value
            case 1: EEPROM.update(i, str_lo[0]); break;
            case 2: EEPROM.update(i, str_lo[1]); break;
            case 3: EEPROM.update(i, str_lo[2]); break;
            case 4: EEPROM.update(i, str_lo[3]); break;

            // HI-value
            case 5: EEPROM.update(i, str_hi[0]); break;
            case 6: EEPROM.update(i, str_hi[1]); break;
            case 7: EEPROM.update(i, str_hi[2]); break;
            case 8: EEPROM.update(i, str_hi[3]); break;
            
            default:
                EEPROM.update(i, 0);
                break;
        }
    }
    EEPROM.update(STORAGE_CHECKSUM, storage_checksum());
    ansi_highlight_ln((__FlashStringHelper*) STR_DONE);
}