#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int error = 0;
  int sign = get_sign(src);
  int scale = get_scale(src);
  if (scale < 0 || scale > 28) {
    error = 1;
  } else {
    double fake_dst = 0.0;
    for (int i = 0; i < 96; i++) {
      if (get_bit(src, i)) {
        fake_dst += pow(2.0, (double)i);
      }
    }
    while (scale > 0) {
      fake_dst /= 10;
      scale--;
    }
    *dst = fake_dst;
    if (sign) *dst = -*dst;
  }
  return error;
}