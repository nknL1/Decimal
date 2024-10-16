#include "../big_decimal.h"

// adding two positive(!) big_decimal numbers
void big_add(s21_big_decimal value_1, s21_big_decimal value_2,
             s21_big_decimal *result) {
  big_set_zero(result);
  rescale(&value_1, &value_2);

  int carry = 0;

  for (int i = 0; i < 6; i++) {
    unsigned long long sum =
        (unsigned long long)value_1.bits[i] + value_2.bits[i] + carry;
    result->bits[i] = sum & 0xFFFFFFFF;
    carry = sum >> 32;
  }

  result->scale = value_1.scale;
}