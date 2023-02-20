/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// clang-format off

enum custom_keycodes {
    CTRL_Q,
    CMD_Q,
};

enum layers {
    MAC_BASE,
    WIN_BASE,
    QWERT,
    _FN1,
    _FN2,
    _FN3
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,------------------------------------------------------------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   [  |   ]  |   Bksp  |
 * |--------+------+------+------+------+------+------|------+------+------+------+------+----------------|
 * | Tab    |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |   /  |   =  |   \     |
 * |--------+------+------+------+------+------|---------------+------+------+------+------+--------------|
 * | Ctl(Q) |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  -   |    Enter       |
 * |--------+------+------+------+------+------|-------------|------+------+------+------+------+---------|
 * |    LShift     |  :/; |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |    RShift      |
 * `--------+------+------+------+------+------------------+------+------+------+------+------------------'
 * | _FN1   | LWin |  LAlt|                       Space                    | RAlt | _FN1 |  _FN3 |  RCtrl | 
 * `------------------------------------'-----------------------------------------------------------------.
 */
    [MAC_BASE] = LAYOUT_ansi_61(
        KC_ESC,   KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_LBRC,  KC_RBRC,  KC_BSPC,
        KC_TAB,   KC_QUOT,  KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,     KC_SLSH,  KC_EQL,   KC_BSLS,
        KC_LCTL,  KC_A,     KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,     KC_MINS,             KC_ENT,
        KC_LSFT,            KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,        KC_Z,            KC_RSFT,
        MO(_FN1), KC_LOPT,    CMD_Q,                            KC_SPC,                             KC_RCMD,  MO(_FN1), MO(QWERT), KC_CAPS
    ),

    [WIN_BASE] = LAYOUT_ansi_61(
        KC_ESC,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        KC_CAPS, KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,             KC_ENT,
        KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT,
        KC_LCTL, KC_LWIN,  KC_LALT,                            KC_SPC,                             KC_RALT,  MO(_FN2), MO(_FN3), KC_RCTL
    ),
/* Keymap 2: QWERT layer
 *
 * ,------------------------------------------------------------------------------------------------------.
 * |        |      |      |      |      |      |      |      |      |      |      |      |      |         |
 * |--------+------+------+------+------+------+------|------+------+------+------+------+----------------|
 * |        |   Q  |  W   |  E   |  R   |  T   |  Y   |  U   |   I  |  O   |   P  |   [  |  ]   |    \    |
 * |--------+------+------+------+------+------|---------------+------+------+------+------+--------------|
 * |        |   A  |  S   |  D   |  F   |  G   |  H   |  J   |   K  |   L  |   ;  |   '  |                |
 * |--------+------+------+------+------+------|-------------|------+------+------+------+------+---------|
 * |               |  Z   |  X   |  C   |  V   |  B   |  N   |   M  |   ,  |   .  |   /  |                |
 * `--------+------+------+------+------+------------------+------+------+------+------+------------------'
 * |        |      |      |                                                |      |      |       |        | 
 * `------------------------------------'-----------------------------------------------------------------.
 */
    [QWERT] = LAYOUT_ansi_61(
        _______, _______, _______,  _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
        _______,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        _______,  KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,           _______,
        _______,            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,           _______,
        _______, _______, _______,                            _______,                              _______, _______, _______, _______
    ), 
/* Keymap 2: FN1 layer
 *
 * ,------------------------------------------------------------------------------------------------------.
 * |        |      |      |      |      |      |      |      |      |      |      |      |      |         |
 * |--------+------+------+------+------+------+------|------+------+------+------+------+----------------|
 * |        |      |  _U  |      |      |      |      |      |      |      |      |      |      |         |
 * |--------+------+------+------+------+------|---------------+------+------+------+------+--------------|
 * |        |  _L  |  _D  |  _R  |      |      |      |      |  _U  |      |      |      |                |
 * |--------+------+------+------+------+------|-------------|------+------+------+------+------+---------|
 * |               | `/~  |      |      |      |      |      |  _L  | _D   |  _R  |      |                |
 * `--------+------+------+------+------+------------------+------+------+------+------+------------------'
 * |        |      |      |                                                |      |      |       |        | 
 * `------------------------------------'-----------------------------------------------------------------.
 */
    [_FN1] = LAYOUT_ansi_61(
        _______, _______, _______,  _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
        _______, _______,   KC_UP,  _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______,    KC_UP, _______, _______, _______,          _______,
        _______,           KC_GRV,  _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______,          _______,
        _______, _______, _______,                            _______,                              _______, _______, _______, _______
    ), 

    [_FN2] = LAYOUT_ansi_61(
        KC_GRV,  KC_BRID,  KC_BRIU, KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  RGB_MOD,
        RGB_TOG, RGB_MOD,  RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, KC_APP,  KC_SCRL, KC_INS,   KC_PGUP,  KC_HOME,  _______,
        _______, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, KC_UP,   KC_PSCR, KC_PGDN,  KC_END,             _______,
        _______,           _______, _______, _______, _______, _______, NK_TOGG, KC_LEFT, KC_DOWN, KC_RIGHT, KC_DEL,             _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______
    ),
/* Keymap 2: FN1 layer
 *
 * ,------------------------------------------------------------------------------------------------------.
 * |        |      |      |      |      |      |      |      |      |      |      |      |      |         |
 * |--------+------+------+------+------+------+------|------+------+------+------+------+----------------|
 * |        |      |      |      |      |      |      |      |      |      |      |      |      |         |
 * |--------+------+------+------+------+------|---------------+------+------+------+------+--------------|
 * |        |      |      |      |      |      |      |      |      |      |      |      |                |
 * |--------+------+------+------+------+------|-------------|------+------+------+------+------+---------|
 * |               |      |      |      |      |      |      |      |      |      |      |                |
 * `--------+------+------+------+------+------------------+------+------+------+------+------------------'
 * |        |      |      |                                                |      |      |       |        | 
 * `------------------------------------'-----------------------------------------------------------------.
 */
    [_FN3] = LAYOUT_ansi_61(
        KC_TILD, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,
        RGB_TOG, RGB_MOD,  RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______,  _______,            _______,
        _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CTRL_Q:
      if (record->event.pressed) {
          register_code(KC_LCTL);
          layer_on(QWERT);
      }
      else {
          layer_off(QWERT);
          unregister_code(KC_LCTL);
      }
      return false;

    case CMD_Q:
      if (record->event.pressed) {
          register_code(KC_LCMD);
          layer_on(QWERT);
      }
      else {
          layer_off(QWERT);
          unregister_code(KC_LCMD);
      }
      return false;
  }

  return true;
}