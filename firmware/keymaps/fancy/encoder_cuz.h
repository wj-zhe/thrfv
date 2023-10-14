/* Inspired by: https://www.reddit.com/r/olkb/comments/n6hd8v/comment/gx9rg64/?utm_source=share&utm_medium=web2x&context=3 */

enum custom_keycodes {
    ENC_TG = SAFE_RANGE,
};

#define NUM_ENC_MODES 2
enum encoder_modes {
    VOLUME,
    SCROLL,
    /* ZOOM, */
};

static uint8_t encoder_mode = VOLUME;

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*   switch (keycode) { */
/*       case ENC_TOGG: */
/*           if (record->event.pressed) { */
/*               // Go to the next encoder mode, looping around to the start. */
/*               encoder_mode = (encoder_mode + 1) % NUM_ENC_MODES; */
/*           } */
/*       break; */
/*   } */
/* } */

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        switch(encoder_mode) {
            case VOLUME:				
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            break;

            case SCROLL:
                if (clockwise) {
                    tap_code(KC_WH_D);
                } else {
                    tap_code(KC_WH_U);
                }
            break;

            /* case ZOOM: */
            /*     if (clockwise) { */
            /*         tap_code(LCTRL(KC_PPLUS));  // CTRL+NumpadPlus */
            /*     } else { */
            /*         tap_code(LCTRL(KC_PMNS));   // CTRL+NumpadMinus */
            /*     } */
            /* break; */

        }
    } 
    return false;
}
