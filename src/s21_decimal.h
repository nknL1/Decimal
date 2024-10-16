#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define s21_INF 1.0 / 0.0
#define s21_N_INF -1.0 / 0.0
#define s21_NaN 0.0 / 0.0
#define s21_MAXINT 2147483647
#define s21_MININT -2147483648
#define s21_MINFLOAT 1e-28f
#define s21_MAXFLOAT 79228162514264337593543950335.
#define s21_UNSIGNED_MAX 0XFFFFFFFF
typedef struct {
  unsigned int bits[4];
} s21_decimal;

enum { FIRST, SECOND, THIRD, SCALE };

// arithmetics
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// comparisons
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

// converters
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// others
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);

// auxiliary
int get_sign(s21_decimal d);
void set_sign(s21_decimal *d, int sign);
int get_scale(s21_decimal d);
void set_scale(s21_decimal *d, int scale);
void set_zero(s21_decimal *d);
int is_zero(s21_decimal d);
void copy(s21_decimal *copy_to, s21_decimal copy_from);
int get_bit(s21_decimal src, int pos);
void print_decimal(s21_decimal d);
void clear_decimal(s21_decimal *dst);
void deleteChar(char *str, char ch);
int count_trailing_zeros(int number);

#endif