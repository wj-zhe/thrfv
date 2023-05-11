/*
Copyright 2020 Jz_Wong <@wj-zhe>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* #include "config_common.h" */

/* USB Device descriptor parameter */
#define VENDOR_ID    0x0001
#define PRODUCT_ID   0x0001
#define DEVICE_VER   0x0001
#define MANUFACTURER "jw"
#define PRODUCT      "thrfv"

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 5
#define DIODE_DIRECTION COL2ROW
#define MATRIX_ROW_PINS \
    { D4, E6, B4, B5 }

// wiring of each half
#define MATRIX_COL_PINS \
    { F7, B1, B3, B2, B6 }
/* #define MATRIX_COL_PINS \ */
/*     { B6, B2, B3, B1, F7 } */
// //uncomment this line and comment line above if you need to reverse left-to-right key order

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* /1* Locking resynchronize hack *1/ */
/* #define LOCKING_RESYNC_ENABLE */

/* Serial communication settings */
#define USE_SERIAL
#define SOFT_SERIAL_PIN D2

/* Split side setting */
#define EE_HANDS

/* Top left key on left half */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0
/* Top right key on right half */
#define BOOTMAGIC_LITE_ROW_RIGHT 4
#define BOOTMAGIC_LITE_COLUMN_RIGHT 4

/* Encoder config */
#ifdef ENCODER_ENABLE
#   define ENCODERS_PAD_A { F4 }
#   define ENCODERS_PAD_B { F5 }
#   define ENCODER_RESOLUTIONS { 2 }

/* For 4x encoders you also can assign default position if encoder skips pulses when it changes */
/* direction. For example, if your encoder send high level on both pins by default, define this: */
#   define ENCODER_DEFAULT_POS 0x3

#endif

/* OLED config for split keyboard */
#ifdef OLED_ENABLE
#   define SPLIT_OLED_ENABLE
#   define OLED_BRIGHTNESS 128
#   define OLED_TIMEOUT 8000
#endif

/* per-key backlight options */
#ifdef BACKLIGHT_ENABLE
#   define BACKLIGHT_PIN D3
#endif

/* RGB underglow options */
#ifdef RGBLIGHT_ENABLE
#   define RGB_DI_PIN D3
#   undef RGBLED_NUM
#   define RGBLED_NUM 8
#   define RGBLED_SPLIT {4,4}
#   define RGBLIGHT_SPLIT
#   define RGBLIGHT_SLEEP
/* #define RGBLIGHT_LIMIT_VAL 120 */
/* #define RGBLIGHT_HUE_STEP 10 */
/* #define RGBLIGHT_SAT_STEP 17 */
/* #define RGBLIGHT_VAL_STEP 17 */
#endif

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

