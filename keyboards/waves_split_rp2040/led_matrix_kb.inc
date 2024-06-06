LED_MATRIX_EFFECT(highlight_layer_keys)

#ifdef LED_MATRIX_CUSTOM_EFFECT_IMPLS

static bool my_cool_effect(effect_params_t* params) {
	LED_MATRIX_USE_LIMITS(led_min, led_max);
  	
  	led_matrix_set_value(31, 0xFF);
    led_matrix_set_value(32, 0xFF);
    led_matrix_set_value(33, 0xFF);
    led_matrix_set_value(36, 0xFF);

    led_matrix_set_value(38, 0xFF);
    led_matrix_set_value(39, 0xFF);
    led_matrix_set_value(40, 0xFF);

    led_matrix_set_value(45, 0xFF);
    led_matrix_set_value(46, 0xFF);
    led_matrix_set_value(47, 0xFF);
    led_matrix_set_value(49, 0xFF);

    led_matrix_set_value(51, 0xFF);
    led_matrix_set_value(55, 0xFF);

    led_matrix_set_value(58, 0xFF);
    led_matrix_set_value(59, 0xFF);
    led_matrix_set_value(60, 0xFF);

	return led_matrix_check_finished_leds(led_max);
}


#endif // LED_MATRIX_CUSTOM_EFFECT_IMPLS