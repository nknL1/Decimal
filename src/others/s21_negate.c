#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  copy(result, value);

  set_sign(result, 1 - get_sign(value));

  return 0;
}