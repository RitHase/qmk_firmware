// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// キーコードを自作
enum custom_keycodes {
    SEND_HACHI = SAFE_RANGE,
    SEND_pon,
    SEND_seto,
    SEND_natsu,
    SEND_bab,
    SEND_ran,
    SEND_hate,
    SEND_arj
};

// キー処理関数
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SEND_HACHI:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_GRAVE) SS_UP(X_LALT)
                SS_DELAY(100)
                "ha"
                SS_DELAY(50)
                "cc"
                SS_DELAY(50)
                "ha"
                SS_DELAY(50)
                "nn"
                SS_DELAY(100)
                SS_TAP(X_F7)
                SS_DOWN(X_LALT) SS_TAP(X_GRAVE) SS_UP(X_LALT)
                SS_DELAY(100)
                SS_TAP(X_ENTER)
            );
            }
            return false;
        case SEND_pon:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_GRAVE) SS_UP(X_LALT)
                SS_DELAY(100)
                "pon"
                SS_DELAY(50)
                "zu"
                SS_DELAY(50)
                "ya"
                SS_DELAY(50)
                "ro"
                SS_DELAY(50)
                "u"
                SS_DELAY(100)
                SS_DOWN(X_LALT) SS_TAP(X_GRAVE) SS_UP(X_LALT)
                SS_DELAY(100)
                SS_TAP(X_ENTER)
            );
            }
            return false;
        case SEND_seto:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_GRAVE) SS_UP(X_LALT)
                SS_DELAY(100)
                "se"
                SS_DELAY(50)
                "to"
                SS_DELAY(50)
                "asa"
                SS_DELAY(20)
                "hi"
                SS_DELAY(100)
                SS_DOWN(X_LALT) SS_TAP(X_GRAVE) SS_UP(X_LALT)
                SS_DELAY(100)
                SS_TAP(X_ENTER)
            );
            }
            return false;
        case SEND_natsu:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_GRAVE) SS_UP(X_LALT)
                SS_DELAY(100)
                "na"
                SS_DELAY(20)
                "tu"
                SS_DELAY(20)
                "pyo"
                SS_DELAY(20)
                "nn"
                SS_DELAY(100)
                SS_DOWN(X_LALT) SS_TAP(X_GRAVE) SS_UP(X_LALT)
                SS_DELAY(100)
                SS_TAP(X_ENTER)
            );
            }
            return false;
        case SEND_bab:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_GRAVE) SS_UP(X_LALT)
                SS_DELAY(100)
                "ba"
                SS_DELAY(50)
                "bu"
                SS_DELAY(50)
                "ru"
                SS_DELAY(50)
                "ke-"
                SS_DELAY(50)
                "ki"
                SS_DELAY(100)
                SS_TAP(X_F7)
                SS_DOWN(X_LALT) SS_TAP(X_GRAVE) SS_UP(X_LALT)
                SS_DELAY(100)
                SS_TAP(X_ENTER)
            );
            }
            return false;
        case SEND_ran:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_GRAVE) SS_UP(X_LALT)
                SS_DELAY(100)
                "mi"
                SS_DELAY(50)
                "sa"
                SS_DELAY(50)
                "to"
                SS_DELAY(50)
                "ra"
                SS_DELAY(50)
                "nn"
                SS_DELAY(100)
                SS_DOWN(X_LALT) SS_TAP(X_GRAVE) SS_UP(X_LALT)
                SS_DELAY(100)
                SS_TAP(X_ENTER)
            );
            }
            return false;
        case SEND_hate:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_GRAVE) SS_UP(X_LALT)
                SS_DELAY(100)
                "ha"
                SS_DELAY(50)
                "te"
                SS_DELAY(50)
                "na"
                SS_DELAY(100)
                SS_DOWN(X_LALT) SS_TAP(X_GRAVE) SS_UP(X_LALT)
                SS_DELAY(100)
                SS_TAP(X_ENTER)
            );
            }
            return false;
        case SEND_arj:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_GRAVE) SS_UP(X_LALT)
                SS_DELAY(100)
                "a"
                SS_DELAY(100)
                "ru"
                SS_DELAY(50)
                "ja"
                SS_DELAY(50)
                "nn"
                SS_TAP(X_F7) 
                SS_DELAY(100)
                SS_DOWN(X_LALT) SS_TAP(X_GRAVE) SS_UP(X_LALT)
                SS_DELAY(100)
                SS_TAP(X_ENTER)
            );
            }
            return false;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        SEND_HACHI, SEND_pon, SEND_seto, SEND_natsu,
        SEND_bab,   SEND_ran, SEND_hate, SEND_arj
    )
};