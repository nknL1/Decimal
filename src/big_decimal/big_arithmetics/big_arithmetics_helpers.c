#include "../big_decimal.h"

void bank_rounding(s21_big_decimal *dec) {
  s21_big_decimal dec_copy;
  big_copy(&dec_copy, *dec);
  divide_by_ten(&dec_copy, 1);

  while (((dec->bits[3] || dec->bits[4] || dec->bits[5]) && dec->scale) ||
         (dec->scale > 28 && !big_is_zero(*dec))) {
    int round_the_value = 0;
    int last_digit = divide_by_ten(dec, 1),
        penultimate_digit = divide_by_ten(&dec_copy, 1);

    if (last_digit > 5)
      round_the_value = 1;
    else if (last_digit == 5)
      if (penultimate_digit % 2 == 1) round_the_value = 1;

    if (round_the_value) inc(dec);
  }
}

int divide_by_ten(s21_big_decimal *dec, int times) {
  if (times <= 0) return 0;

  dec->scale -= times;
  if (dec->scale < 0) dec->scale = 0;

  int carry;
  while (times--) {
    carry = 0;
    for (int i = 5; i >= 0; i--) {
      unsigned long long dividend =
          ((unsigned long long)carry << 32) | (unsigned)dec->bits[i];
      dec->bits[i] = (unsigned int)(dividend / 10);
      carry = (int)(dividend % 10);
    }
  }

  return carry;
}

void multiply_by_ten(s21_big_decimal *dec, int times) {
  if (times <= 0) return;

  dec->scale -= times;

  int carry;
  while (dec->scale < 0) {
    carry = 0;
    for (int j = 0; j < 6; j++) {
      unsigned long long sum = (unsigned long long)dec->bits[j] * 10 + carry;
      dec->bits[j] = (int)(sum & 0xFFFFFFFF);
      carry = (int)(sum >> 32);
    }
    dec->scale++;
  }
}

void add_zeroes(s21_big_decimal *dec, int times) {
  if (times <= 0) return;

  dec->scale += times;

  int carry;
  while (times--) {
    carry = 0;
    for (int j = 0; j < 6; j++) {
      unsigned long long sum = (unsigned long long)dec->bits[j] * 10 + carry;
      dec->bits[j] = (int)(sum & 0xFFFFFFFF);
      carry = (int)(sum >> 32);
    }
  }
}

void inc(s21_big_decimal *dec) {
  int i = 0;
  while (++dec->bits[i] == 0) i++;
}