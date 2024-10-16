#include "../big_decimal.h"

void big_div(s21_big_decimal value_1, s21_big_decimal value_2,
             s21_big_decimal *result) {
  s21_big_decimal remainder, quotient, value_1_copy, value_2_copy;

  big_copy(&value_1_copy, value_1);
  big_copy(&value_2_copy, value_2);
  multiply_by_ten(&value_1_copy, value_1_copy.scale);
  multiply_by_ten(&value_2_copy, value_2_copy.scale);

  big_set_zero(result);

  int quotient_scale = 0, end_flag = 0;

  do {
    big_set_zero(&remainder);
    big_set_zero(&quotient);

    for (int i = 127; i >= 0; i--) {
      big_bitwise_shift_left(&remainder, 1);
      big_set_bit(&remainder, 0, big_get_bit(value_1_copy, i));

      if (big_is_greater_or_equal(remainder, value_2_copy)) {
        s21_big_decimal tmp;
        big_sub(remainder, value_2_copy, &tmp);
        big_copy(&remainder, tmp);

        big_set_bit(&quotient, i, 1);
      }
    }

    quotient.scale = quotient_scale;

    s21_big_decimal tmp;
    big_add(*result, quotient, &tmp);
    big_copy(result, tmp);

    if (result->bits[3] == 0 && !big_is_zero(remainder)) {
      big_copy(&value_1_copy, remainder);
      multiply_by_ten(&value_1_copy, 1);

      add_zeroes(result, 1);
      quotient_scale++;
    } else {
      end_flag = 1;
    }
  } while (!end_flag);

  if (value_2.scale - value_1.scale > 0)
    multiply_by_ten(result, value_2.scale - value_1.scale);
  else if (value_2.scale - value_1.scale < 0)
    result->scale += value_1.scale - value_2.scale;

  // delete_trailing_zeroes(result);
}