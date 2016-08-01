#include "planck.h"
#include "eeconfig.h"
#include "audio.h"

float tone_startup[][2] = SONG(
  Q__NOTE(_A3),

  Q__NOTE(_E4),
  Q__NOTE(_D4),
  Q__NOTE(_E4),
  Q__NOTE(_G4),

  W__NOTE(_E4),

  H__NOTE(_REST),
  Q__NOTE(_REST),
  Q__NOTE(_A3),

  Q__NOTE(_E4),
  Q__NOTE(_D4),
  Q__NOTE(_E4),
  Q__NOTE(_A4),

  W__NOTE(_E4),

  H__NOTE(_REST),
  Q__NOTE(_REST),
  Q__NOTE(_C5),

  Q__NOTE(_B4),
  Q__NOTE(_A4),
  Q__NOTE(_G4),
  Q__NOTE(_A4),

  W__NOTE(_E4),

  H__NOTE(_REST),
  Q__NOTE(_REST),
  Q__NOTE(_C5),

  Q__NOTE(_B4),
  Q__NOTE(_A4),
  Q__NOTE(_G4),
  Q__NOTE(_B4),

  W__NOTE(_E4),

  H__NOTE(_REST),
  Q__NOTE(_REST),
  Q__NOTE(_A3),

  Q__NOTE(_E4),
  Q__NOTE(_D4),
  Q__NOTE(_E4),
  Q__NOTE(_A4),

  W__NOTE(_E4),

  H__NOTE(_REST),
  Q__NOTE(_REST),
  Q__NOTE(_A4),

  W__NOTE(_E4)
);

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Norman
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   D  |   F  |   K  |   J  |   U  |   R  |   L  |   ;  |   _  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   E  |   T  |   G  |   Y  |   N  |   I  |   O  |   H  |   '  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   P  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Mod  | Alt  |Paste |Lower |Space |Enter |Raise |   [  |   ]  |   \  |Backsp|
 * `-----------------------------------------------------------------------------------'
 */
[0] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_D,    KC_F,    KC_K,    KC_J,    KC_U,    KC_R,    KC_L,    KC_SCLN, KC_MINS},
  {KC_ESC,  KC_A,    KC_S,    KC_E,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_I,    KC_O,    KC_H,    KC_QUOT},
  {KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_P,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC},
  {KC_LCTL, KC_LGUI, KC_LALT, S(KC_INS), MO(1), KC_SPC,  KC_ENT,  MO(2),   KC_LBRC, KC_RBRC, KC_BSLS, LT(4, KC_BSPC)}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |      |      |      |      |      |      |      |      |      |      |   +  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   =  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Trans |      |      |      |      | PgUp | PgDn | Left | Down |  Up  |Right |PrScr |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Trans |Trans |Trans |      |Trans |Trans |Trans |Trans |      |      |      |Trans |
 * `-----------------------------------------------------------------------------------'
 */
[1] = {
  {KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PLUS},
  {KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL},
  {_______, M(1),    XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PSCR},
  {_______, _______, _______, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Vol+ |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Trans |      |      |      |      |      |      |      |      |      | Play | Vol- |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Trans |Trans |Trans |      |Trans |Trans |Trans |Trans |      |      |      |Trans |
 * `-----------------------------------------------------------------------------------'
 */
[2] = {
  {KC_F1,   KC_F1,   KC_F1,   KC_F1,   KC_F1,   KC_F1,   KC_F1,   KC_F1,   KC_F1,   KC_F1,   KC_F1,   KC_F12},
  {XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_VOLU},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, KC_VOLD},
  {_______, _______, _______, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, TG(3),   _______}
},

/* Overwatch
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   1  |      |      |      |      |      | Exit |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   2  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   H  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |Space |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[3] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_1,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_2,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_H,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX}
},

/* Extras
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[4] = {
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______}
},

};

void matrix_init_user(void) {
   startup_user();
}

void startup_user() {
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch(id) {
    case 1:
      if (record->event.pressed) {
        PLAY_NOTE_ARRAY(tone_startup, false, 0);
      }
      break;
  }
  return MACRO_NONE;
};
