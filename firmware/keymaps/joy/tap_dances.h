/* tap-dance state declarations */
enum {
    X_TAPS = 0,
    SINGLE_TAP = 1,
    SINGLE_HOLD = 2,
    DOUBLE_TAP = 3,
    DOUBLE_SINGLE_TAP = 4,
    DOUBLE_HOLD = 5,
};

/* some declaration */
typedef struct {
    bool is_press_action;
    int state;
} tap;

typedef struct {
    uint8_t layer_state;
} user_data_t;

/* Create an instance of 'tap' */
static tap tap_dance_state = {
    .is_press_action = true,
    .state = X_TAPS
};

/* determine tap-dance state */
int cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return X_TAPS;
};

/* tap once to activate layer momentarily like oneshot key OSL();
 * tap twice to toggle layer;
 * hold to activate layer momentarily like MO()
 */
void td_layer_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_dance_state.state = cur_dance(state);
    uint8_t layer_state = ((user_data_t*)user_data)->layer_state;
    switch (tap_dance_state.state) {
        case SINGLE_TAP:
            set_oneshot_layer(layer_state, ONESHOT_START);
            break;
        case SINGLE_HOLD:
            layer_on(layer_state);
            break;
        case DOUBLE_TAP:
            layer_on(layer_state);
            break;
    }
};

void td_layer_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    uint8_t layer_state = ((user_data_t*)user_data)->layer_state;
    switch (tap_dance_state.state) {
        case SINGLE_TAP:
            clear_oneshot_layer_state(ONESHOT_PRESSED);
            break;
        case DOUBLE_TAP:
            break;
        default:
            layer_off(layer_state);
            break;
    }

    tap_dance_state.state = X_TAPS;
};

#define ACTION_TAP_DANCE_FN_ADVANCED_USER(user_fn_on_each_tap, user_fn_on_dance_finished, \
    user_fn_on_dance_reset, user_user_data) { \
   .fn = { user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset }, \
   .user_data = (void*)user_user_data, \
}

/* Tap-Dance declarations */
enum {
    TD_L1,
};

/* tap dance definitions */
qk_tap_dance_action_t tap_dance_actions[] = {
    /* [TD_L1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_l1_finished, td_l1_reset), */
    [TD_L1] = ACTION_TAP_DANCE_FN_ADVANCED_USER(NULL, td_layer_finished, td_layer_reset,
        &((user_data_t){1})),
};
