#include "e_matrix_u_tests_environment.h"
#include "e_matrix_u_tests_fixtures.h"

TEST_P(EMatrixSumSubTSuite, MulNumberOk) {
  int i = GetParam();
  int n = TestsEnvironment::uform_matrices_number_;
  int i_src = i / n / 2 * 2 * n + i % n;
  int i_res = (i / n / 2 * 2 + 1) * n + i % n;

  EMatrix test_matrix{TestsEnvironment::ut_matrices_arr_[i_src]};
  test_matrix.MulNumber(2);

  EXPECT_TRUE(TestsEnvironment::ut_matrices_arr_[i_res].EqMatrix(test_matrix));
}
