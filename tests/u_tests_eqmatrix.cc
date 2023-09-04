#include "e_matrix_u_tests_environment.h"
#include "e_matrix_u_tests_fixtures.h"

TEST_P(EMatrixEqMatrixSuite, EqMatrixTrue) {
  int i = GetParam();
  EMatrix test_matrix{TestsEnvironment::ut_matrices_arr_[i]};
  EXPECT_TRUE(TestsEnvironment::ut_matrices_arr_[i].EqMatrix(test_matrix));
}

TEST_P(EMatrixEqMatrixSuite, EqMatrixFalse) {
  int i = GetParam();
  EMatrix test_matrix{TestsEnvironment::ut_matrices_tr_arr_[i]};
  EXPECT_FALSE(TestsEnvironment::ut_matrices_arr_[i].EqMatrix(test_matrix));
}
