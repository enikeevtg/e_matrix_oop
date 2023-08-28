.PHONY: all clean test e_matrix_oop.a

# UTILITIES
CC = gcc
LEAKS = leaks -atExit -- #
RM = rm -rf

# UTITLITIES OPTIONS
CF = -Wall -Werror -Wextra -lstdc++
STD = -std=c++17 -pedantic

# FILENAMES
TARGET = e_matrix_oop.a
SRC_DIR = ./src/
SRC = $(wildcard $(SRC_DIR)*.cc)

MAN_TEST_DIR = ./man_tests/
MAN_TEST_RUNER = ./man_test_runner
EXECUTION_REPORT = execution_report.txt
OPEN_TXT = open -e
EXE = $(MAN_TEST_RUNER) a.out

# BUILD
all:

test:

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
#	$(CC) $(CF) $(STD) $(MAN_TEST_DIR)constructor_destructor_man_test.cc $(SRC) -o $(MAN_TEST_RUNER)
	$(CC) $(CF) $(STD) $(MAN_TEST_DIR)operations_man_test.cc $(SRC) -o $(MAN_TEST_RUNER)
	@$(LEAKS) $(MAN_TEST_RUNER) > $(EXECUTION_REPORT)
#	$(OPEN_TXT) $(EXECUTION_REPORT)
	@$(RM) $(MAN_TEST_RUNER)
