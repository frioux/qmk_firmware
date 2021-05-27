RGB_MATRIX_EFFECT(off)
RGB_MATRIX_EFFECT(dim)
RGB_MATRIX_EFFECT(bright)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool off(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  rgb_matrix_set_color_all(0, 0, 0);
  return led_max < DRIVER_LED_TOTAL;
}

bool dim(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  rgb_matrix_set_color_all(1, 1, 1);
  return led_max < DRIVER_LED_TOTAL;
}

bool bright(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  rgb_matrix_set_color_all(15, 15, 15);
  return led_max < DRIVER_LED_TOTAL;
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// vim: syntax=c
