#include "e_matrix_u_tests_environment.h"
#include "e_matrix_u_tests_fixtures.h"

TEST_P(EMatrixOperatorsOverloadsTSuite, BracesThrowNillIndices) {
  int i = GetParam();

  EXPECT_THROW(TestsEnvironment::ut_matr_arr_[i](0, 0), std::out_of_range);
  EXPECT_THROW(TestsEnvironment::ut_matr_arr_[i](0, 1), std::out_of_range);
  EXPECT_THROW(TestsEnvironment::ut_matr_arr_[i](1, 0), std::out_of_range);
}

TEST_P(EMatrixOperatorsOverloadsTSuite, BracesThrowNegIndices) {
  int i = GetParam();
  EXPECT_THROW(TestsEnvironment::ut_matr_arr_[i](-1, INT32_MIN),
               std::out_of_range);
}

TEST_P(EMatrixOperatorsOverloadsTSuite, BracesThrowPosIndices) {
  int i = GetParam();
  int row = TestsEnvironment::ut_matr_arr_[i].get_rows();
  int col = TestsEnvironment::ut_matr_arr_[i].get_cols();
  EXPECT_THROW(TestsEnvironment::ut_matr_arr_[i](row * 10, col * 100),
               std::out_of_range);
}

TEST_P(EMatrixOperatorsOverloadsTSuite, BracesOk) {
  int i = GetParam();
  int n = TestsEnvironment::uform_matr_number_;

  EXPECT_DOUBLE_EQ(TestsEnvironment::ut_unity_matr_arr_[i % n](1, 1), 1.f);
}
