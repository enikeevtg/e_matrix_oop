#include "e_matrix_u_tests_fixtures.h"

namespace e_matrix {

INSTANTIATE_TEST_SUITE_P(
    EMatrixUTests, EMatrixRuleOfFiveTSuite,
    testing::Range(0, TestsEnvironment::uform_matr_number_*
                          TestsEnvironment::kMatrTypesNumber));

INSTANTIATE_TEST_SUITE_P(EMatrixUTests, EMatrixAccessorsMutators,
                         testing::Range(1, 11));

INSTANTIATE_TEST_SUITE_P(
    EMatrixUTests, EMatrixEqMatrixTSuite,
    testing::Range(0, TestsEnvironment::uform_matr_number_*
                          TestsEnvironment::kMatrTypesNumber));

INSTANTIATE_TEST_SUITE_P(
    EMatrixUTests, EMatrixSumSubTSuite,
    testing::Range(0, TestsEnvironment::uform_matr_number_*
                          TestsEnvironment::kMatrTypesNumber));

INSTANTIATE_TEST_SUITE_P(
    EMatrixUTests, EMatrixMulTSuite,
    testing::Range(0, TestsEnvironment::uform_matr_number_*
                          TestsEnvironment::kMatrTypesNumber));

INSTANTIATE_TEST_SUITE_P(
    EMatrixUTests, EMatrixTransposeTSuite,
    testing::Range(0, TestsEnvironment::uform_matr_number_*
                          TestsEnvironment::kMatrTypesNumber));

INSTANTIATE_TEST_SUITE_P(
    EMatrixUTests, EMatrixCalcComplementsTSuite,
    testing::Range(0, TestsEnvironment::uform_matr_number_*
                          TestsEnvironment::kMatrTypesNumber));

INSTANTIATE_TEST_SUITE_P(
    EMatrixUTests, EMatrixDeterminantTSuite,
    testing::Range(0, TestsEnvironment::uform_matr_number_*
                          TestsEnvironment::kMatrTypesNumber));

INSTANTIATE_TEST_SUITE_P(
    EMatrixUTests, EMatrixInverseMatrixTSuite,
    testing::Range(1, 1 + TestsEnvironment::uform_matr_number_));

INSTANTIATE_TEST_SUITE_P(
    EMatrixUTests, EMatrixOperatorsOverloadsTSuite,
    testing::Range(0, TestsEnvironment::uform_matr_number_*
                          TestsEnvironment::kMatrTypesNumber));

}  // namespace e_matrix
