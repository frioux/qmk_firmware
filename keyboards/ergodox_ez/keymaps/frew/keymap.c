#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,
    FREW,
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  esc   |   1  |   2  |   3  |   4  |   5  |   6  |           |      |   7  |   8  |   9  |   0  |   -  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   ~    |   Q  |   W  |   E  |   R  |   T  |   \  |           |  [   |   Y  |   U  |   I  |   O  |   P  |   ]    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Tab   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Pause| Prev | Next |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LCtrl| LAlt |       | RAlt |RCtrl   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | BkSp | Win  |------|       |------| Enter  |Space |
 *                                 |      |      |      |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_ESC,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_6,                  KC_NO  ,     KC_7,    KC_8,    KC_9,    KC_0,              KC_MINS,        KC_EQL ,
  KC_TILD,         KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    KC_BSLS,              KC_LBRC ,     KC_Y,    KC_U,    KC_I,    KC_O,              KC_P,           KC_RBRC,
  KC_TAB ,    LT(1,KC_A),        KC_S,          KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,   LT(1,KC_SCLN), KC_QUOT,
  KC_LSFT,         KC_Z,        KC_X,          KC_C,    KC_V,    KC_B,    KC_NO ,                  KC_NO,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_MPLY, KC_MPRV,          KC_MNXT, KC_NO  , KC_NO  ,                                              KC_NO,   KC_NO  , KC_NO  , KC_NO  , KC_NO   ,

                                                           KC_LCTL, KC_LALT,                KC_RALT, KC_RCTL,
                                                                    KC_HOME,                KC_PGUP,
                                                          KC_BSPC, KC_LGUI, KC_NO,          KC_PGDN, KC_ENT, KC_SPC
),
/* Keymap 1: fREW Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |  TEENSY |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12   |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      | WORD |      |      |      |      |           |      | COPY |      |      |      |PASTE |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      | CUT  |      |      |------|           |------| LEFT | DOWN | UP   | RIGHT|      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         | UNDO | DEL  |      |      | BWORD|      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |VERSION|      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[FREW] = LAYOUT_ergodox_pretty(
  // left hand
  QK_BOOT,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,     KC_TRNS, KC_F7,   KC_F8,  KC_F9,  KC_F10,     KC_F11, KC_F12,
  KC_TRNS, KC_TRNS, A(KC_W), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,G(KC_C),KC_TRNS, KC_TRNS,  KC_TRNS, G(KC_V), KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, G(KC_X), KC_TRNS, KC_TRNS,              KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS,
  KC_TRNS, G(KC_Z), KC_DEL,  KC_TRNS, KC_TRNS, A(KC_B), KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     VRSN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
            break;
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

    return state;
};
