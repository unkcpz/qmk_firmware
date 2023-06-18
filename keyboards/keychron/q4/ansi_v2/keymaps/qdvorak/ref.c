#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define QWRT 1 // qwerty
#define SYMB 2 // symbols
#define FNKEYS 3 // function keys

enum custom_keycodes {
  VRSN = SAFE_RANGE,
  RGB_SLD,
  CTRL_Q,
  CMD_Q,
  FULL_RESET,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  =/FN  |   1  |   2  |   3  |   4  |   5  |VolDn |           | VolUp|   6  |   7  |   8  |   9  |   0  |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   '  |   ,  |   .  |   P  |   Y  |  Qw  |           | Sym  |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctl(Q) |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |- or Cmd|
 * |--------+------+------+------+------+------| Hyper|           | Caps |------+------+------+------+------+--------|
 * | LShift |  :/; |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |Z/Alt | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/Qw|Cmd(Q)| Alt  | Left | Right|                                       | Down |  Up  |   [  |   ]  | Rst  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Del  | Home |       | Esc  | App  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | End  |       | PgUp |        |      |
 *                                 | Space|Enter |------|       |------|  Bksp  |Space |
 *                                 |      |      |Cmd(Q)|       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  LT(FNKEYS,KC_EQL), KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_VOLD,
  KC_TAB,            KC_QUOT,     KC_COMM,       KC_DOT,  KC_P,    KC_Y,    TG(QWRT),
  CTRL_Q,            KC_A,        KC_O,          KC_E,    KC_U,    KC_I,
  KC_LSFT,           KC_SCLN,     KC_Q,          KC_J,    KC_K,    KC_X,    ALL_T(KC_NO),
  LT(QWRT,KC_GRV),   CMD_Q,       KC_LALT,       KC_LEFT, KC_RGHT,
                                                                 KC_DEL,  KC_HOME,
                                                                          KC_END,
                                                         KC_SPC, KC_ENT,  CMD_Q,
  // right hand
  KC_VOLU,      KC_6,    KC_7,    KC_8,    KC_9,     KC_0,              KC_BSLS,
  TT(SYMB),     KC_F,    KC_G,    KC_C,    KC_R,     KC_L,              KC_SLSH,
                KC_D,    KC_H,    KC_T,    KC_N,     KC_S,              GUI_T(KC_MINS),
  KC_CAPSLOCK,  KC_B,    KC_M,    KC_W,    KC_V,     ALT_T(KC_Z),       KC_RSFT,
                         KC_DOWN, KC_UP,   KC_LBRC,  KC_RBRC,           FULL_RESET,
  KC_ESC, KC_APP,
  KC_PGUP,
  KC_PGDN, KC_BSPC, KC_SPC
),

/* Keymap 1: QWERTY keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
#define _MODIFIER
[QWRT] = LAYOUT_ergodox(
        // left hand
        KC_TRNS,      KC_TRNS,       KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,      KC_TRNS,
        KC_TRNS,      _MODIFIER(KC_Q),    _MODIFIER(KC_W),  _MODIFIER(KC_E), _MODIFIER(KC_R), _MODIFIER(KC_T),   KC_TRNS,
        KC_TRNS,      _MODIFIER(KC_A),    _MODIFIER(KC_S),  _MODIFIER(KC_D), _MODIFIER(KC_F), _MODIFIER(KC_G),
        KC_TRNS,      _MODIFIER(KC_Z),    _MODIFIER(KC_X),  _MODIFIER(KC_C), _MODIFIER(KC_V), _MODIFIER(KC_B),   KC_TRNS,
        KC_TRNS,      KC_TRNS, KC_TRNS,     KC_TRNS,    KC_TRNS,
                                                               KC_TRNS, KC_TRNS,
                                                                        KC_TRNS,
                                                      KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
             KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,       KC_TRNS,      KC_TRNS,       KC_TRNS,
             KC_TRNS, _MODIFIER(KC_Y), _MODIFIER(KC_U), _MODIFIER(KC_I),    _MODIFIER(KC_O),   _MODIFIER(KC_P),    _MODIFIER(KC_BSLS),
                      _MODIFIER(KC_H), _MODIFIER(KC_J), _MODIFIER(KC_K),    _MODIFIER(KC_L),   _MODIFIER(KC_SCLN), _MODIFIER(KC_QUOT),
             KC_TRNS, _MODIFIER(KC_N), _MODIFIER(KC_M), _MODIFIER(KC_COMM), _MODIFIER(KC_DOT), _MODIFIER(KC_SLSH), KC_TRNS,
                                  KC_TRNS,    KC_TRNS,       KC_TRNS,      KC_TRNS,       KC_TRNS,
             KC_TRNS, KC_TRNS,
             KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS
),
#undef _MODIFIER

/* Keymap 2: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |    . |   0  |   =  | VRSN |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
  KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
  KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
  KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               RGB_MOD, KC_TRNS,
                                                        KC_TRNS,
                                      RGB_VAD, RGB_VAI, KC_TRNS,
  // right hand
  KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TRNS, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
  KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
  KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
  KC_TRNS, KC_DOT,  KC_0,    KC_EQL,  VRSN,
  RGB_TOG, RGB_SLD,
  KC_TRNS,
  KC_TRNS, RGB_HUD, RGB_HUI
),

/* Keymap 3: Function/Arrow key layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |   U  |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |   L  |   D  |   R  |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[FNKEYS] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F12,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS,
  KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
)
};


static bool g_last_qwerty_state = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }

  switch (keycode) {
    case CTRL_Q:
    // TODO(fyhuang): use timer to make caps also function as ESC on short press?
    if (record->event.pressed) {
        register_code(KC_LCTL);
        // Remember state of QWRT layer before key pressed
        g_last_qwerty_state = layer_state & (1<<QWRT);
        layer_on(QWRT);
    }
    else {
        if (!g_last_qwerty_state) {
            layer_off(QWRT);
        }
        unregister_code(KC_LCTL);
    }
    return false;

    case CMD_Q:
    if (record->event.pressed) {
        register_code(KC_LGUI);
        layer_on(QWRT);
    }
    else {
        layer_off(QWRT);
        unregister_code(KC_LGUI);
    }
    return false;

    case FULL_RESET:
    if (!record->event.pressed) {
        // Clear all layers as well
        for (int i = 1; i <= SYMB; i++) {
        layer_off(i);
        }
        clear_keyboard();
    }
    return false;
  }

  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs whenever LED states change
void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        ergodox_right_led_1_on();
    } else {
        ergodox_right_led_1_off();
    }
}

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t layer_state) {
  ergodox_board_led_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  if (layer_state & (1<<QWRT)) {
      ergodox_right_led_3_on();
  }

  if (layer_state & (1<<SYMB)) {
      ergodox_right_led_2_on();
  }

  return layer_state;
};