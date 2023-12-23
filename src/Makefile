CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror
CCOVTEST= -fprofile-arcs -ftest-coverage
LIBS = -lm

all: s21_string.a

s21_string.a: s21_string.o
	ar rcs $@ $^

s21_string.o: s21_string.c s21_string.h
	$(CC) $(CFLAGS) -c $< -o $@

test1: string.o s21_string.o
	$(CC) $(CFLAGS)  $^ $(LIBS) -o $@ -lcheck -lm -lpthread
	./test1

test2: tests.o s21_string.o
	$(CC) $(CFLAGS) $(CCOVTEST) $^ $(LIBS) -o $@ -lcheck -lm -lpthread
	./test2

tests.o: s21_string.h
	$(CC) $(CFLAGS) $(CCOVTEST) -I. -c nw/s21_string_tests.c -o $@

test_sprintf_d.o: s21_string.h
	$(CC) $(CFLAGS) $(CCOVTEST) -I. -c tests/test_sprintf_d.c -o $@

test: test_s21_string.o s21_string.o
	$(CC) $(CFLAGS) $(CCOVTEST) $^ $(LIBS) -o $@ -lcheck -lm -lpthread
	./test

test_s21_string.o: s21_string_tests.c s21_string.h
	$(CC) $(CFLAGS) $(CCOVTEST) -I. -c $< -o $@

string.o: string.c s21_string.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

gcov_report: test s21_math.a
	$(CC) $(CFLAGS) -pedantic -lcheck $(CCOVTEST) test_s21_math.c s21_math.a -o $@
	./gcov_report
	lcov -t gcov_report -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

clang:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.c *.h

clean:
	rm -f *.a
	rm -f *.o
	rm -f test1
	rm -f test
	rm -f *.gc*
	rm -f gcov_report.html
	rm -f gcov_report
	rm -f test.info
	rm -f -R report
rebuild: clean all
	clear
r:clean test2