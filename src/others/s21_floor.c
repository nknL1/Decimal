#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  if (result == NULL) return 1;

  s21_truncate(value, result);
  if (get_sign(value) == 1 && get_scale(value) != 0) {
    s21_decimal one = {{1, 0, 0, 0}};
    s21_sub(*result, one, result);
  }

  return 0;
}