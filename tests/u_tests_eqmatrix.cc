#include "e_matrix_u_tests_environment.h"
#include "e_matrix_u_tests_fixtures.h"

namespace e_matrix {

TEST_P(EMatrixEqMatrixTSuite, EqMatrixTrue) {
  int i = GetParam();
  EMatrix test_matrix(TestsEnvironment::ut_matr_arr_[i]);

  EXPECT_TRUE(TestsEnvironment::ut_matr_arr_[i].EqMatrix(test_matrix));
}

TEST_P(EMatrixEqMatrixTSuite, EqMatrixFalse) {
  int i = GetParam();
  EMatrix test_matrix(TestsEnvironment::ut_matr_tr_arr_[i]);

  EXPECT_FALSE(TestsEnvironment::ut_matr_arr_[i].EqMatrix(test_matrix));
}

TEST_P(EMatrixEqMatrixTSuite, EqMatrixFalseRows) {
  int i = GetParam();
  int rows = TestsEnvironment::ut_matr_tr_arr_[i].get_rows();
  int cols = TestsEnvironment::ut_matr_tr_arr_[i].get_cols();
  EMatrix test_matrix(rows + 1, cols);

  EXPECT_FALSE(TestsEnvironment::ut_matr_arr_[i].EqMatrix(test_matrix));
}

TEST_P(EMatrixEqMatrixTSuite, EqMatrixFalseCols) {
  int i = GetParam();
  int rows = TestsEnvironment::ut_matr_tr_arr_[i].get_rows();
  int cols = TestsEnvironment::ut_matr_tr_arr_[i].get_cols();
  EMatrix test_matrix(rows, cols + 1);

  EXPECT_FALSE(TestsEnvironment::ut_matr_arr_[i].EqMatrix(test_matrix));
}

}  // namespace e_matrix
