#include "../big_decimal/big_decimal.h"
#include "../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int value_1_sign = get_sign(value_1);
  int value_2_sign = get_sign(value_2);

  if (value_1_sign != value_2_sign) {
    set_sign(&value_2, value_1_sign);
    return s21_add(value_1, value_2, result);
  } else if (value_1_sign == 1 && value_2_sign == 1) {
    set_sign(&value_1, 0);
    set_sign(&value_2, 0);
    return s21_sub(value_2, value_1, result);
  }

  s21_big_decimal big_value_1 = decimal_to_big(value_1),
                  big_value_2 = decimal_to_big(value_2), big_result;

  if (s21_is_greater_or_equal(value_1, value_2)) {
    big_sub(big_value_1, big_value_2, &big_result);
  } else {
    big_sub(big_value_2, big_value_1, &big_result);
    big_result.sign = 1;
  }

  int error_code = big_to_decimal(big_result, result);

  return error_code;
}