#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE   0 // default layer
#define NORMAN 1 // norman
#define NOTHING 4 // for copy-pasta

#define KC_SESC MT(MOD_LCTL, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = KEYMAP(
        // Left hand:
        KC_GRV,  KC_1,    KC_2,    KC_3,         KC_4,   KC_5,   KC_NO,
        KC_TAB,  KC_Q,    KC_W,    KC_E,         KC_R,   KC_T,   KC_LCBR,
        KC_SESC, KC_A,    KC_S,    KC_D,         KC_F,   KC_G,
        KC_LSPO, KC_Z,    KC_X,    KC_C,         KC_V,   KC_B,   KC_LABK,
        KC_LCTL, KC_LALT, KC_LGUI, KC_NO,        KC_NO,

                                                         KC_MPLY,KC_VOLU,
                                                                 KC_VOLD,
                                                 KC_SPC, KC_ENT, LGUI(KC_V),

        // Right hand:
        KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_EQL,
        KC_RCBR, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_MINS,
                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCOLON, KC_QUOT,
        KC_RABK, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   KC_RSPC,
                          KC_NO,   KC_LBRC, KC_RBRC, KC_BSLS,   TG(NORMAN),

        KC_HOME, KC_END,
        KC_PGUP,
        KC_PGDN, KC_TRNS, KC_BSPC
// FIXME I've got no arrows now!!!
    ),
    [NORMAN] = KEYMAP(
       // Left hand:
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_Q,    KC_W,    KC_D,    KC_F,    KC_K,    KC_TRNS,
       KC_TRNS, KC_A,    KC_S,    KC_E,    KC_T,    KC_G,
       KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                                    KC_TRNS, KC_TRNS,
                                                             KC_TRNS,
                                           KC_TRNS, KC_TRNS, KC_TRNS,

       // Right hand:
       KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
       KC_TRNS, KC_J,      KC_U,      KC_R,    KC_L,      KC_SCOLON, KC_TRNS,
                KC_Y,      KC_N,      KC_I,    KC_O,      KC_H,      KC_TRNS,
       KC_TRNS, KC_P,      KC_M,      KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
                           KC_TRNS,   KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,

       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS,   KC_TRNS
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    ergodox_right_led_1_on();
  }

  return true;
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    /* uint8_t layer = biton32(layer_state); */

    /* ergodox_board_led_off(); */
    /* ergodox_right_led_1_off(); */
    /* ergodox_right_led_2_off(); */
    /* ergodox_right_led_3_off(); */

    /* switch (layer) { */
    /* } */
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
