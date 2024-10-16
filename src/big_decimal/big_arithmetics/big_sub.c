#include "../big_decimal.h"

// substracting two positive(!) big_decimal numbers
// value_1 > value_2 !!!
void big_sub(s21_big_decimal value_1, s21_big_decimal value_2,
             s21_big_decimal *result) {
  big_set_zero(result);
  rescale(&value_1, &value_2);

  int borrow = 0;
  for (int i = 0; i < 6; i++) {
    unsigned long long dif =
        value_1.bits[i] - ((unsigned long long)value_2.bits[i] + borrow);
    if (value_1.bits[i] < ((unsigned long long)value_2.bits[i] + borrow)) {
      dif += (1ULL << 32);
      borrow = 1;
    } else {
      borrow = 0;
    }
    result->bits[i] = (unsigned int)dif;
  }

  result->scale = value_1.scale;
}