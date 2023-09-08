.PHONY: all clean test e_matrix_oop.a gcov gcov_report

# UTILITIES
CC = gcc
AR = ar rs
RAN = ranlib
MK = mkdir -p
RM = rm -rf
OPEN_TXT = open -e
OS := $(shell uname)
ifeq ($(OS), Darwin)
	LEAKS = CK_FORK=no leaks --atExit -- 
	OPEN_HTML = open
else ifeq ($(OS), Linux)
	LEAKS =
	OPEN_HTML = xdg-open
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
OBJ_DIR = ./obj/
OBJ = $(patsubst $(SRC_DIR)%.cc, $(OBJ_DIR)%.o, $(SRC))

TESTS_DIR = ./tests/
TESTS_SRC = $(wildcard $(TESTS_DIR)*.cc)
TESTS_OBJ_DIR = ./tests_obj/
TESTS_OBJ = $(patsubst $(TESTS_DIR)%.cc, $(TESTS_OBJ_DIR)%.o, $(TESTS_SRC))
TESTS_RUNNER = tests_runner
TESTS_REPORT = u_tests_report.txt

MAN_TEST_DIR = ./man_tests/
MAN_TEST_RUNNER = ./man_test_runner
EXECUTION_REPORT = man_tests_report.txt

EXE = a.out $(MAN_TEST_RUNNER) $(TESTS_RUNNER)

# BUILD
all: e_matrix_oop.a test gcov_report

lib: e_matrix_oop.a

e_matrix_oop.a: objects
	@$(AR) $@ $(OBJ)
	@$(RAN) $@
	@echo "$(AR): creating library $(TARGET) \033[0;32msuccess\033[0m"

objects: makeobjdir $(OBJ)
	@echo "\033[0;32m$(CC): LIBRARY OBJECT FILES COMPILATION SUCCESS\033[0m"

makeobjdir:
	@$(MK) $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cc
	@$(CC) $(CF) $(STD) -c $^ -o $@

# TESTS && COVERAGE
test: clean $(TARGET) testobjects
	$(CC) $(CF) $(STD) $(GTESTF) $(TESTS_OBJ) $(TARGET) -o $(TESTS_RUNNER)
	./$(TESTS_RUNNER) > $(TESTS_REPORT)
	$(OPEN_TXT) $(TESTS_REPORT)
	@$(RM) $(TESTS_RUNNER)

cover: gcov_report

gcov_report: clean testobjects
	$(CC) $(CF) $(STD) $(GTESTF) $(GCOV_FLAGS) $(ASAN) $(TESTS_OBJ) $(SRC) -o $(TESTS_RUNNER)
	./$(TESTS_RUNNER) > $(TESTS_REPORT)
	@$(RM) $(TESTS_RUNNER)
	open $(TESTS_REPORT)
	@lcov -t "gcov_report" --ignore-errors mismatch -o report.info --no-external -c -d .
	@genhtml -o report report.info
	@$(OPEN_HTML) ./report/index.html
	@$(RM) *.gcno *.gcda *.info

testobjects: maketestobjdir $(TESTS_OBJ)
	@echo "\033[0;32m$(CC): TEST OBJECT FILES COMPILATION SUCCESS\033[0m"

maketestobjdir:
	@$(MK) $(TESTS_OBJ_DIR)

$(TESTS_OBJ_DIR)%.o: $(TESTS_DIR)%.cc
	$(CC) $(CF) $(STD) $(ASAN) -c $^ -o $@

# SERVICE
style:
	find . -name "*.h" -o -name "*.cc" | xargs clang-format --style=google -n

gost:
	find . -name "*.h" -o -name "*.cc" | xargs clang-format --style=google -i

clean:
	@$(RM) $(EXE)
	@$(RM) *.txt
	@rm -rf *.out *.dSYM ./tests/*.dSYM ./units/*dSYM
	@rm -rf *.gcno *.gcda ./report gcov_test *.info

obj_rm:
	@$(RM) $(TARGET)
	@$(RM) $(OBJ_DIR) $(TESTS_OBJ_DIR)

# DEVELOPING TESTS
man:
#	@$(CC) $(CF) $(STD) $(MAN_TEST_DIR)constructor_destructor_man_test.cc $(SRC) -o $(MAN_TEST_RUNNER)
#	@$(CC) $(CF) $(STD) $(MAN_TEST_DIR)operations_man_test.cc $(SRC) -o $(MAN_TEST_RUNNER)
	@$(CC) $(CF) $(STD) $(MAN_TEST_DIR)determinant_man_test.cc $(SRC) -o $(MAN_TEST_RUNNER)
	@$(LEAKS) $(MAN_TEST_RUNNER) > $(EXECUTION_REPORT)
	@$(RM) $(MAN_TEST_RUNNER)
#	$(OPEN_TXT) $(EXECUTION_REPORT)
