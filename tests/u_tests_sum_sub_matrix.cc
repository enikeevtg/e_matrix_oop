#include "e_matrix_u_tests_environment.h"
#include "e_matrix_u_tests_fixtures.h"

namespace e_matrix {

//=============================================================================
// void SumMatrix(const EMatrix& other);
//=============================================================================

TEST_P(EMatrixSumSubTSuite, SumMatrixThrowRangeErr1) {
  int i = GetParam();
  EMatrix test_matrix;

  EXPECT_THROW(test_matrix.SumMatrix(TestsEnvironment::ut_matr_arr_[i]),
               std::range_error);
}

TEST_P(EMatrixSumSubTSuite, SumMatrixThrowRangeErr2) {
  int i = GetParam();
  int rows = TestsEnvironment::ut_matr_arr_[i].get_rows();
  int cols = TestsEnvironment::ut_matr_arr_[i].get_cols();
  EMatrix test_matrix(rows + 1, cols);

  EXPECT_THROW(test_matrix.SumMatrix(TestsEnvironment::ut_matr_arr_[i]),
               std::range_error);
}

TEST_P(EMatrixSumSubTSuite, SumMatrixThrowRangeErr3) {
  int i = GetParam();
  int rows = TestsEnvironment::ut_matr_arr_[i].get_rows();
  int cols = TestsEnvironment::ut_matr_arr_[i].get_cols();
  EMatrix test_matrix(rows, cols + 1);

  EXPECT_THROW(test_matrix.SumMatrix(TestsEnvironment::ut_matr_arr_[i]),
               std::range_error);
}

TEST_P(EMatrixSumSubTSuite, SumMatrixOk0) {
  int i = GetParam();
  int rows = TestsEnvironment::ut_matr_arr_[i].get_rows();
  int cols = TestsEnvironment::ut_matr_arr_[i].get_cols();
  EMatrix test_matrix(rows, cols);
  test_matrix.SumMatrix(TestsEnvironment::ut_matr_arr_[i]);

  EXPECT_TRUE(test_matrix.EqMatrix(TestsEnvironment::ut_matr_arr_[i]));
}

TEST_P(EMatrixSumSubTSuite, SumMatrixOk1) {
  int i = GetParam();
  EMatrix test_matrix(TestsEnvironment::ut_matr_arr_[i]);
  test_matrix.SumMatrix(TestsEnvironment::ut_matr_arr_[i]);

  EXPECT_TRUE(test_matrix.EqMatrix(TestsEnvironment::ut_matr_x2_arr_[i]));
}

//=============================================================================
// void SubMatrix(const EMatrix& other);
//=============================================================================

TEST_P(EMatrixSumSubTSuite, SubMatrixThrowRangeErr1) {
  int i = GetParam();
  EMatrix test_matrix;

  EXPECT_THROW(test_matrix.SubMatrix(TestsEnvironment::ut_matr_arr_[i]),
               std::range_error);
}

TEST_P(EMatrixSumSubTSuite, SubMatrixThrowRangeErr2) {
  int i = GetParam();
  int rows = TestsEnvironment::ut_matr_arr_[i].get_rows();
  int cols = TestsEnvironment::ut_matr_arr_[i].get_cols();
  EMatrix test_matrix(rows + 1, cols);

  EXPECT_THROW(test_matrix.SubMatrix(TestsEnvironment::ut_matr_arr_[i]),
               std::range_error);
}

TEST_P(EMatrixSumSubTSuite, SubMatrixThrowRangeErr3) {
  int i = GetParam();
  int rows = TestsEnvironment::ut_matr_arr_[i].get_rows();
  int cols = TestsEnvironment::ut_matr_arr_[i].get_cols();
  EMatrix test_matrix(rows, cols + 1);

  EXPECT_THROW(test_matrix.SumMatrix(TestsEnvironment::ut_matr_arr_[i]),
               std::range_error);
}

TEST_P(EMatrixSumSubTSuite, SubMatrixOk0) {
  int i = GetParam();
  int rows = TestsEnvironment::ut_matr_arr_[i].get_rows();
  int cols = TestsEnvironment::ut_matr_arr_[i].get_cols();
  EMatrix test_matrix_nills(rows, cols);
  EMatrix test_matrix(TestsEnvironment::ut_matr_arr_[i]);
  test_matrix.SubMatrix(TestsEnvironment::ut_matr_arr_[i]);

  EXPECT_TRUE(test_matrix.EqMatrix(test_matrix_nills));
}

TEST_P(EMatrixSumSubTSuite, SubMatrixOk1) {
  int i = GetParam();
  EMatrix test_matrix(TestsEnvironment::ut_matr_x2_arr_[i]);
  test_matrix.SubMatrix(TestsEnvironment::ut_matr_arr_[i]);

  EXPECT_TRUE(test_matrix.EqMatrix(TestsEnvironment::ut_matr_arr_[i]));
}

}  // namespace e_matrix
