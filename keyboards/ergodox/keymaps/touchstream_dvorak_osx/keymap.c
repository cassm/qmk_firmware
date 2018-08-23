// Netable differences vs. the default firmware for the ErgoDox:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | CapLck |   1  |   2  |   3  |   4  |   5  |ScrlLk|           | NumLk|   6  |   7  |   8  |   9  |   0  |   §    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   '  |   ,  |   .  |   P  |   Y  | Sym  |           | Sym  |   F  |   G  |   C  |   R  |   L  |   `    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |   \    |
 * |--------+------+------+------+------+------| Hyper|           | Hyper|------+------+------+------+------+--------|
 * | LShift |   ;  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |PrtScr|  Fn  | Ctrl | Alt  | Cmd  |                                       |  Cmd | Ctrl | Alt  |  Fn  |Popup |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        | Home | End  |       | Left | Right  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | PgUp |       |  Up  |        |      |
 *                                 | Bksp | Del  |------|       |------| Enter  |Space |
 *                                 |      |      | PgDn |       |  Dn  |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*

//FIXME: fix fn functionality on mac. Need to update vid and pid. Patch diff at https://gist.github.com/fauxpark/010dcf5d6377c3a71ac98ce37414c6c4
//FIXME: add numpad layer

[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_LCAP,        KC_1,     KC_2,    KC_3,    KC_4,    KC_5,   KC_SLCK,
        KC_TAB,         KC_QUOT,  KC_COMM, KC_DOT,  KC_P,    KC_Y,   MO(SYMB),
        KC_ESC,         KC_A,     KC_O,    KC_E,    KC_U,    KC_I,
        KC_LSFT,        KC_SCLN,  KC_Q,    KC_J,    KC_K,    KC_X,   ALL_T(KC_NO),
        KC_PSCR,        KC_NO,    KC_LCTL, KC_LALT, KC_LGUI,
                                                    KC_HOME, KC_END,
                                                             KC_PGUP,
                                           KC_BSPC, KC_DEL,  KC_PGDN,
        // right hand
             KC_TRNS,     KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_GRAVE,
             MO(SYMB),    KC_F,   KC_G,   KC_C,   KC_R,    KC_L,    KC_NUBS,
                          KC_D,   KC_H,   KC_T,   KC_N,    KC_S,    KC_BSLS,
             ALL_T(KC_NO),KC_B,   KC_M,   KC_W,   KC_V,    KC_Z,    KC_RSFT,
                                  KC_RGUI,KC_RALT,KC_RCTRL,KC_NO,   KC_APP,
             KC_LEFT,     KC_RGHT,
             KC_UP,
             KC_DOWN,     KC_ENTER, KC_SPC
    ),

//FIXME get multikey macros working

/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |Reset |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  //  |  {   |  }   |  [   |  ]   |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|  ->  |  -   |  _   |  (   |  )   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  !=  |  +   |  =   |  |   |  \   |        |
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
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       RESET,   KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_TRNS, KC_LCBR,KC_RCBR, KC_LBRC, KC_RBRC, KC_F12,
                KC_TRNS, KC_MINS,KC_UNDS, KC_LPRN, KC_RPRN, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_PLUS,KC_EQL,  KC_PIPE, KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
      break;
  }
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox.
    case SYMB:
      ergodox_right_led_1_on();
      break;
    default:
      // none
      break;
  }
};
