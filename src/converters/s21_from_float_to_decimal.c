#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  clear_decimal(dst);
  int error = 0;
  int sign = 0;
  if (src < 0) {
    src = -src;
    sign = 1;
  }
  if ((src < s21_MINFLOAT && src > 0.0f) || src > s21_MAXFLOAT ||
      src == s21_N_INF || src == s21_INF) {
    error = 1;
  } else if (src == 0.0f) {
    error = 0;
  } else {
    char *buffer;
    int size;
    size = snprintf(NULL, 0, "%e", src);
    buffer = (char *)malloc(size + 1);
    if (buffer != NULL) {
      sprintf(buffer, "%e", src);  // тут число в 1.23e+02
      char numberWithoutPoint[9];  // 1.234568
      char exponenta[4];           // +02
      sscanf(buffer, "%9[^e]e%4s", numberWithoutPoint, exponenta);
      free(buffer);
      deleteChar(numberWithoutPoint, '.');
      int mantisa = atoi(numberWithoutPoint);
      int scale = atoi(exponenta);
      int zeros = count_trailing_zeros(mantisa);
      if (6 - scale >= 0) {
        if (6 - scale - zeros > 28) {
          error = 1;
        } else {
          scale = 6 - scale - zeros;
          dst->bits[FIRST] = mantisa / pow(10, zeros);
          dst->bits[SCALE] = scale << 16;
        }
      } else {
        dst->bits[FIRST] = mantisa;
        s21_decimal timeDst;
        for (int i = 0; i < scale - 6; i++) {
          s21_decimal ten = {{10, 0, 0, 0}};
          int error2 = s21_mul(*dst, ten, &timeDst);
          if (error2) {
            error = 1;
            clear_decimal(dst);
          } else {
            dst->bits[FIRST] = timeDst.bits[FIRST];
            dst->bits[SECOND] = timeDst.bits[SECOND];
            dst->bits[THIRD] = timeDst.bits[THIRD];
            dst->bits[SCALE] = timeDst.bits[SCALE];
          }
          clear_decimal(&timeDst);
        }
      }
    }
  }
  if (sign) {
    dst->bits[SCALE] = dst->bits[SCALE] | 1 << 31;
  }
  return error;
}