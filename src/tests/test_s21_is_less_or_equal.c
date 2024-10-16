#include "test_main.h"

START_TEST(test1) {
  s21_decimal src = {{0, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(1, s21_is_less_or_equal(src, src2));
}
END_TEST

START_TEST(test2) {
  s21_decimal src = {{0, 0, 0, 0}};
  s21_decimal src2 = {{1, 0, 0, 0}};
  ck_assert_int_eq(1, s21_is_less_or_equal(src, src2));
}
END_TEST

START_TEST(test3) {
  s21_decimal src = {{0, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0x80000000}};
  ck_assert_int_eq(1, s21_is_less_or_equal(src, src2));
}
END_TEST

START_TEST(test4) {
  s21_decimal src = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0X80100000}};
  s21_decimal src2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0X800F0000}};
  ck_assert_int_eq(0, s21_is_less_or_equal(src, src2));
}
END_TEST

START_TEST(test5) {
  s21_decimal src = {{123140, 0, 0, 0x30000}};
  s21_decimal src2 = {{12314, 0, 0, 0x20000}};
  ck_assert_int_eq(1, s21_is_less_or_equal(src, src2));
}
END_TEST

START_TEST(test6) {
  s21_decimal src = {{1, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(0, s21_is_less_or_equal(src, src2));
}
END_TEST

START_TEST(test7) {
  s21_decimal src = {{1, 0, 0, 0}};
  s21_decimal src2 = {{0, 1, 0, 0}};
  ck_assert_int_eq(1, s21_is_less_or_equal(src, src2));
}
END_TEST

START_TEST(test8) {
  s21_decimal src = {{0, 0, 0, 0x80000000}};
  s21_decimal src2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(1, s21_is_less_or_equal(src, src2));
}
END_TEST

Suite *test_s21_is_less_or_equal(void) {
  Suite *s = suite_create("s21_is_less_or_equal");
  TCase *tc = tcase_create("tc_test_s21_is_less_or_equal");

  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);
  tcase_add_test(tc, test5);
  tcase_add_test(tc, test6);
  tcase_add_test(tc, test7);
  tcase_add_test(tc, test8);
  suite_add_tcase(s, tc);
  return s;
}