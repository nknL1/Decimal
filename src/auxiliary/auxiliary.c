#include "../big_decimal/big_decimal.h"
#include "../s21_decimal.h"

int get_sign(s21_decimal d) { return d.bits[3] >> 31; }

void set_sign(s21_decimal *d, int sign) {
  d->bits[3] &= 0x7FFFFFFF;
  d->bits[3] |= sign << 31;
}

int get_scale(s21_decimal d) { return (d.bits[3] >> 16) & 0xFF; }

void set_scale(s21_decimal *d, int scale) {
  d->bits[3] &= ~(0xFF << 16);
  d->bits[3] |= scale << 16;
}

// void print_decimal(s21_decimal d) {
//     printf("sign: %c  scale: %d\n", get_sign(d) ? '-' : '+', get_scale(d));

//     for (int i = 0; i < 3; i++)
//         printf("bits[%d]: %u (0X%08X)\n", i, d.bits[i], d.bits[i]);
// }

void set_zero(s21_decimal *d) {
  for (int i = 0; i < 4; i++) d->bits[i] = 0;
}

int is_zero(s21_decimal d) {
  return d.bits[0] == 0 && d.bits[1] == 0 && d.bits[2] == 0;
}

void copy(s21_decimal *copy_to, s21_decimal copy_from) {
  for (int i = 0; i < 4; i++) copy_to->bits[i] = copy_from.bits[i];
}

int get_bit(s21_decimal src, int pos) {
  int bit = 0;
  if (pos >= 0 && pos <= 31) {
    bit = src.bits[FIRST] & 1 << pos;
  } else if (pos > 31 && pos <= 63) {
    bit = src.bits[SECOND] & 1 << (pos - 32);
  } else {
    bit = src.bits[THIRD] & 1 << (pos - 64);
  }
  return bit ? 1 : 0;
}

void clear_decimal(s21_decimal *dst) {
  dst->bits[FIRST] = 0;
  dst->bits[SECOND] = 0;
  dst->bits[THIRD] = 0;
  dst->bits[SCALE] = 0;
}

void deleteChar(char *str, char ch) {
  char *src, *dst;
  for (src = dst = str; *src != '\0'; src++) {
    if (*src != ch) {
      *dst = *src;
      dst++;
    }
  }
  *dst = '\0';
}

int count_trailing_zeros(int number) {
  int count = 0;
  for (int i = 6; i >= 0; i--) {  // начинаем с 6, так как индексация идет с 0,
                                  // и последний элемент имеет индекс 6
    if (number % 10 == 0) {
      count++;
      number /= 10;
    } else {
      break;
    }
  }
  return count;
}