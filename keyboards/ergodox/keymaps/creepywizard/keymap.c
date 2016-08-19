#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define XTRA 2 // extras
#define GMZZ 3 // gaming

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = KEYMAP(
        // Left hand:
        KC_GRV,  KC_1,    KC_2,    KC_3,         KC_4,   KC_5, KC_NO,
        KC_TAB,  KC_Q,    KC_W,    KC_D,         KC_F,   KC_K, KC_NO,
        KC_ESC,  KC_A,    KC_S,    KC_E,         KC_T,   KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_C,         KC_V,   KC_B, KC_NO,
        KC_LCTL, KC_LGUI, KC_LALT, LSFT(KC_INS), KC_BSPC,

                                                        KC_NO, KC_NO,
                                                               KC_NO,
                                                KC_SPC, KC_NO, KC_NO,

        // Right hand:
        KC_NO, KC_6, KC_7,  KC_8,    KC_9,    KC_0,      KC_EQL,
        KC_NO, KC_J, KC_U,  KC_R,    KC_L,    KC_SCOLON, KC_MINS,
               KC_Y, KC_N,  KC_I,    KC_O,    KC_H,      KC_QUOT,
        KC_NO, KC_P, KC_M,  KC_COMM, KC_DOT,  KC_SLSH,   KC_LSHIFT,
                     MO(1), KC_LBRC, KC_RBRC, KC_BSLS,   MO(2),

        TG(GMZZ),KC_NO,
        KC_NO,
        KC_NO, KC_NO, KC_ENT
    ),
    [SYMB] = KEYMAP(
       // Left hand:
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,     KC_NO,
       KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,   KC_PERC,   KC_NO,
       KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,
       KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_PGDOWN, KC_NO,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS,

                                                         KC_NO, KC_NO,
                                                                KC_NO,
                                                KC_TRNS, KC_NO, KC_NO,

       // Right hand:
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
       KC_NO,   KC_PGUP, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_TRNS,
                         KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,

       KC_NO,   KC_NO,
       KC_NO,
       KC_NO,   KC_NO, KC_TRNS
    ),

    [XTRA] = KEYMAP(
       // Left hand:
       KC_NO,   KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
       KC_F1,   KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_NO,
       KC_PSCR, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5),
       KC_TRNS, KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
       KC_TRNS, KC_TRNS,    KC_TRNS,    KC_NO,      KC_TRNS,

                                                                   KC_NO,   KC_NO,
                                                                            KC_NO,
                                                          KC_TRNS, KC_NO,   KC_NO,

       // Right hand:
       KC_NO,   KC_NO,      KC_NO,      KC_NO,      KC_NO,       KC_NO,     KC_NO,
       KC_NO,   KC_F7,      KC_F8,      KC_F9,      KC_F10,      KC_F11,    KC_F12,
                LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9),  KC_HOME,   KC_NO,
       KC_NO,   KC_NO,      KC_NO,      KC_NO,      KC_NO,       KC_END,    KC_TRNS,
                            KC_NO,      KC_MPLY,    KC__VOLDOWN, KC__VOLUP, KC_TRNS,

       KC_NO, KC_NO,
       KC_NO,
       KC_NO, KC_NO, KC_TRNS
    ),
    [GMZZ] = KEYMAP(
       // Left hand:
       KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
       KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_7,
       KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
       KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_8,
       KC_LCTL, KC_LGUI, KC_LALT, KC_NO,   KC_NO,

                                           KC_9,    KC_0,
                                                    KC_NO,
                                   KC_SPC, KC_E,    KC_Q,

       // Right hand:
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   TG(GMZZ),
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

       KC_NO,   KC_NO,
       KC_NO,
       KC_NO,   KC_NO, KC_NO
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
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
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
      // TODO: Make this relevant to the ErgoDox EZ.
        case 0:
            ergodox_right_led_1_on();
            break;
        case 1:
            ergodox_right_led_2_on();
            break;
        case 2:
            ergodox_right_led_3_on();
            break;
        case 3:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};

/* Blank Layer
       // Left hand:
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

                                           KC_NO,   KC_NO,
                                                    KC_NO,
                                    KC_NO, KC_NO,   KC_NO,

       // Right hand:
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

       KC_NO,   KC_NO,
       KC_NO,
       KC_NO,   KC_NO, KC_NO
*/
