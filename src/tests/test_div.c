#include "test_main.h"

START_TEST(div_0) {
  s21_decimal number1 = {{864192, 0, 0, 0x00030000}};
  s21_decimal number2 = {{7, 0, 0, 0x00000000}};
  s21_decimal res;

  ck_assert_int_eq(0, s21_div(number1, number2, &res));
  ck_assert_int_eq(res.bits[0], 123456);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 196608);
}
END_TEST

START_TEST(div_1) {
  s21_decimal val1 = {{15, 15, 15, 0x000F0000}};
  s21_decimal val2 = {{10, 0, 0, 0x00000000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(res.bits[0], 15);
  ck_assert_int_eq(res.bits[1], 15);
  ck_assert_int_eq(res.bits[2], 15);
  ck_assert_int_eq(res.bits[3], 1048576);
}
END_TEST

START_TEST(div_2) {
  s21_decimal val1 = {{123, 456, 789, 0x00040000}};
  s21_decimal val2 = {{1, 1, 1, 0x00050000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(res.bits[0], 405681253);
  ck_assert_int_eq(res.bits[1], 150366383);
  ck_assert_int_eq(res.bits[2], 4277177570);
  ck_assert_int_eq(res.bits[3], 1638400);
}
END_TEST

START_TEST(div_3) {
  s21_decimal val1 = {{2, 0, 0, 0x00000000}};
  s21_decimal val2 = {{5, 0, 0, 0x001C0000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(res.bits[0], 2684354560);
  ck_assert_int_eq(res.bits[1], 2135032051);
  ck_assert_int_eq(res.bits[2], 216840434);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

// START_TEST(div_4) {
//   s21_decimal val1 = {{123456789, 900009, 1337, 0x00100000}};
//   s21_decimal val2 = {{1, 1, 1111111, 0x80070000}};
//   s21_decimal res;
//   ck_assert_int_eq(0, s21_div(val1, val2, &res));
//   ck_assert_int_eq(res.bits[0], 796440904);
//   ck_assert_int_eq(res.bits[1], 280165);
//   ck_assert_int_eq(res.bits[2], 0);
//   ck_assert_int_eq(res.bits[3], 2149253120);
// }
// END_TEST

START_TEST(div_5) {
  s21_decimal val1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x001C0000}};
  s21_decimal val2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(res.bits[0], 1);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 1835008);
}
END_TEST

START_TEST(div_6) {
  s21_decimal val1 = {{1, 0, 0, 0x001C0000}};
  s21_decimal val2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(div_7) {
  s21_decimal val1 = {{123, 0, 0, 0x00000000}};
  s21_decimal val2 = {{1, 0, 0, 0x001C0000}};
  s21_decimal res;
  ck_assert_int_eq(1, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_8) {
  s21_decimal val1 = {{123, 0, 0, 0x00000000}};
  s21_decimal val2 = {{1, 0, 0, 0x000A0000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(res.bits[0], 1639353344);
  ck_assert_int_eq(res.bits[1], 286);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(div_9) {
  s21_decimal val1 = {{123, 123, 123, 0x00050000}};
  s21_decimal val2 = {{1, 2, 3, 0x000A0000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(res.bits[0], 3942814950);
  ck_assert_int_eq(res.bits[1], 3297597181);
  ck_assert_int_eq(res.bits[2], 2222614453);
  ck_assert_int_eq(res.bits[3], 1441792);
}
END_TEST

START_TEST(div_10) {
  s21_decimal val1 = {{1234567890, 0, 0, 0x00050000}};
  s21_decimal val2 = {{0, 0, 0, 0x800A0000}};
  s21_decimal res;
  ck_assert_int_eq(3, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_11) {
  s21_decimal val1 = {{387420489, 999999999, 123456789, 0x000E0000}};
  s21_decimal val2 = {{987654321, 666666666, 888888888, 0x80190000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(res.bits[0], 2966737934);
  ck_assert_int_eq(res.bits[1], 2263411014);
  ck_assert_int_eq(res.bits[2], 752918170);
  ck_assert_int_eq(res.bits[3], 2148663296);
}
END_TEST

START_TEST(div_12) {
  s21_decimal val1 = {{123456, 0, 0, 0x00040000}};
  s21_decimal val2 = {{123, 0, 0, 0x00000000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(res.bits[0], 1964161873);
  ck_assert_int_eq(res.bits[1], 2944270678);
  ck_assert_int_eq(res.bits[2], 54411082);
  ck_assert_int_eq(res.bits[3], 1835008);
}
END_TEST

START_TEST(div_13) {
  s21_decimal val1 = {{1, 0, 0, 0x00000000}};
  s21_decimal val2 = {{3, 0, 0, 0x00000000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(res.bits[0], 89478485);
  ck_assert_int_eq(res.bits[1], 347537611);
  ck_assert_int_eq(res.bits[2], 180700362);
  ck_assert_int_eq(res.bits[3], 1835008);
}
END_TEST

Suite *test_div(void) {
  Suite *s = suite_create("s21_div");
  TCase *tc = tcase_create("div_tc");

  tcase_add_test(tc, div_0);
  tcase_add_test(tc, div_1);
  tcase_add_test(tc, div_2);
  tcase_add_test(tc, div_3);
  // tcase_add_test(tc, div_4);
  tcase_add_test(tc, div_5);
  tcase_add_test(tc, div_6);
  tcase_add_test(tc, div_7);
  tcase_add_test(tc, div_8);
  tcase_add_test(tc, div_9);
  tcase_add_test(tc, div_10);
  tcase_add_test(tc, div_11);
  tcase_add_test(tc, div_12);
  tcase_add_test(tc, div_13);

  suite_add_tcase(s, tc);
  return s;
}