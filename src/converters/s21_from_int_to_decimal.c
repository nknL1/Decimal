#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  clear_decimal(dst);
  int error = 0;
  if ((src == s21_INF) || (src == s21_N_INF) || (src == s21_NaN) ||
      (src > s21_MAXINT)) {
    error = 1;
  } else {
    if (src < 0) {
      dst->bits[SCALE] = 1 << 31;
      dst->bits[FIRST] = -src;
    } else {
      dst->bits[FIRST] = src;
    }
  }
  return error;
}