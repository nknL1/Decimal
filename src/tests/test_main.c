#include "test_main.h"

int main() {
  int fail = 0;
  Suite *s21_decimal_test[] = {test_from_decimal_to_float(),
                               test_from_decimal_to_int(),
                               test_from_int_to_decimal(),
                               test_from_float_to_decimal(),
                               test_mul(),
                               test_add(),
                               test_div(),
                               test_sub(),
                               test_s21_is_less(),
                               test_s21_is_less_or_equal(),
                               test_s21_is_greater(),
                               test_s21_is_greater_or_equal(),
                               test_s21_is_equal(),
                               test_s21_is_not_equal(),
                               test_truncate(),
                               test_floor(),
                               test_negate(),
                               test_round(),
                               NULL};

  for (int i = 0; s21_decimal_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_decimal_test[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    fail += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("Failed: %d\n", fail);
  return 0;
}