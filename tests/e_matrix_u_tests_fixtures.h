#ifndef E_MATRIXPLUS_TESTS_E_MATRIX_U_TESTS_FIXTURES_H_
#define E_MATRIXPLUS_TESTS_E_MATRIX_U_TESTS_FIXTURES_H_

#include <gtest/gtest.h>

#include "e_matrix_u_tests_environment.h"

class EMatrixRuleOfFiveTSuite : public ::testing::TestWithParam<int> {};
class EMatrixAccessorsMutators : public ::testing::TestWithParam<int> {};

class EMatrixEqMatrixTSuite : public ::testing::TestWithParam<int> {};
class EMatrixSumSubTSuite : public ::testing::TestWithParam<int> {};
class EMatrixMulTSuite : public ::testing::TestWithParam<int> {};
class EMatrixTransposeTSuite : public ::testing::TestWithParam<int> {};
// class EMatrixCalcComplementsTSuite : public ::testing::TestWithParam<int> {};
class EMatrixDeterminantTSuite : public ::testing::TestWithParam<int> {};

class EMatrixOperatorsOverloadsTSuite : public ::testing::TestWithParam<int> {};

#endif  // E_MATRIXPLUS_TESTS_E_MATRIX_U_TESTS_FIXTURES_H_
