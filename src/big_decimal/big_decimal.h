#ifndef BIG_DECIMAL_H
#define BIG_DECIMAL_H

#include "../s21_decimal.h"

typedef struct {
  unsigned int bits[6];
  int scale;
  int sign;
} s21_big_decimal;

// arithemtics
void big_add(s21_big_decimal value_1, s21_big_decimal value_2,
             s21_big_decimal *result);
void big_sub(s21_big_decimal value_1, s21_big_decimal value_2,
             s21_big_decimal *result);
void big_mul(s21_big_decimal value_1, s21_big_decimal value_2,
             s21_big_decimal *result);
void big_div(s21_big_decimal value_1, s21_big_decimal value_2,
             s21_big_decimal *result);

void bank_rounding(s21_big_decimal *dec);
int divide_by_ten(s21_big_decimal *dec, int times);
void multiply_by_ten(s21_big_decimal *dec, int times);
void inc(s21_big_decimal *dec);

// auxiliary

void rescale(s21_big_decimal *value1, s21_big_decimal *value2);
void add_zeroes(s21_big_decimal *dec, int times);
int number_of_digits(s21_big_decimal big_dec);
void big_set_zero(s21_big_decimal *d);
void print_big(s21_big_decimal d);
void big_copy(s21_big_decimal *copy_to, s21_big_decimal copy_from);
int big_is_greater(s21_big_decimal value_1, s21_big_decimal value_2);
int big_is_equal(s21_big_decimal value_1, s21_big_decimal value_2);
int big_is_greater_or_equal(s21_big_decimal value_1, s21_big_decimal value_2);
int big_is_zero(s21_big_decimal d);
void delete_trailing_zeroes(s21_big_decimal *d);
void big_bitwise_shift_left(s21_big_decimal *d, int shift);
int big_get_bit(s21_big_decimal d, int position);
void big_set_bit(s21_big_decimal *d, int position, int value);

// converters
s21_big_decimal decimal_to_big(s21_decimal dec);
int big_to_decimal(s21_big_decimal big_dec, s21_decimal *result);

#endif