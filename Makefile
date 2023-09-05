.PHONY: all clean test e_matrix_oop.a gcov gcov_report

# UTILITIES
CC = gcc
RM = rm -rf
OPEN_TXT = open -e
OS := $(shell uname)
ifeq ($(OS), Darwin)
	LEAKS = CK_FORK=no leaks --atExit -- 
	REPORT_OPEN = open
else ifeq ($(OS), Linux)
	LEAKS =
	REPORT_OPEN = xdg-open
endif


# UTITLITIES OPTIONS
CF = -Wall -Werror -Wextra -lstdc++
STD = -std=c++17 -pedantic
GTESTF = -lgtest -pthread
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

# FILENAMES
TARGET = e_matrix_oop.a
SRC_DIR = ./src/
SRC = $(wildcard $(SRC_DIR)*.cc)

TESTS_DIR = ./tests/
TESTS_SRC = $(wildcard $(TESTS_DIR)*.cc)
# $(wildcard $(TESTS_DIR)*.h)
TESTS_RUNNER = tests_runner
TESTS_REPORT = u_tests_report.txt

MAN_TEST_DIR = ./man_tests/
MAN_TEST_RUNNER = ./man_test_runner
EXECUTION_REPORT = man_tests_report.txt

EXE = a.out $(MAN_TEST_RUNNER) $(TESTS_RUNNER)

# BUILD
all:

lib: e_matrix_oop.a

e_matrix_oop.a: clean

test:
	$(CC) $(CF) $(STD) $(GTESTF) $(TESTS_SRC) $(SRC) -o $(TESTS_RUNNER)
	@./$(TESTS_RUNNER) > $(TESTS_REPORT)
#	 --gtest_output=xml:output.xml
	@$(RM) $(TESTS_RUNNER)

cover: gcov_report

gcov_report: clean
	$(CC) $(CF) $(STD) $(GTESTF) $(GCOV_FLAGS) $(ASAN) $(TESTS_SRC) $(SRC) -o $(TESTS_RUNNER)
	@./$(TESTS_RUNNER) > $(TESTS_REPORT)
	@$(RM) $(TESTS_RUNNER)
	open $(TESTS_REPORT)
	@lcov -t "./gcov" -o report.info --no-external -c -d . --ignore-errors mismatch
	@genhtml -o report report.info
	@$(REPORT_OPEN) ./report/index.html
	@rm -rf *.gcno *.gcda gcov_test *.info

# SERVICE
style:
	find . -name "*.h" -o -name "*.cc" | xargs clang-format --style=google -n

gost:
	find . -name "*.h" -o -name "*.cc" | xargs clang-format --style=google -i

clean:
	@rm -rf $(TARGET)
	@$(RM) $(EXE)
	@$(RM) *.txt
	@rm -rf *.out *.dSYM ./tests/*.dSYM ./units/*dSYM
	@rm -rf *.gcno *.gcda ./report gcov_test *.info

# DEVELOPING TESTS
man:
#	@$(CC) $(CF) $(STD) $(MAN_TEST_DIR)constructor_destructor_man_test.cc $(SRC) -o $(MAN_TEST_RUNNER)
	@$(CC) $(CF) $(STD) $(MAN_TEST_DIR)operations_man_test.cc $(SRC) -o $(MAN_TEST_RUNNER)
	@$(LEAKS) $(MAN_TEST_RUNNER) > $(EXECUTION_REPORT)
#	$(OPEN_TXT) $(EXECUTION_REPORT)
	@$(RM) $(MAN_TEST_RUNNER)
