NAME = s21_matrix
CC = g++
CC_FLAGS = -std=c++17 -Wall -Wextra -Werror -g #-pedantic
GCOV_FLAGS = -L. -lgcov -lgtest -lgtest_main -ls21_matrix -lgmock --coverage
OS = $(shell uname)
#-o test -lgtest -lgmock -pthread - флаги для тестов из статьи 
ifeq ($(OS), Linux)
	CHECK_FLAGS = -lgtest -pthread -lrt -lm -lsubunit
else
	CHECK_FLAGS = $(shell pkg-config --libs --cflags) -lm
endif

TEST_COMPILE = $(CC) $(CC_FLAGS) test/*.cc libs21_matrix.a $(CHECK_FLAGS) -L. -lgtest -lgtest_main -lgmock -ls21_matrix

all: clean s21_matrix.a

clean:
	rm -rf *.o, *.g* *.info *.out report *.a *.dSYM

re: clean all

s21_matrix.o:
	$(CC) $(CC_FLAGS) -c *.cc

s21_matrix.a: s21_matrix.o
	ar rcs libs21_matrix.a *.o
	rm -rf *.o
	ranlib libs21_matrix.a
	cp libs21_matrix.a s21_matrix.a

test: s21_matrix.a
	$(TEST_COMPILE)
	./a.out

clang: 
	clang-format -i *.cc *.h test/*.cc test/*.h

gcov_report: s21_matrix.a test
	rm -f *.g*
	$(CC) $(CC_FLAGS) test/*.cc *.cc libs21_matrix.a $(CHECK_FLAGS) $(GCOV_FLAGS)
	./a.out
	lcov -t a.out -o rep.info -c -d .
	genhtml -o report rep.info
	open ./report/index.html
	rm -rf *.gcda *.gcno

check:
	clang-format -style=google -n s21_*.cc *.h
	make test
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./a.out
else
	valgrind ./a.out --leak-check=full
endif
	make clean

.PHONY: all clean re s21_matrix.a test gcov_report check