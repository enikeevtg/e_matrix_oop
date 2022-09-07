#include "e_matrix_u_tests_environment.h"
#include "e_matrix_u_tests_fixtures.h"

namespace e_matrix {

TEST_P(EMatrixTransposeTSuite, TransposeOk) {
  int i = GetParam();
  EMatrix test_matrix = TestsEnvironment::ut_matr_arr_[i].Transpose();

  EXPECT_TRUE(test_matrix.EqMatrix(TestsEnvironment::ut_matr_tr_arr_[i]));
}

}  // namespace e_matrix
