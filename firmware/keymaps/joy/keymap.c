/* Keymap for thrfv */

#include QMK_KEYBOARD_H
/* #include "print.h" */
#include "combo.h"
#include "tap_dances.h"
#include "joystick.h"

/* keymaps */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
            LGUI_T(KC_Q), KC_W, KC_E, KC_R, KC_T,
            KC_Y, KC_U, KC_I, KC_O, LGUI_T(KC_P),

            LCTL_T(KC_A), KC_S, KC_D, KC_F, KC_G,
            KC_H, KC_J, KC_K, KC_L, LCTL_T(KC_SCLN),

            LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B,
            KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH),

            KC_MS_BTN1, KC_MS_BTN2, LT(2,KC_TAB), LALT_T(KC_BSPC), KC_KB_MUTE,
            LGUI_T(KC_ENT), LALT_T(KC_SPC), TD(TD_L1), KC_NO, KC_1

            ),

    [1] = LAYOUT(
            KC_LGUI, KC_EXLM, KC_AT, KC_HASH, KC_NO,
            KC_SLSH, KC_7, KC_8, KC_9, RGUI_T(KC_MINS),

            KC_LCTL, KC_DLR, KC_PERC, KC_CIRC, KC_ESC,
            KC_ASTR, KC_4, KC_5, KC_6, RCTL_T(KC_PLUS),

            LSFT_T(KC_COMM), KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
            KC_0, KC_1, KC_2, KC_3, RSFT_T(KC_DOT),

            _______, _______, TO(2), _______, _______,
            _______, KC_BSPC, TG(1), _______, _______

            ),

    [2] = LAYOUT(
            LGUI_T(KC_F9), KC_F10, KC_F11, KC_F12, KC_PSCR,
            KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_LGUI,

            LCTL_T(KC_F5), KC_F6, KC_F7, KC_F8, KC_NO,
            KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_LCTL,

            LSFT_T(KC_F1), KC_F2, KC_F3, KC_F4, TO(3),
            KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, KC_RSFT,

            _______, _______, TG(2), _______, _______,
            _______, KC_SPC, TG(1), _______, _______

            ),

    [3] = LAYOUT(
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS,

            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS,

            KC_NO, KC_NO, RESET, KC_NO, TG(3),
            KC_P0, KC_P1, KC_P2, KC_P3, KC_DOT,

            _______, _______, TG(2), _______, _______,
            _______, KC_SPC, TG(1), _______, _______

            ),

};

/* Tapping-term per key */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_Z): case LSFT_T(KC_F1):
        case RSFT_T(KC_SLSH):
        /* case LGUI_T(KC_Q): case LGUI_T(KC_P): */
            return 135;
        default:
            return TAPPING_TERM;
    }
};

/* per-key ignore mod tap configuration */
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Do not force the mod-tap key press to be handled as a modifier
        // if any other key was pressed while the mod-tap key is held down.
        case LGUI_T(KC_Q): case LGUI_T(KC_P):
        case RGUI_T(KC_MINS):
        case LCTL_T(KC_A): case LCTL_T(KC_SCLN):
        case RCTL_T(KC_PLUS):
        case LCTL_T(KC_F5):
        case LSFT_T(KC_Z):
        case LSFT_T(KC_COMM): case RSFT_T(KC_DOT):
        case LSFT_T(KC_F1):
            return true;
        // Force the mod-tap key press to be handled as a modifier if any
        // other key was pressed while the mod-tap key is held down.
        default:
            return false;
    }
};

/* /1* per-key permissive setting *1/ */
/* bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) { */
/*     switch (keycode) { */
/*         case TD(TD_L1): */
/*         case LT(2,KC_TAB): */
/*         /1* case LALT_T(KC_BSPC): case LALT_T(KC_SPC): *1/ */
/*         case RSFT_T(KC_SLSH): */ 
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
    };

    /* /1* for debug mode only *1/ */
    /* #ifdef CONSOLE_ENABLE */
    /*     dprintf("KL: kc: 0x%04X, col: %u, row: %u," */
    /*         "pressed: %b, time: %u, interrupt: %b, count: %u\n", */
    /*         keycode, record->event.key.col, record->event.key.row, */
    /*         record->event.pressed, record->event.time, */
    /*         record->tap.interrupted, record->tap.count */
    /*         ); */
    /* #endif */ 

    return true;
};

