.PHONY: all clean test e_matrix_oop.a

# UTILITIES
CC = gcc
LEAKS = leaks -atExit -- #
RM = rm -rf
OPEN_TXT = open -e

# UTITLITIES OPTIONS
CF = -Wall -Werror -Wextra -lstdc++
STD = -std=c++17 -pedantic
GTESTF = -lgtest -pthread

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
	@./$(TESTS_RUNNER)
#	 --gtest_output=xml:output.xml
#	 > $(TESTS_REPORT)
#	@$(RM) $(TESTS_RUNNER)

e_matrix_oop.a:

lib: e_matrix_oop.a

# SERVICE
style:
	find . -name "*.h" -o -name "*.cc" | xargs clang-format --style=google -n

gost:
	find . -name "*.h" -o -name "*.cc" | xargs clang-format --style=google -i

clean:
	$(RM) $(EXE)
	@$(RM) *.txt

# DEVELOPING TESTS
man:
#	@$(CC) $(CF) $(STD) $(MAN_TEST_DIR)constructor_destructor_man_test.cc $(SRC) -o $(MAN_TEST_RUNNER)
	@$(CC) $(CF) $(STD) $(MAN_TEST_DIR)operations_man_test.cc $(SRC) -o $(MAN_TEST_RUNNER)
	@$(LEAKS) $(MAN_TEST_RUNNER) > $(EXECUTION_REPORT)
#	$(OPEN_TXT) $(EXECUTION_REPORT)
	@$(RM) $(MAN_TEST_RUNNER)
