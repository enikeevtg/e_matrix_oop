#include "e_matrix_u_tests_environment.h"
#include "e_matrix_u_tests_fixtures.h"

namespace e_matrix {

TEST_P(EMatrixMulTSuite, MulNumberOkHalf) {
  int i = GetParam();
  EMatrix test_matrix(TestsEnvironment::ut_matr_x2_arr_[i]);
  test_matrix.MulNumber(0.5f);

  EXPECT_TRUE(test_matrix.EqMatrix(TestsEnvironment::ut_matr_arr_[i]));
}

TEST_P(EMatrixMulTSuite, MulNumberOkTwix) {
  int i = GetParam();
  EMatrix test_matrix(TestsEnvironment::ut_matr_arr_[i]);
  test_matrix.MulNumber(2.f);

  EXPECT_TRUE(test_matrix.EqMatrix(TestsEnvironment::ut_matr_x2_arr_[i]));
}

}  // namespace e_matrix
