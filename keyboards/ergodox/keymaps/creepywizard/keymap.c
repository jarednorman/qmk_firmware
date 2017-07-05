#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE   0 // default layer
#define QWERTY 1 // gaming
#define FUNCTION  2 // symbols
#define EXTRAS 3 // gaming
#define NOTHING 4 // for copy-pasta

#define KC_SESC LT(EXTRAS, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = KEYMAP(
        // Left hand:
        KC_GRV,  KC_1,    KC_2,    KC_3,         KC_4,   KC_5,   KC_NO,
        KC_TAB,  KC_Q,    KC_W,    KC_D,         KC_F,   KC_K,   KC_LCBR,
        KC_SESC, KC_A,    KC_S,    KC_E,         KC_T,   KC_G,
        KC_LSPO, KC_Z,    KC_X,    KC_C,         KC_V,   KC_B,   KC_LABK,
        KC_LCTL, KC_LALT, KC_LGUI, KC_NO,        KC_NO,

                                                         KC_MPLY,KC_VOLU,
                                                                 KC_VOLD,
                                                 KC_SPC, KC_ENT, LSFT(KC_INS),

        // Right hand:
        KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_EQL,
        KC_RCBR, KC_J,    KC_U,    KC_R,    KC_L,    KC_SCOLON, KC_MINS,
                 KC_Y,    KC_N,    KC_I,    KC_O,    KC_H,      KC_QUOT,
        KC_RABK, KC_P,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   KC_RSPC,
                          KC_NO,   KC_LBRC, KC_RBRC, KC_BSLS,   TG(QWERTY),

        KC_HOME, KC_END,
        KC_PGUP,
        KC_PGDN, MO(FUNCTION), KC_BSPC
    ),
    [QWERTY] = KEYMAP(
       // Left hand:
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_TRNS,
       KC_TRNS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
       KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                                    KC_TRNS, KC_TRNS,
                                                             KC_TRNS,
                                           KC_SPC,  KC_TRNS, KC_TRNS,

       // Right hand:
       KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
       KC_TRNS, KC_Y,      KC_U,      KC_I,    KC_O,      KC_P,      KC_TRNS,
                KC_H,      KC_J,      KC_K,    KC_L,      KC_SCOLON, KC_TRNS,
       KC_TRNS, KC_N,      KC_M,      KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
                           KC_TRNS,   KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,

       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS,   KC_TRNS
    ),
    [FUNCTION] = KEYMAP(
       // Left hand:
       KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
       KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
       KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
       KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_NO,

                                                         KC_NO,    KC_NO,
                                                                   KC_NO,
                                               KC_NO,    KC_NO,    KC_NO,

       // Right hand:
       KC_NO,   KC_NO,     KC_NO,     KC_NO,   KC_NO,     KC_NO,     KC_NO,
       KC_NO,   KC_NO,     KC_NO,     KC_NO,   KC_NO,     KC_NO,     KC_NO,
                KC_NO,     KC_NO,     KC_NO,   KC_NO,     KC_NO,     KC_NO,
       KC_NO,   KC_NO,     KC_NO,     KC_NO,   KC_NO,     KC_NO,     KC_TRNS,
                           KC_NO,     KC_NO,   KC_NO,     KC_NO,     KC_NO,

       KC_NO,   KC_NO,
       KC_NO,
       KC_NO,   KC_NO,     KC_TRNS
    ),
    [EXTRAS] = KEYMAP(
       // Left hand:
       KC_NO,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
       KC_NO,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
       KC_NO,    LGUI(KC_1),LGUI(KC_2),LGUI(KC_3),LGUI(KC_4),LGUI(KC_5),
       KC_TRNS,  KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
       KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_NO,     KC_TRNS,

                                                             KC_NO,     KC_NO,
                                                                        KC_NO,
                                                  KC_TRNS,   KC_NO,     KC_NO,

       // Right hand:
       KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                LGUI(KC_6),KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                           KC_TRNS ,KC_NO,   KC_NO,   KC_NO,   KC_TRNS,

       KC_NO,   KC_NO,
       KC_NO,
       KC_NO,   KC_NO, KC_TRNS
    ),
    [NOTHING] = KEYMAP(
       // Left hand:
       KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
       KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
       KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
       KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_NO,

                                                         KC_NO,    KC_NO,
                                                                   KC_NO,
                                               KC_NO,    KC_NO,    KC_NO,

       // Right hand:
       KC_NO,   KC_NO,     KC_NO,     KC_NO,   KC_NO,     KC_NO,     KC_NO,
       KC_NO,   KC_NO,     KC_NO,     KC_NO,   KC_NO,     KC_NO,     KC_NO,
                KC_NO,     KC_NO,     KC_NO,   KC_NO,     KC_NO,     KC_NO,
       KC_NO,   KC_NO,     KC_NO,     KC_NO,   KC_NO,     KC_NO,     KC_TRNS,
                           KC_NO,     KC_NO,   KC_NO,     KC_NO,     KC_NO,

       KC_NO,   KC_NO,
       KC_NO,
       KC_NO,   KC_NO,     KC_TRNS
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
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
        case FUNCTION:
            ergodox_right_led_1_on();
            break;
        case EXTRAS:
            ergodox_right_led_2_on();
            break;
        case QWERTY:
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
