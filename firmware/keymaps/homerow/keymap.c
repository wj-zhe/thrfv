
#include QMK_KEYBOARD_H

#ifdef CONSOLE_ENABLE
#   include "print.h"
#endif

#ifdef ENCODER_ENABLE
#   include "encoder_cuz.h"
#endif

#ifdef OLED_ENABLE
#   include "thrfv_oled.h"
#endif

#ifdef TAP_DANCE_ENABLE
#   include "tap_dances.h"
#endif

#ifdef COMBO_ENABLE
/* #   include "combo.h" */
#   include "g/keymap_combo.h"
#endif

// A 'transparent' key code (that falls back to the layers below it).
#define ___ KC_TRANSPARENT

/* keymaps */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
            LGUI_T(KC_Q), KC_W, KC_E, KC_R, KC_T,                   KC_Y, KC_U, KC_I, KC_O, LGUI_T(KC_P),
            KC_A, KC_S, KC_D, LCTL_T(KC_F), KC_G,                   KC_H, LCTL_T(KC_J), KC_K, KC_L, KC_SCLN,
            LSFT_T(KC_Z), KC_X, KC_C, KC_V, LT(3,KC_B),             KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH),
            KC_NO, KC_NO, LT(2,KC_TAB), LALT_T(KC_BSPC), ENC_TG,    KC_BTN1, LALT_T(KC_SPC), TD(TD_L1), KC_NO, KC_NO

            ),

    [1] = LAYOUT(
            KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
            KC_1, KC_2, KC_3, LCTL_T(KC_4), KC_5,            KC_6, LCTL_T(KC_7), KC_8, KC_9, KC_0,
            KC_LSFT, KC_NO, KC_NO, KC_EQL, LT(3,KC_PLUS),    KC_UNDS, KC_MINS, ___, ___, ___,
                                 ___, ___, ___, ___, ___,    KC_BTN2, ___, ___, ___, ___

            ),

    [2] = LAYOUT(
            LGUI_T(KC_F9), KC_F10, KC_F11, KC_F12, KC_BTN2,    KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_LGUI,
            KC_F5, KC_F6, KC_F7, LCTL_T(KC_F8), KC_BTN1,       KC_LEFT, LCTL_T(KC_DOWN), KC_UP, KC_RGHT, KC_CAPS,
            LSFT_T(KC_F1), KC_F2, KC_F3, KC_F4, TO(3),         KC_MUTE, KC_VOLD, KC_VOLU, KC_WBAK, RSFT_T(KC_WFWD),
                ___, ___, TG(2), LALT_T(KC_PSCR), ___,         KC_BTN2, LALT_T(KC_MPLY), TD(TD_MD_NX_PR), ___, ___

            ),

    [3] = LAYOUT(
            KC_NO, KC_HOME, KC_UP, KC_PGUP, KC_NO,          KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS,
            KC_END, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,    KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS,
            KC_NO, KC_NO, KC_NO, KC_NO, TG(3),              KC_P0, KC_P1, KC_P2, KC_P3, KC_DOT,
                    ___, ___, KC_NO, ___, ___,              ___, KC_BSPC, KC_ESC, ___, ___

            ),

};

/* Tapping-term per key */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LALT_T(KC_BSPC):
        case RSFT_T(KC_SLSH):
            return 115;
        case LALT_T(KC_SPC):
        case LSFT_T(KC_Z): case LSFT_T(KC_F1):
            return 135;
        default:
            return TAPPING_TERM;
    }
};

/* /1* per-key ignore mod tap configuration *1/ */
/* bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) { */
/*     switch (keycode) { */
/*         // Do not force the mod-tap key press to be handled as a modifier */
/*         // if any other key was pressed while the mod-tap key is held down. */
/*         case LGUI_T(KC_Q): case LGUI_T(KC_P): */
/*         case LCTL_T(KC_A): case LCTL_T(KC_SCLN): */
/*         case LCTL_T(KC_F5): */
/*         case LSFT_T(KC_Z): */
/*         case LSFT_T(KC_COMM): case RSFT_T(KC_DOT): */
/*         case LSFT_T(KC_F1): */
/*             return true; */
/*         // Force the mod-tap key press to be handled as a modifier if any */
/*         // other key was pressed while the mod-tap key is held down. */
/*         default: */
/*             return false; */
/*     } */
/* }; */

/* /1* per-key permissive setting *1/ */
/* bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) { */
/*     switch (keycode) { */
/*         case LT(2,KC_TAB): */
/*         case RSFT_T(KC_SLSH): case LSFT_T(KC_Z): case LSFT_T(KC_F1): */
/*         case LALT_T(KC_BSPC): case LALT_T(KC_SPC): */
/*             // Immediately select the hold action when another key is tapped. */
/*             return true; */
/*         default: */
/*             // Do not select the hold action when another key is tapped. */
/*             return false; */
/*     } */
/* } */

/* Custom keycode */
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
        case KC_BSPC: case LALT_T(KC_BSPC): case LGUI_T(KC_BSPC): {
            // Initialize a boolean variable that keeps track
            // of the delete key status: registered or not?
            static bool delkey_registered;
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_SHIFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_DEL);
                    // Update the boolean variable to reflect the status of KC_DEL
                    delkey_registered = true;
                    // Reapplying modifier state so that the held shift key(s)
                    // still work even after having tapped the Backspace/Delete key.
                    set_mods(mod_state);
                    return false;
                }
            } else { // on release of KC_BSPC
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
            // Let QMK process the KC_BSPC keycode as usual outside of shift
            return true;
        };

        case KC_ESC: case LALT_T(KC_ESC): case LGUI_T(KC_ESC): {
            // Detect the activation of only SHIFT key
            if ( (get_mods() & MOD_BIT(KC_LALT)) == MOD_BIT(KC_LALT) ) {
                if (record->event.pressed) {
                    tap_code(KC_GRV);
                }
                else {
                    unregister_code(KC_GRV);
                }
                // Do not let QMK process the keycode further
                return false;
            }
            // Else, let QMK process the standard keycode as usual
            return true;
        };

        case ENC_TG: {
            if (record->event.pressed) {
                // Go to the next encoder mode, looping around to the start.
                encoder_mode = (encoder_mode + 1) % NUM_ENC_MODES;
            }
            return false;
        };
    };

    return true;
};

/* /1* encoder mapping *1/ */
/* #if defined(ENCODER_MAP_ENABLE) */
/* const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = { */
/*     [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), }, */
/*     [1] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN),}, */
/*     /1* [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), }, *1/ */
/*     [3] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN),}, */
/* }; */
/* #endif */

/* for debug mode only */
#ifdef CONSOLE_ENABLE
    dprintf("KL: kc: 0x%04X, col: %u, row: %u,"
        "pressed: %b, time: %u, interrupt: %b, count: %u\n",
        keycode, record->event.key.col, record->event.key.row,
        record->event.pressed, record->event.time,
        record->tap.interrupted, record->tap.count
        );
#endif 

