#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  if (result == NULL) return 1;

  int sign = get_sign(value);
  set_sign(&value, 0);

  s21_truncate(value, result);

  if (get_scale(value) != 0) {
    s21_decimal fractional_part;
    s21_sub(value, *result, &fractional_part);

    s21_decimal frac_five = {{5, 0, 0, 0X00010000}}, one = {{1, 0, 0, 0}};
    if ((s21_is_equal(fractional_part, frac_five) &&
         result->bits[0] % 2 != 0) ||
        s21_is_greater(fractional_part, frac_five)) {
      s21_add(*result, one, result);
    }
  }

  set_sign(result, sign);

  return 0;
}