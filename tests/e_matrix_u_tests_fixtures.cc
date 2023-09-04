#include "e_matrix_u_tests_fixtures.h"

INSTANTIATE_TEST_SUITE_P(
    EMatrixUTests, EMatrixEqMatrixSuite,
    testing::Range(0, TestsEnvironment::uform_matrices_number_*
                          TestsEnvironment::kEMatrixTypesNumber));

INSTANTIATE_TEST_SUITE_P(
    EMatrixUTests, EMatrixSumSubTSuite,
    testing::Range(0, TestsEnvironment::uform_matrices_number_*
                          TestsEnvironment::kEMatrixTypesNumber));
