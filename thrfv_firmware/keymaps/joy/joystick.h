/* #include "analog.h" */
#include "print.h"
/* #include "thumbstick.h" */

/* bool useJoystick = true; */

void keyboard_post_init_user(void) {
    //analog.c ----------- JOYSTICK INIT
    /* setPinOutput(F1); */
    /* setPinOutput(F4); */
    /* setPinInput(F7); */
    /* setPinInput(F6); */
    setPinInputHigh(C6);

    /* if(rightSideLayout) */
    /* { */
    /*     writePinHigh(F1); */
    /*     x_startAnalogValue = analogReadPin(F7); */
    /*     y_startAnalogValue = analogReadPin(F6); */
    /* } */
    /* else */
    /* { */
    /*     writePinLow(F1); */
    /*     y_startAnalogValue = analogReadPin(F7); */
    /*     x_startAnalogValue = analogReadPin(F6); */
    /* } */
}

uint8_t pin_state = 0;
void housekeeping_task_user(void) {
    pin_state = readPin(C6);
#ifdef CONSOLE_ENABLE
    debug_enable=true;
    uprintf("%d: \n", pin_state);
#endif

    /* if(useJoystick) */
    /* { */
    /*     left_right_or_up_down = !left_right_or_up_down; //ONLY CHECKING ONCE EVERY OTHER LOOP UP-DOWN OR LEFT-RIGHT */
        
    /*     writePinHigh(F4); */

    /*     if(left_right_or_up_down) */
    /*     { */
    /*         if(rightSideLayout) */
    /*         { */
    /*             y_analogValue = analogReadPin(F6); */
    /*             y_diff = y_startAnalogValue - y_analogValue; */
    /*         } */
    /*         else */
    /*         { */
    /*             y_analogValue = analogReadPin(F7); */
    /*             y_diff = y_analogValue - y_startAnalogValue; */
    /*         } */

    /*         if(y_diff>y_thrs && !b_right) */
    /*         { */
    /*             register_code(KC_RIGHT); */
    /*             b_right = true; */
    /*         } */
    /*         else if(y_diff<=y_thrs && b_right) */ 
    /*         { */
    /*             unregister_code(KC_RIGHT); */
    /*             b_right = false; */
    /*         } */

    /*         if(y_diff<-y_thrs && !b_left) */
    /*         { */
    /*             register_code(KC_LEFT); */
    /*             b_left = true; */ 
    /*         } */
    /*         else if(y_diff>=-y_thrs && b_left) */
    /*         { */
    /*             unregister_code(KC_LEFT); */
    /*             b_left = false; */
    /*         } */
    /*     } */
    /*     else */
    /*     { */
    /*         if(rightSideLayout) */
    /*         { */
    /*             x_analogValue = analogReadPin(F7); */
    /*             x_diff = x_startAnalogValue - x_analogValue; */
    /*         } */
    /*         else */
    /*         { */
    /*             x_analogValue = analogReadPin(F6); */
    /*             x_diff = x_startAnalogValue - x_analogValue; */
    /*         } */
            
    /*         if(x_diff>x_thrs && !b_up) */
    /*         { */
    /*             register_code(KC_UP); */
    /*             b_up = true; */
    /*         } */
    /*         else if(x_diff<=x_thrs && b_up) */
    /*         { */
    /*             unregister_code(KC_UP); */
    /*             b_up = false; */
    /*         } */

    /*         if(x_diff<-x_thrs && !b_down) */
    /*         { */
    /*             register_code(KC_DOWN); */
    /*             b_down = true; */ 
    /*         } */
    /*         else if(x_diff>=-x_thrs && b_down) */
    /*         { */
    /*             unregister_code(KC_DOWN); */
    /*             b_down = false; */
    /*         } */
    /*     } */
    /* } */
    /* else */
    /* { */
    /*     writePinLow(F4); */

    /*     if(b_up)    { unregister_code(KC_UP); b_up = false; } */
    /*     if(b_down)  { unregister_code(KC_DOWN); b_down = false; } */
    /*     if(b_right) { unregister_code(KC_RIGHT); b_right= false; } */
    /*     if(b_left)  { unregister_code(KC_LEFT); b_left = false; } */
    /* } */
}
