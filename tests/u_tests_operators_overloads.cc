#include "e_matrix_u_tests_environment.h"
#include "e_matrix_u_tests_fixtures.h"

namespace e_matrix {

//=============================================================================
// EMatrix operator+(const EMatrix& other);
//=============================================================================

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorPlusThrowInvalidArg) {
  int i = GetParam();
  EMatrix test_matrix;

  EXPECT_THROW(test_matrix + TestsEnvironment::ut_matr_arr_[i],
               std::invalid_argument);
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorPlusThrowRangeErr1) {
  int i = GetParam();
  EMatrix test_matrix;

  EXPECT_THROW(TestsEnvironment::ut_matr_arr_[i] + test_matrix,
               std::range_error);
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorPlusThrowRangeErr2) {
  int i = GetParam();
  int rows = TestsEnvironment::ut_matr_arr_[i].get_rows();
  int cols = TestsEnvironment::ut_matr_arr_[i].get_cols();
  EMatrix test_matrix(rows + 1, cols);

  EXPECT_THROW(test_matrix + TestsEnvironment::ut_matr_arr_[i],
               std::range_error);
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorPlusThrowRangeErr3) {
  int i = GetParam();
  int rows = TestsEnvironment::ut_matr_arr_[i].get_rows();
  int cols = TestsEnvironment::ut_matr_arr_[i].get_cols();
  EMatrix test_matrix(rows, cols + 1);

  EXPECT_THROW(test_matrix + TestsEnvironment::ut_matr_arr_[i],
               std::range_error);
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorPlusOk0) {
  int i = GetParam();
  int rows = TestsEnvironment::ut_matr_arr_[i].get_rows();
  int cols = TestsEnvironment::ut_matr_arr_[i].get_cols();
  EMatrix test_matrix(rows, cols);
  EMatrix test_res_matrix = test_matrix + TestsEnvironment::ut_matr_arr_[i];

  EXPECT_TRUE(test_res_matrix.EqMatrix(TestsEnvironment::ut_matr_arr_[i]));
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorPlusOk1) {
  int i = GetParam();
  EMatrix test_matrix(TestsEnvironment::ut_matr_arr_[i]);
  EMatrix test_res_matrix = test_matrix + TestsEnvironment::ut_matr_arr_[i];

  EXPECT_TRUE(test_res_matrix.EqMatrix(TestsEnvironment::ut_matr_x2_arr_[i]));
}


//=============================================================================
// EMatrix operator-(const EMatrix& other);
//=============================================================================

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorMinusThrowInvalidArg) {
  int i = GetParam();
  EMatrix test_matrix;

  EXPECT_THROW(test_matrix - TestsEnvironment::ut_matr_arr_[i],
               std::invalid_argument);
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorMinusThrowRangeErr1) {
  int i = GetParam();
  EMatrix test_matrix;

  EXPECT_THROW(TestsEnvironment::ut_matr_arr_[i] - test_matrix,
               std::range_error);
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorMinusThrowRangeErr2) {
  int i = GetParam();
  int rows = TestsEnvironment::ut_matr_arr_[i].get_rows();
  int cols = TestsEnvironment::ut_matr_arr_[i].get_cols();
  EMatrix test_matrix(rows + 1, cols);

  EXPECT_THROW(test_matrix - TestsEnvironment::ut_matr_arr_[i],
               std::range_error);
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorMinusThrowRangeErr3) {
  int i = GetParam();
  int rows = TestsEnvironment::ut_matr_arr_[i].get_rows();
  int cols = TestsEnvironment::ut_matr_arr_[i].get_cols();
  EMatrix test_matrix(rows, cols + 1);

  EXPECT_THROW(test_matrix - TestsEnvironment::ut_matr_arr_[i],
               std::range_error);
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorMinusOk0) {
  int i = GetParam();
  int rows = TestsEnvironment::ut_matr_arr_[i].get_rows();
  int cols = TestsEnvironment::ut_matr_arr_[i].get_cols();
  EMatrix test_matrix(rows, cols);
  EMatrix test_res_matrix = TestsEnvironment::ut_matr_arr_[i] - test_matrix;

  EXPECT_TRUE(test_res_matrix.EqMatrix(TestsEnvironment::ut_matr_arr_[i]));
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorMinusOk1) {
  int i = GetParam();
  EMatrix test_matrix(TestsEnvironment::ut_matr_x2_arr_[i]);
  EMatrix test_res_matrix = test_matrix - TestsEnvironment::ut_matr_arr_[i];

  EXPECT_TRUE(test_res_matrix.EqMatrix(TestsEnvironment::ut_matr_arr_[i]));
}


//=============================================================================
// operator()(int row, int col) const;
//=============================================================================

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

}  // namespace e_matrix
