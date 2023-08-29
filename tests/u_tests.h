#ifndef E_MATRIXPLUS_TESTS_UNIT_TESTS_H_
#define E_MATRIXPLUS_TESTS_UNIT_TESTS_H_

#include <gtest/gtest.h>

#include "../e_matrix_oop.h"

struct EMatrixTest : public testing::Test {
  EMatrix *matrix;

  void SetUp();
  void TearDown();
};

#endif  // E_MATRIXPLUS_TESTS_UNIT_TESTS_H_
