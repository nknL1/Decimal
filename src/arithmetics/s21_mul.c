#include "../big_decimal/big_decimal.h"
#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int sign = 0;
  if (get_sign(value_1) != get_sign(value_2)) {
    set_sign(&value_1, 0);
    set_sign(&value_2, 0);
    sign = 1;
  }

  s21_big_decimal big_value_1 = decimal_to_big(value_1),
                  big_value_2 = decimal_to_big(value_2), big_result;
  big_mul(big_value_1, big_value_2, &big_result);

  big_result.sign = sign;

  int error_code = big_to_decimal(big_result, result);

  return error_code;
}