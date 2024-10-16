#include "big_decimal.h"

int big_is_greater(s21_big_decimal value_1, s21_big_decimal value_2) {
  int is_greater = 0;
  int sign_1 = value_1.sign, sign_2 = value_2.sign;

  if (sign_1 != sign_2) {
    if (value_1.bits[0] == value_2.bits[0] &&
        value_1.bits[1] == value_2.bits[1] &&
        value_1.bits[2] == value_2.bits[2] &&
        value_1.bits[3] == value_2.bits[3] &&
        value_1.bits[4] == value_2.bits[4] &&
        value_1.bits[5] == value_2.bits[5] && value_1.bits[5] == 0) {
      is_greater = 0;
    } else {
      is_greater = !sign_1;
    }

  } else if (sign_1 == 1 && sign_2 == 1) {
    value_1.sign = 0;
    value_2.sign = 0;
    is_greater = big_is_greater(value_2, value_1);
  } else {
    rescale(&value_1, &value_2);

    int stop_flag = 0;
    for (int i = 5; i >= 0 && !stop_flag; i--) {
      if (value_1.bits[i] != value_2.bits[i]) {
        is_greater = value_1.bits[i] > value_2.bits[i];
        stop_flag = 1;
      }
    }
  }

  return is_greater;
}

int big_is_equal(s21_big_decimal value_1, s21_big_decimal value_2) {
  rescale(&value_1, &value_2);
  // return value_1.sign == value_2.sign && value_1.bits[0] == value_2.bits[0]
  // &&
  //        value_1.bits[1] == value_2.bits[1] &&
  //        value_1.bits[2] == value_2.bits[2] &&
  //        value_1.bits[3] == value_2.bits[3] &&
  //        value_1.bits[4] == value_2.bits[4] &&
  //        value_1.bits[5] == value_2.bits[5];

  if (value_1.sign == value_2.sign && value_1.bits[0] == value_2.bits[0] &&
      value_1.bits[1] == value_2.bits[1] &&
      value_1.bits[2] == value_2.bits[2] &&
      value_1.bits[3] == value_2.bits[3] &&
      value_1.bits[4] == value_2.bits[4] &&
      value_1.bits[5] == value_2.bits[5]) {
    return 1;
  }
  if (value_1.sign != value_2.sign && value_1.bits[0] == value_2.bits[0] &&
      value_1.bits[1] == value_2.bits[1] &&
      value_1.bits[2] == value_2.bits[2] &&
      value_1.bits[3] == value_2.bits[3] &&
      value_1.bits[4] == value_2.bits[4] &&
      value_1.bits[5] == value_2.bits[5] && value_1.bits[5] == 0) {
    return 1;
  } else {
    return 0;
  }
}

int big_is_greater_or_equal(s21_big_decimal value_1, s21_big_decimal value_2) {
  return big_is_greater(value_1, value_2) || big_is_equal(value_1, value_2);
}

int big_is_zero(s21_big_decimal d) {
  return d.bits[0] == 0 && d.bits[1] == 0 && d.bits[2] == 0 && d.bits[3] == 0 &&
         d.bits[4] == 0 && d.bits[5] == 0;
}