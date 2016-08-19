#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE   0 // default layer
#define LOWER  1 // symbols
#define RAISE  2 // numbers
#define EXTRAS 3 // extras
#define GAMING 4 // gaming

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = KEYMAP(
        // Left hand:
        KC_GRV,  KC_1,    KC_2,    KC_3,         KC_4,   KC_5, KC_NO,
        KC_TAB,  KC_Q,    KC_W,    KC_D,         KC_F,   KC_K, KC_NO,
        KC_ESC,  KC_A,    KC_S,    KC_E,         KC_T,   KC_G,
        KC_LSPO, KC_Z,    KC_X,    KC_C,         KC_V,   KC_B, KC_NO,
        KC_LCTL, KC_LGUI, KC_LALT, S(KC_INS),    MO(1),

                                                        KC_NO, KC_NO,
                                                               KC_NO,
                                                KC_SPC, KC_NO, KC_NO,

        // Right hand:
        KC_NO, KC_6, KC_7,  KC_8,    KC_9,    KC_0,      KC_EQL,
        KC_NO, KC_J, KC_U,  KC_R,    KC_L,    KC_SCOLON, KC_MINS,
               KC_Y, KC_N,  KC_I,    KC_O,    KC_H,      KC_QUOT,
        KC_NO, KC_P, KC_M,  KC_COMM, KC_DOT,  KC_SLSH,   KC_RSPC,
                     MO(2), KC_LBRC, KC_RBRC, KC_BSLS,   LT(EXTRAS, KC_BSPC),

        TG(GAMING),KC_NO,
        KC_NO,
        KC_NO, KC_NO, KC_ENT
    ),
    [LOWER] = KEYMAP(
       // Left hand:
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,     KC_NO,
       KC_TILD, KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,     KC_NO,
       KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,   KC_PERC,
       KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_NO,     KC_NO,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS,

                                                         KC_NO, KC_NO,
                                                                KC_NO,
                                                KC_TRNS, KC_NO, KC_NO,

       // Right hand:
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PLUS,
                KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL,
       KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_PSCR,
                         KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_TRNS,

       KC_NO,   KC_NO,
       KC_NO,
       KC_NO,   KC_NO, KC_TRNS
    ),

    [RAISE] = KEYMAP(
       // Left hand:
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NO,
       KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
       KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS,

                                           KC_NO,   KC_NO,
                                                    KC_NO,
                                  KC_TRNS, KC_NO,   KC_NO,

       // Right hand:
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_VOLU,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MPLY, KC_VOLD,
                         KC_TRNS, KC_NO,   KC_NO, TG(GAMING),KC_TRNS,

       KC_NO,   KC_NO,
       KC_NO,
       KC_NO,   KC_NO, KC_TRNS
    ),
    [EXTRAS] = KEYMAP(
       // Left hand:
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   LGUI(KC_1),LGUI(KC_2),LGUI(KC_3),LGUI(KC_4),LGUI(KC_5),
       KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS,

                                           KC_NO,   KC_NO,
                                                    KC_NO,
                                  KC_TRNS, KC_NO,   KC_NO,

       // Right hand:
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                LGUI(KC_6),KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                         KC_TRNS ,KC_NO,   KC_NO,   KC_NO,   KC_TRNS,

       KC_NO,   KC_NO,
       KC_NO,
       KC_NO,   KC_NO, KC_TRNS
    ),
    [GAMING] = KEYMAP(
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
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                         KC_TRNS, KC_NO,   KC_NO,   KC_TRNS, KC_TRNS,

       KC_NO,   KC_NO,
       KC_NO,
       KC_NO,   KC_NO, KC_TRNS
    ),
};

const uint16_t PROGMEM fn_actions[] = {
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
        case BASE:
            ergodox_right_led_1_on();
            break;
        case LOWER:
            ergodox_right_led_2_on();
            break;
        case RAISE:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case EXTRAS:
            ergodox_right_led_3_on();
            break;
        case GAMING:
            ergodox_right_led_1_on();
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
       KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS,

                                           KC_NO,   KC_NO,
                                                    KC_NO,
                                  KC_TRNS, KC_NO,   KC_NO,

       // Right hand:
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                         KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_TRNS,

       KC_NO,   KC_NO,
       KC_NO,
       KC_NO,   KC_NO, KC_TRNS
*/
