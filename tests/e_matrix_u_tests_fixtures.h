#ifndef E_MATRIXPLUS_TESTS_E_MATRIX_U_TESTS_FIXTURE_FULL_H_
#define E_MATRIXPLUS_TESTS_E_MATRIX_U_TESTS_FIXTURE_FULL_H_

#include <gtest/gtest.h>

#include "e_matrix_u_tests_environment.h"

class EMatrixEqMatrixSuite : public ::testing::TestWithParam<int> {};
class EMatrixSumSubTSuite : public ::testing::TestWithParam<int> {};

#endif  // E_MATRIXPLUS_TESTS_E_MATRIX_U_TESTS_FIXTURE_FULL_H_
