#include "../big_decimal/big_decimal.h"
#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (get_sign(value_1) != get_sign(value_2)) {
    if (get_sign(value_1)) {
      set_sign(&value_1, 0);
      return s21_sub(value_2, value_1, result);
    } else {
      set_sign(&value_2, 0);
      return s21_sub(value_1, value_2, result);
    }
  }

  s21_big_decimal big_value_1 = decimal_to_big(value_1),
                  big_value_2 = decimal_to_big(value_2), big_result;

  big_add(big_value_1, big_value_2, &big_result);

  big_result.sign = get_sign(value_1);

  int error_code = big_to_decimal(big_result, result);

  return error_code;
}