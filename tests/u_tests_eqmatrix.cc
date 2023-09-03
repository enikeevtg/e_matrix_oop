#include "e_matrix_u_tests_environment.h"
#include "e_matrix_u_tests_fixture.h"

TEST_P(EMatrixUTestsFixture, EqMatrixPosMatricesTrue) {
  int i = GetParam();
  EMatrix test_matrix{TestsEnvironment::ut_matrices_arr_[i]};
  EXPECT_TRUE(TestsEnvironment::ut_matrices_arr_[i].EqMatrix(test_matrix));
}

TEST_P(EMatrixUTestsFixture, EqMatrixPosMatricesFalse) {
  int i = GetParam();
  EMatrix test_matrix{TestsEnvironment::ut_matrices_tr_arr_[i]};
  EXPECT_FALSE(TestsEnvironment::ut_matrices_arr_[i].EqMatrix(test_matrix));
}
