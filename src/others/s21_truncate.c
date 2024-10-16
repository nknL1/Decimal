#include "../big_decimal/big_decimal.h"
#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  if (result == NULL) return 1;

  s21_big_decimal big_value = decimal_to_big(value);

  int scale = get_scale(value);

  divide_by_ten(&big_value, scale);

  big_to_decimal(big_value, result);

  return 0;
}