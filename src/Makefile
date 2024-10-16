all: s21_decimal.a test gcov_report
CC= -Wall -Werror -Wextra -std=c11
DEF= -o testing -lcheck -lm -lsubunit
AR= arithmetics/*.c
AUX= auxiliary/*.c
BIG= big_decimal/*.c big_decimal/big_arithmetics/*.c
COMP= comparisons/*.c
CON= converters/*.c
OTH= others/*.c
TEST= tests/*.c

clang_formats:
	clang-format -i $(AR)
	clang-format -i $(AUX)
	clang-format -i $(BIG)
	clang-format -i $(COMP)
	clang-format -i $(CON)
	clang-format -i $(OTH)
	clang-format -i $(TEST)
	clang-format -i big_decimal/big_decimal.h
	clang-format -i tests/test_main.h
	clang-format -i s21_decimal.h

s21_decimal.a: 
	gcc $(CC) -c $(AR) $(AUX) $(BIG) $(COMP) $(CON) $(OTH) -lm
	ar rcs s21_decimal.a *.o


leaks:
	gcc $(CC) $(AR) $(AUX) $(BIG) $(COMP) $(CON) $(OTH) $(TEST) $(DEF)
	valgrind --tool=memcheck --leak-check=yes ./testing
	rm -rf testing

test:
	gcc $(CC) $(AR) $(AUX) $(BIG) $(COMP) $(CON) $(OTH) $(TEST) $(DEF)
	./testing
	rm -rf testing

clean:
	rm -rf *.o *.a *.gch *.gcno *.gcda *.info report testing

gcov_report:
	gcc $(CC) --coverage $(AR) $(AUX) $(BIG) $(COMP) $(CON) $(OTH) $(TEST) $(DEF)
	./testing
	lcov -t "test" -o test_report.info -c -d .
	genhtml -o report test_report.info
