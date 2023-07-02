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

/* Split side setting */
#define MASTER_RIGHT

/* /1* OLED config for split keyboard *1/ */
/* #define #define SPLIT_OLED_ENABLE */

/* Encoder config */
#ifdef ENCODER_ENABLE
#   define ENCODERS_PAD_A { F4 }
#   define ENCODERS_PAD_B { F5 }
#   define ENCODERS_PAD_A_RIGHT { F4 }
#   define ENCODERS_PAD_B_RIGHT { F5 }
#endif

/* Point device config for split keyboard */
#if (defined POINTING_DEVICE_ENABLE && POINTING_DEVICE_DRIVER == analog_joystick)
#   define ANALOG_JOYSTICK_X_AXIS_PIN F6
#   define ANALOG_JOYSTICK_Y_AXIS_PIN D7
#endif

#ifdef THUMBSTICK_ENABLE
#    define THUMBSTICK_FLIP_X
#    define THUMBSTICK_PIN_X F6
#    define THUMBSTICK_PIN_Y D7
#endif

/* tap-hold option */
#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY
/* #define RETRO_TAPPING_PER_KEY */

/* #define COMBO_TERM 40 */
#define COMBO_STRICT_TIMER
/* #define COMBO_ONLY_FROM_LAYER 0 */


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

