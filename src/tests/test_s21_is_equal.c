#include "test_main.h"

START_TEST(comparison_0) {
  s21_decimal number1 = {{0, 0, 0, 0}};
  s21_decimal number2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(1, s21_is_equal(number1, number2));
  ck_assert_int_eq(0, s21_is_greater(number1, number2));
  ck_assert_int_eq(1, s21_is_greater_or_equal(number1, number2));
  ck_assert_int_eq(0, s21_is_less(number1, number2));
  ck_assert_int_eq(1, s21_is_less_or_equal(number1, number2));
  ck_assert_int_eq(0, s21_is_not_equal(number1, number2));
}
END_TEST

START_TEST(comparison_1) {
  s21_decimal number1 = {{1, 0, 0, 0}};
  s21_decimal number2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(0, s21_is_equal(number1, number2));
  ck_assert_int_eq(1, s21_is_greater(number1, number2));
  ck_assert_int_eq(1, s21_is_greater_or_equal(number1, number2));
  ck_assert_int_eq(0, s21_is_less(number1, number2));
  ck_assert_int_eq(0, s21_is_less_or_equal(number1, number2));
  ck_assert_int_eq(1, s21_is_not_equal(number1, number2));
}
END_TEST

START_TEST(comparison_2) {
  s21_decimal number1 = {{1, 0, 0, 0}};
  s21_decimal number2 = {{0, 1, 0, 0}};

  ck_assert_int_eq(0, s21_is_equal(number1, number2));
  ck_assert_int_eq(0, s21_is_greater(number1, number2));
  ck_assert_int_eq(0, s21_is_greater_or_equal(number1, number2));
  ck_assert_int_eq(1, s21_is_less(number1, number2));
  ck_assert_int_eq(1, s21_is_less_or_equal(number1, number2));
  ck_assert_int_eq(1, s21_is_not_equal(number1, number2));
}
END_TEST

START_TEST(comparison_3) {
  s21_decimal number1 = {{123, 123, 123, 0X00000000}};
  s21_decimal number2 = {{123, 123, 123, 0X00010000}};

  ck_assert_int_eq(0, s21_is_equal(number1, number2));
  ck_assert_int_eq(1, s21_is_greater(number1, number2));
  ck_assert_int_eq(1, s21_is_greater_or_equal(number1, number2));
  ck_assert_int_eq(0, s21_is_less(number1, number2));
  ck_assert_int_eq(0, s21_is_less_or_equal(number1, number2));
  ck_assert_int_eq(1, s21_is_not_equal(number1, number2));
}
END_TEST

START_TEST(comparison_4) {
  s21_decimal number1 = {{123, 123, 123, 0X00040000}};
  s21_decimal number2 = {{123, 123, 123, 0X00010000}};

  ck_assert_int_eq(0, s21_is_equal(number1, number2));
  ck_assert_int_eq(0, s21_is_greater(number1, number2));
  ck_assert_int_eq(0, s21_is_greater_or_equal(number1, number2));
  ck_assert_int_eq(1, s21_is_less(number1, number2));
  ck_assert_int_eq(1, s21_is_less_or_equal(number1, number2));
  ck_assert_int_eq(1, s21_is_not_equal(number1, number2));
}
END_TEST

START_TEST(comparison_5) {
  s21_decimal number1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0X80000000}};
  s21_decimal number2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0X80000000}};

  ck_assert_int_eq(1, s21_is_equal(number1, number2));
  ck_assert_int_eq(0, s21_is_greater(number1, number2));
  ck_assert_int_eq(1, s21_is_greater_or_equal(number1, number2));
  ck_assert_int_eq(0, s21_is_less(number1, number2));
  ck_assert_int_eq(1, s21_is_less_or_equal(number1, number2));
  ck_assert_int_eq(0, s21_is_not_equal(number1, number2));
}
END_TEST

START_TEST(comparison_6) {
  s21_decimal number1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0X80100000}};
  s21_decimal number2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0X800F0000}};

  ck_assert_int_eq(0, s21_is_equal(number1, number2));
  ck_assert_int_eq(1, s21_is_greater(number1, number2));
  ck_assert_int_eq(1, s21_is_greater_or_equal(number1, number2));
  ck_assert_int_eq(0, s21_is_less(number1, number2));
  ck_assert_int_eq(0, s21_is_less_or_equal(number1, number2));
  ck_assert_int_eq(1, s21_is_not_equal(number1, number2));
}
END_TEST

START_TEST(comparison_7) {
  s21_decimal number1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  s21_decimal number2 = {{1, 0, 0, 0x00000000}};

  ck_assert_int_eq(0, s21_is_equal(number1, number2));
  ck_assert_int_eq(0, s21_is_greater(number1, number2));
  ck_assert_int_eq(0, s21_is_greater_or_equal(number1, number2));
  ck_assert_int_eq(1, s21_is_less(number1, number2));
  ck_assert_int_eq(1, s21_is_less_or_equal(number1, number2));
  ck_assert_int_eq(1, s21_is_not_equal(number1, number2));
}
END_TEST

START_TEST(comparison_8) {
  s21_decimal number1 = {{387420489, 999999999, 123456789, 0x000E0000}};
  s21_decimal number2 = {{987654321, 666666666, 888888888, 0x80190000}};

  ck_assert_int_eq(0, s21_is_equal(number1, number2));
  ck_assert_int_eq(1, s21_is_greater(number1, number2));
  ck_assert_int_eq(1, s21_is_greater_or_equal(number1, number2));
  ck_assert_int_eq(0, s21_is_less(number1, number2));
  ck_assert_int_eq(0, s21_is_less_or_equal(number1, number2));
  ck_assert_int_eq(1, s21_is_not_equal(number1, number2));
}
END_TEST

START_TEST(test1) {
  s21_decimal src = {{0, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(1, s21_is_equal(src, src2));
}
END_TEST

START_TEST(test2) {
  s21_decimal src = {{0, 0, 0, 0}};
  s21_decimal src2 = {{1, 0, 0, 0}};
  ck_assert_int_eq(0, s21_is_equal(src, src2));
}
END_TEST

START_TEST(test3) {
  s21_decimal src = {{0, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0x80000000}};
  ck_assert_int_eq(1, s21_is_equal(src, src2));
}
END_TEST

START_TEST(test4) {
  s21_decimal src = {{2483874238, 42323, 0, 0x80000000}};
  s21_decimal src2 = {{321321, 321321, 123, 0x80190000}};
  ck_assert_int_eq(0, s21_is_equal(src, src2));
}
END_TEST

START_TEST(test5) {
  s21_decimal src = {{123140, 0, 0, 0x30000}};
  s21_decimal src2 = {{12314, 0, 0, 0x20000}};
  ck_assert_int_eq(1, s21_is_equal(src, src2));
}
END_TEST

Suite *test_s21_is_equal(void) {
  Suite *s = suite_create("s21_is_equal");
  TCase *tc = tcase_create("tc_s21_is_equal");

  tcase_add_test(tc, comparison_0);
  tcase_add_test(tc, comparison_1);
  tcase_add_test(tc, comparison_2);
  tcase_add_test(tc, comparison_3);
  tcase_add_test(tc, comparison_4);
  tcase_add_test(tc, comparison_5);
  tcase_add_test(tc, comparison_6);
  tcase_add_test(tc, comparison_7);
  tcase_add_test(tc, comparison_8);
  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);
  tcase_add_test(tc, test5);
  suite_add_tcase(s, tc);
  return s;
}