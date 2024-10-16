#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error = 0;
  int sign = get_sign(src);
  int scale = get_scale(src);
  src.bits[SCALE] = 0;
  s21_decimal turned;
  s21_truncate(src, &turned);
  if (scale == 0 && (turned.bits[1] != 0 || turned.bits[2] != 0)) {
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
    if ((unsigned)fake_dst == 2147483648 && sign == 1) {
      *dst = -2147483648;
    } else if (fake_dst > s21_MAXINT) {
      error = 1;
    } else {
      *dst = (int)fake_dst;
      if (sign) {
        *dst = -*dst;
      }
    }
  }
  return error;
}
