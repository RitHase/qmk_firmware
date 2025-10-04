// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#define LY_0 TG(_DEFO)
#define LY_1 LT(_NUM,KC_MINS)
#define LY_2 LT(_SYNBOL,KC_D)

#define KCS_MINUI MT(KC_LGUI,KC_BSPC)

enum custom_keycodes {
    CTRL_C = SAFE_RANGE,  // 任意のカスタムキ-
    CTRL_V,
    CTRL_A
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTRL_C:
            if (record->event.pressed) {
                // Ctrl + C を送信
                register_code(KC_LGUI);
                tap_code(KC_C);
            } else {
                unregister_code(KC_LGUI);
            }
            return false;  // 他の処理を行わない
        
        case CTRL_V:
            if (record->event.pressed) {
                // Ctrl + C を送信
                register_code(KC_LGUI);
                tap_code(KC_V);
            } else {
                unregister_code(KC_LGUI);
            }
            return false;  // 他の処理を行わない
        
        case CTRL_A:
            if (record->event.pressed) {
                // Ctrl + C を送信
                register_code(KC_LGUI);
                tap_code(KC_A);
            } else {
                unregister_code(KC_LGUI);
            }
            return false;  // 他の処理を行わない
    }
    return true;
};

enum layer_number {
  _DEFO=0,
  _NUM,
  _SYNBOL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Alt│
      *               └───┤Bsp├───┐   ┌───┤Ent├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [_DEFO] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_NUHS,
        KC_TAB,  KC_A,    KC_S,    LY_2,    SFT_T(KC_F),    KC_G,                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        CTL_T(KC_LNG1), KC_Z,    KC_X,    KC_C,  KC_V,    KC_B,                        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_UNDS,
        CTRL_A, CTRL_C, CTRL_V ,GUI_T(KC_LNG1), KC_SPC,  LY_1,                     SFT_T(KC_ENT),  KC_BSPC, KC_LNG2, KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [_NUM] = LAYOUT(
        KC_TAB,  _______,    KC_0,    KC_1,    KC_2,    KC_3,                            KC_EQL,     KC_MINS,    KC_GRAVE,    KC_O,    KC_P,    KC_UNDS,
        KC_LCTL, KC_A,    KC_S,    KC_4,    KC_5,    KC_6,                               KC_LBRC,    KC_RBRC,   KC_UNDS,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LALT, KC_Z,    KC_X,    KC_7,    KC_8,    KC_9,                               KC_SLSH,    KC_BSLS,    KC_COMM, KC_DOT,  KC_UP,  KC_UNDS,
        CTRL_A, CTRL_C, CTRL_V,    GUI_T(KC_ESC), KC_SPC,  KC_LSFT,                      SFT_T(KC_ENT),  KC_BSPC, MS_BTN2, KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [_SYNBOL] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               MS_BTN1,    MS_UP,   MS_BTN2, KC_O,    MS_WHLD, KC_NUBS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    SFT_T(KC_F),    KC_G,                               MS_LEFT,    MS_BTN3, MS_RGHT, MS_WHLL, MS_WHLU, MS_WHLR,
        KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               MS_BTN4,    MS_DOWN, MS_BTN5, KC_DOT,  KC_UP, KC_MINS,
        CTRL_A, CTRL_C, CTRL_V,    GUI_T(KC_ESC), KC_SPC,  KC_LSFT,               MS_BTN1, MS_BTN2, MS_BTN2, KC_LEFT, KC_DOWN, KC_RIGHT
    )
};
