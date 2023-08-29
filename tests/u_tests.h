#ifndef E_MATRIXPLUS_TESTS_UNIT_TESTS_H_
#define E_MATRIXPLUS_TESTS_UNIT_TESTS_H_

#include <gtest/gtest.h>

#include "../e_matrix_oop.h"

class EMatrixTest : public testing::Test {
 protected:
  void SetUp();
  void TearDown();

  EMatrix *matrix;
};

#endif  // E_MATRIXPLUS_TESTS_UNIT_TESTS_H_
