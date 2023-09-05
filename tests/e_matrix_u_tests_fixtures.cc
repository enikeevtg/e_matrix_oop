#include "e_matrix_u_tests_fixtures.h"

INSTANTIATE_TEST_SUITE_P(
    EMatrixUTests, EMatrixRuleOfFiveTSuite,
    testing::Range(0, TestsEnvironment::uform_matrices_number_*
                          TestsEnvironment::kEMatrixTypesNumber));

INSTANTIATE_TEST_SUITE_P(
    EMatrixUTests, EMatrixAccessorsMutators,
    testing::Range(1, 1 + TestsEnvironment::uform_matrices_number_));

INSTANTIATE_TEST_SUITE_P(
    EMatrixUTests, EMatrixEqMatrixTSuite,
    testing::Range(0, TestsEnvironment::uform_matrices_number_*
                          TestsEnvironment::kEMatrixTypesNumber));

INSTANTIATE_TEST_SUITE_P(
    EMatrixUTests, EMatrixSumSubTSuite,
    testing::Range(0, TestsEnvironment::uform_matrices_number_*
                          TestsEnvironment::kEMatrixTypesNumber));

INSTANTIATE_TEST_SUITE_P(
    EMatrixUTests, EMatrixMulTSuite,
    testing::Range(0, TestsEnvironment::uform_matrices_number_*
                          TestsEnvironment::kEMatrixTypesNumber));

INSTANTIATE_TEST_SUITE_P(
    EMatrixUTests, EMatrixTransposeTSuite,
    testing::Range(0, TestsEnvironment::uform_matrices_number_*
                          TestsEnvironment::kEMatrixTypesNumber));

INSTANTIATE_TEST_SUITE_P(
    EMatrixUTests, EMatrixOperatorsOverloadsTSuite,
    testing::Range(0, TestsEnvironment::uform_matrices_number_*
                          TestsEnvironment::kEMatrixTypesNumber));
