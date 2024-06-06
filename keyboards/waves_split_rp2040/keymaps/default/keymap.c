#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┐ ┌───┬───┬───┬───┬───┬───┬───┐
     * │esc│ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ │ 6 │ 7 │ 8 │ 9 │ 0 │ - │bsp│
     * ├───┴───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┼───┤
     * │  tab  │ q │ w │ e │ r │ t │ │ y │ u │ i │ o │ p │ [ │ ] │
     * ├───────┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┴───┤
     * │ caps  │ a │ s │ d │ f │ g │ │ h │ j │ k │ l │ ; │ enter │
     * ├───────┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───────┤
     * │ shift │ z │ x │ c │ v │ b │ │ n │ m │ , │ . │ / │ shift │
     * ├───┬───┼───┼───┼───┴───┴───┤ ├───┴───┴───┼───┼───┼───┬───┤
     * │fn │ctl│alt│hom│   space   │ │   space   │hom│alt│ = │ \ │
     * └───┴───┴───┴───┴───────────┘ └───────────┴───┴───┴───┴───┘
     * 
     * LAYER 1
     * ┌───┬───┬───┬───┬───┬───┬───┐ ┌───┬───┬───┬───┬───┬───┬───┐
     * │EE │   │   │   │   │   │   │ │ 7 │ 8 │ 9 │   │   │ = │del│
     * ├───┴───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┼───┤
     * │       │   │   │   │   │   │ │ 4 │ 5 │ 6 │   │   │   │ \ │
     * ├───────┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┴───┤
     * │       │   │   │   │   │   │ │ 1 │ 2 │ 3 │   │   │ enter │
     * ├───────┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───────┤
     * │       │   │   │   │   │   │ │ 0 │ . │num│   │ ↑ │ shift │
     * ├───┬───┼───┼───┼───┴───┴───┤ ├───┴───┴───┼───┼───┼───┬───┤
     * │   │   │   │   │           │ │           │ ← │ ↓ │ → │   │
     * └───┴───┴───┴───┴───────────┘ └───────────┴───┴───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_ESC, KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_BSPC,
        KC_TAB,         KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,
        KC_CAPS,        KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_QUOT,KC_ENT,
        KC_LSFT,        KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,
        MO(1),  KC_LCTL,KC_LALT,KC_LGUI,        KC_SPC,                 KC_SPC,         KC_RGUI,KC_RALT,KC_EQL, KC_BSLS
    ),

    // layer with:
    //  things that got shoved out of the layout: equals, semicolon, backslash
    //  arrow keys
    [1] = LAYOUT(
        EE_CLR, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_P7,  KC_P8,  KC_P9,  KC_TRNS,KC_TRNS,KC_EQL, KC_DEL,
        KC_TRNS,        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_P4,  KC_P5,  KC_P6,  KC_TRNS,KC_TRNS,KC_TRNS,KC_BSLS,
        KC_TRNS,        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_P1,  KC_P2,  KC_P3,  KC_TRNS,KC_SCLN,KC_TRNS,
        KC_TRNS,        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_P0,  KC_PDOT,KC_NUM, KC_TRNS,KC_UP,  KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,        KC_TRNS,                KC_TRNS,        KC_LEFT,KC_DOWN,KC_RGHT,KC_TRNS
    )
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}