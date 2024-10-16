#include "../big_decimal.h"

// multiplying two positive(!) big_decimal numbers
void big_mul(s21_big_decimal value_1, s21_big_decimal value_2,
             s21_big_decimal *result) {
  big_set_zero(result);

  for (int i = 0; i < 6; ++i) {
    unsigned long long partial_sum = 0;
    for (int j = 0; j <= i; ++j) {
      partial_sum += (unsigned long long)value_1.bits[j] * value_2.bits[i - j];
    }

    unsigned long long tmp = partial_sum + (unsigned long long)result->bits[i];

    result->bits[i] = (unsigned int)tmp;
    result->bits[i + 1] += (unsigned int)(tmp >> 32);
  }

  result->scale = value_1.scale + value_2.scale;
}