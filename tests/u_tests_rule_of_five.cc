#include "e_matrix_u_tests_environment.h"
#include "e_matrix_u_tests_fixtures.h"

namespace e_matrix {

TEST_P(EMatrixRuleOfFiveTSuite, CopyConstructor) {
  int i = GetParam();
  EMatrix test_matrix(TestsEnvironment::ut_matr_arr_[i]);

  EXPECT_TRUE(test_matrix.EqMatrix(TestsEnvironment::ut_matr_arr_[i]));
}

TEST_P(EMatrixRuleOfFiveTSuite, CopyAssignment) {
  int i = GetParam();
  EMatrix test_matrix;
  test_matrix = TestsEnvironment::ut_matr_arr_[i];

  EXPECT_TRUE(test_matrix.EqMatrix(TestsEnvironment::ut_matr_arr_[i]));
}

TEST_P(EMatrixRuleOfFiveTSuite, MoveConstructor) {
  int i = GetParam();
  EMatrix test_matrix(TestsEnvironment::ut_matr_arr_[i]);
  EMatrix test_matrix_move(std::move(test_matrix));

  EXPECT_EQ(test_matrix.get_rows(), 0);
  EXPECT_EQ(test_matrix.get_cols(), 0);
  EXPECT_TRUE(test_matrix_move.EqMatrix(TestsEnvironment::ut_matr_arr_[i]));
}

TEST_P(EMatrixRuleOfFiveTSuite, MoveAssignment) {
  int i = GetParam();
  EMatrix test_matrix(TestsEnvironment::ut_matr_arr_[i]);
  EMatrix test_matrix_res;
  test_matrix_res = std::move(test_matrix);

  EXPECT_EQ(test_matrix.get_rows(), 0);
  EXPECT_EQ(test_matrix.get_cols(), 0);
  EXPECT_TRUE(test_matrix_res.EqMatrix(TestsEnvironment::ut_matr_arr_[i]));
}

}  // namespace e_matrix
