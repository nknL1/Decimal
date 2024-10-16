#include "../big_decimal/big_decimal.h"
#include "../s21_decimal.h"

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  s21_big_decimal big_value_1 = decimal_to_big(value_1),
                  big_value_2 = decimal_to_big(value_2);

  return big_is_greater(big_value_1, big_value_2);
}