#include "big_decimal.h"

s21_big_decimal decimal_to_big(s21_decimal d) {
  s21_big_decimal result;
  big_set_zero(&result);

  for (int i = 0; i < 3; i++) result.bits[i] = d.bits[i];
  result.scale = get_scale(d);
  result.sign = get_sign(d);

  return result;
}

int big_to_decimal(s21_big_decimal big_dec, s21_decimal *result) {
  int error_code = 0;

  bank_rounding(&big_dec);
  if (big_dec.bits[5] || big_dec.bits[4] || big_dec.bits[3]) {
    error_code = big_dec.sign ? 2 : 1;
  } else if (big_dec.scale > 28)
    big_dec.scale = 0;

  if (error_code == 0) {
    set_zero(result);

    for (int i = 0; i < 3; i++) result->bits[i] = big_dec.bits[i];

    set_scale(result, big_dec.scale);
    set_sign(result, big_dec.sign);
  }

  return error_code;
}