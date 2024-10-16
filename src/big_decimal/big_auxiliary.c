#include "big_decimal.h"

void rescale(s21_big_decimal *value1, s21_big_decimal *value2) {
  if (value1->scale > value2->scale) {
    add_zeroes(value2, value1->scale - value2->scale);
    value2->scale = value1->scale;
  } else if (value1->scale < value2->scale) {
    add_zeroes(value1, value2->scale - value1->scale);
    value1->scale = value2->scale;
  }
}

void big_set_zero(s21_big_decimal *d) {
  for (int i = 0; i < 6; i++) d->bits[i] = 0;
  d->scale = 0;
  d->sign = 0;
}

// void print_big(s21_big_decimal d) {
//     printf("sign: %c  scale: %d\n", d.sign ? '-' : '+', d.scale);

//     for (int i = 0; i < 6; i++)
//         printf("bits[%d]: %u (0X%08X)\n", i, d.bits[i], d.bits[i]);
// }

void big_copy(s21_big_decimal *copy_to, s21_big_decimal copy_from) {
  for (int i = 0; i < 6; i++) copy_to->bits[i] = copy_from.bits[i];
  copy_to->sign = copy_from.sign;
  copy_to->scale = copy_from.scale;
}

void delete_trailing_zeroes(s21_big_decimal *d) {
  s21_big_decimal d_copy;
  big_copy(&d_copy, *d);

  while (d->scale > 0 && divide_by_ten(&d_copy, 1) == 0) divide_by_ten(d, 1);
}

void big_bitwise_shift_left(s21_big_decimal *d, int shift) {
  for (int i = 5; i > 0; i--) {
    d->bits[i] = (d->bits[i] << shift) | (d->bits[i - 1] >> (32 - shift));
  }

  d->bits[0] = d->bits[0] << shift;
}

int big_get_bit(s21_big_decimal d, int position) {
  int block = position / 32, bit_position = position % 32;

  return (d.bits[block] >> bit_position) & 1;
}

void big_set_bit(s21_big_decimal *d, int position, int value) {
  int block = position / 32, bit_position = position % 32;

  d->bits[block] =
      (d->bits[block] & ~(1 << bit_position)) | (value << bit_position);
}
