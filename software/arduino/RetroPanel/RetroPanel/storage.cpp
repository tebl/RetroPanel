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
extern bool turbo_enabled;
extern bool boot_enabled;
extern char str_lo[4];
extern char str_hi[4];
extern char str_boot[4];

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

bool checksum_passes() {
    return EEPROM.read(STORAGE_CHECKSUM) == storage_checksum();
}

void clear_settings() {
    int value = (EEPROM.read(STORAGE_CHECKSUM) + 1) % 256;
    EEPROM.update(STORAGE_CHECKSUM, value);
}

void restore_settings() {
    Serial.println(F("Restore settings ... "));
    if (checksum_passes()) {
        for (int i = 0; i < STORAGE_BYTES; i++) {
            switch (i) {
                case 0: ansi_enabled = EEPROM.read(i) == 1; break;
                case 1: turbo_enabled = EEPROM.read(i) == 1; break;
                case 2: boot_enabled = EEPROM.read(i) == 1; break;

                // Boot message
                case 19: str_boot[0] = EEPROM.read(i); break;
                case 20: str_boot[1] = EEPROM.read(i); break;
                case 21: str_boot[2] = EEPROM.read(i); break;
                case 22: str_boot[3] = EEPROM.read(i); break;

                // LO-value
                case 23: str_lo[0] = EEPROM.read(i); break;
                case 24: str_lo[1] = EEPROM.read(i); break;
                case 25: str_lo[2] = EEPROM.read(i); break;
                case 26: str_lo[3] = EEPROM.read(i); break;

                // HI-value
                case 27: str_hi[0] = EEPROM.read(i); break;
                case 28: str_hi[1] = EEPROM.read(i); break;
                case 29: str_hi[2] = EEPROM.read(i); break;
                case 30: str_hi[3] = EEPROM.read(i); break;
                
                default:
                    break;
            }
        }
        ansi_highlight_ln((__FlashStringHelper*) STR_DONE);
    } else {
        ansi_notice_ln(F("... by loading defaults ... "));
        for (int i = 0; i < STORAGE_BYTES; i++) {
            switch (i) {
                case 0: ansi_enabled = DEFAULT_ANSI; break;
                case 1: turbo_enabled = DEFAULT_TURBO; break;
                case 2: boot_enabled = DEFAULT_BOOT; break;

                // Boot message
                case 19: str_boot[0] = DEFAULT_BOOT_0; break;
                case 20: str_boot[1] = DEFAULT_BOOT_1; break;
                case 21: str_boot[2] = DEFAULT_BOOT_2; break;
                case 22: str_boot[3] = DEFAULT_BOOT_3; break;

                // LO-value
                case 23: str_lo[0] = DEFAULT_LO_0; break;
                case 24: str_lo[1] = DEFAULT_LO_1; break;
                case 25: str_lo[2] = DEFAULT_LO_2; break;
                case 26: str_lo[3] = DEFAULT_LO_3; break;

                // HI-value
                case 27: str_hi[0] = DEFAULT_HI_0; break;
                case 28: str_hi[1] = DEFAULT_HI_1; break;
                case 29: str_hi[2] = DEFAULT_HI_2; break;
                case 30: str_hi[3] = DEFAULT_HI_3; break;
                
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
            case 0: EEPROM.update(i, ansi_enabled ? 1 : 0); break;
            case 1: EEPROM.update(i, turbo_enabled ? 1 : 0); break;
            case 2: EEPROM.update(i, boot_enabled ? 1 : 0); break;

            // Boot message
            case 19: EEPROM.update(i, str_boot[0]); break;
            case 20: EEPROM.update(i, str_boot[1]); break;
            case 21: EEPROM.update(i, str_boot[2]); break;
            case 22: EEPROM.update(i, str_boot[3]); break;

            // LO-value
            case 23: EEPROM.update(i, str_lo[0]); break;
            case 24: EEPROM.update(i, str_lo[1]); break;
            case 25: EEPROM.update(i, str_lo[2]); break;
            case 26: EEPROM.update(i, str_lo[3]); break;

            // HI-value
            case 27: EEPROM.update(i, str_hi[0]); break;
            case 28: EEPROM.update(i, str_hi[1]); break;
            case 29: EEPROM.update(i, str_hi[2]); break;
            case 30: EEPROM.update(i, str_hi[3]); break;
            
            default:
                EEPROM.update(i, 0);
                break;
        }
    }
    EEPROM.update(STORAGE_CHECKSUM, storage_checksum());
    ansi_highlight_ln((__FlashStringHelper*) STR_DONE);
}

void dump_settings() {
    Serial.print(F("Checksum... "));
    if (checksum_passes()) {
        ansi_highlight_ln(F("OK"));

        for (int i = 0; i < STORAGE_BYTES; i++) {
            if (i < 100) Serial.print(' ');
            if (i < 10) Serial.print(' ');
            Serial.print(i);
            Serial.print(": ");

            uint8_t value = EEPROM.read(i); 
            if (value < 100) Serial.print(' ');
            if (value < 10) Serial.print(' ');
            Serial.println(value);
        }
    }
    else ansi_error_ln(F("ERROR"));
}