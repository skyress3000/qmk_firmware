// Copyright 2023 Ray Wendt (@skyress3000)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "waves_split_rp2040.h"
#include "split_util.h"

const is31_led PROGMEM g_is31_leds[LED_MATRIX_LED_COUNT] = {
/* Refer to IS31 manual for these locations
 *    driver
 *    |  LED address
 *    |  | */
    { 0, C1_1 },
    { 0, C1_2 },
    { 0, C1_3 },
    { 0, C1_4 },
    { 0, C1_5 },
    { 0, C1_6 },
    { 0, C1_7 },
    { 0, C2_1 },
    { 0, C2_3 },
    { 0, C2_4 },
    { 0, C2_5 },
    { 0, C2_6 },
    { 0, C2_7 },
    { 0, C3_1 },
    { 0, C3_3 },
    { 0, C3_4 },
    { 0, C3_5 },
    { 0, C3_6 },
    { 0, C3_7 },
    { 0, C4_1 },
    { 0, C4_3 },
    { 0, C4_4 },
    { 0, C4_5 },
    { 0, C4_6 },
    { 0, C4_7 },
    { 0, C5_1 },
    { 0, C5_2 },
    { 0, C5_3 },
    { 0, C5_4 },
    { 0, C5_6 },

    { 0, C1_1 },
    { 0, C1_2 },
    { 0, C1_3 },
    { 0, C1_4 },
    { 0, C1_5 },
    { 0, C1_6 },
    { 0, C1_7 },
    { 0, C2_1 },
    { 0, C2_2 },
    { 0, C2_3 },
    { 0, C2_4 },
    { 0, C2_5 },
    { 0, C2_6 },
    { 0, C2_7 },
    { 0, C3_1 },
    { 0, C3_2 },
    { 0, C3_3 },
    { 0, C3_4 },
    { 0, C3_5 },
    { 0, C3_6 },
    { 0, C4_1 },
    { 0, C4_2 },
    { 0, C4_3 },
    { 0, C4_4 },
    { 0, C4_5 },
    { 0, C4_6 },
    { 0, C5_2 },
    { 0, C5_4 },
    { 0, C5_5 },
    { 0, C5_6 },
    { 0, C5_7 },
};

led_config_t g_led_config = { {
  // Key Matrix to LED Index
  { 0,  1,      2,  3,  4,      5,  6      },
  { 7,  NO_LED, 8,  9,  10,     11, 12     },
  { 13, NO_LED, 14, 15, 16,     17, 18     },
  { 19, NO_LED, 20, 21, 22,     23, 24     },
  { 25, 26,     27, 28, NO_LED, 29, NO_LED },

  { 30,     31, 32,     33, 34, 35, 36     },
  { 37,     38, 39,     40, 41, 42, 43     },
  { 44,     45, 46,     47, 48, 49, NO_LED },
  { 50,     51, 52,     53, 54, 55, NO_LED },
  { NO_LED, 56, NO_LED, 57, 58, 59, 60     }
}, {
  // LED Index to Physical Position
  // going from x 8->216 easier math than 0->224 and should look about the same
  { 8,0  }, { 24,0  }, { 40,0  }, { 56,0  }, { 72,0  }, { 88,0  }, { 104,0  },   
  { 16,16 },           { 40,16 }, { 56,16 }, { 72,16 }, { 88,16 }, { 104,16 },   
  { 16,32 },           { 40,32 }, { 56,32 }, { 72,32 }, { 88,32 }, { 104,32 },   
  { 16,48 },           { 40,48 }, { 56,48 }, { 72,48 }, { 88,48 }, { 104,48 },   
  { 8,64 }, { 24,64 }, { 40,64 }, { 56,64 },            { 88,64 },                

  { 120,0  }, { 136,0  }, { 152,0  }, { 168,0  }, { 184,0  }, { 200,0  }, { 216,0  }, 
  { 120,16 }, { 136,16 }, { 152,16 }, { 168,16 }, { 184,16 }, { 200,16 }, { 216,16 }, 
  { 120,32 }, { 136,32 }, { 152,32 }, { 168,32 }, { 184,32 }, { 208,32 },
  { 120,48 }, { 136,48 }, { 152,48 }, { 168,48 }, { 184,48 }, { 208,48 },
              { 136,64 },             { 168,64 }, { 184,64 }, { 200,64 }, { 216,64 }, 
}, {
  // LED Index to Flag
  4, 4, 4, 4, 4, 4, 4,   
  4,    4, 4, 4, 4, 4,   
  4,    4, 4, 4, 4, 4,   
  4,    4, 4, 4, 4, 4,   
  4, 4, 4, 4,    4,      

  4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,   
  4, 4, 4, 4, 4, 4,   
     4,    4, 4, 4, 4 
} };

// layer_state_t layer_state_set_kb(layer_state_t state) {
//    if(get_highest_layer(state) == 1) {
//       led_matrix_mode(LED_MATRIX_CUSTOM_highlight_layer_keys);
//    } else {
//       // default effect on bottom layer
//       led_matrix_mode(LED_MATRIX_BREATHING);
//    }

//    return state;
// }

bool led_matrix_indicators_kb(void) {
    if (!led_matrix_indicators_user()) {
        return false;
    }

    if(IS_LAYER_ON(1)) {
        led_matrix_set_value_all(0x00);

        if(!isLeftHand) {
            led_matrix_set_value(30, 0xFF);
            led_matrix_set_value(31, 0xFF);
            led_matrix_set_value(32, 0xFF);
            led_matrix_set_value(35, 0xFF);

            led_matrix_set_value(37, 0xFF);
            led_matrix_set_value(38, 0xFF);
            led_matrix_set_value(39, 0xFF);

            led_matrix_set_value(44, 0xFF);
            led_matrix_set_value(45, 0xFF);
            led_matrix_set_value(46, 0xFF);
            led_matrix_set_value(48, 0xFF);

            led_matrix_set_value(50, 0xFF);
            led_matrix_set_value(54, 0xFF);

            led_matrix_set_value(57, 0xFF);
            led_matrix_set_value(58, 0xFF);
            led_matrix_set_value(59, 0xFF);
        }
    }

    return true;
}