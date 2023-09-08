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
// EMatrix operator*(const double& num);
//=============================================================================

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorMulNumberOkHalf) {
  int i = GetParam();
  EMatrix test_matrix = TestsEnvironment::ut_matr_x2_arr_[i] * 0.5f;

  EXPECT_TRUE(test_matrix.EqMatrix(TestsEnvironment::ut_matr_arr_[i]));
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorMulNumberOkTwix) {
  int i = GetParam();
  EMatrix test_matrix = TestsEnvironment::ut_matr_arr_[i] * 2.f;

  EXPECT_TRUE(test_matrix.EqMatrix(TestsEnvironment::ut_matr_x2_arr_[i]));
}

//=============================================================================
// EMatrix operator*(const double& num, EMatrix& matrix);
//=============================================================================

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorMulNumberFriendOkHalf) {
  int i = GetParam();
  double num = 0.5f;
  EMatrix test_matrix = num * TestsEnvironment::ut_matr_x2_arr_[i];

  EXPECT_TRUE(test_matrix.EqMatrix(TestsEnvironment::ut_matr_arr_[i]));
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorMulNumberFriendOkTwix) {
  int i = GetParam();
  double num = 2.f;
  EMatrix test_matrix = num * TestsEnvironment::ut_matr_arr_[i];

  EXPECT_TRUE(test_matrix.EqMatrix(TestsEnvironment::ut_matr_x2_arr_[i]));
}

//=============================================================================
// EMatrix operator*(const EMatrix& other);
//=============================================================================

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorMulMatrixThrowInvalidArgFirst) {
  int i = GetParam();
  EMatrix test_matrix;  // matrix_ = nullptr

  EXPECT_THROW(test_matrix * TestsEnvironment::ut_matr_arr_[i],
               std::invalid_argument);
}

TEST_P(EMatrixOperatorsOverloadsTSuite,
       OperatorMulMatrixThrowInvalidArgSecond) {
  int i = GetParam();
  EMatrix test_matrix;  // matrix_ = nullptr

  EXPECT_THROW(TestsEnvironment::ut_matr_arr_[i] * test_matrix,
               std::invalid_argument);
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorMulMatrixThrowRangeErr) {
  int i = GetParam();
  int rows = TestsEnvironment::ut_matr_arr_[i].get_cols() + 1;
  int cols = TestsEnvironment::ut_matr_arr_[i].get_rows();
  EMatrix test_matrix(rows, cols);

  EXPECT_THROW(TestsEnvironment::ut_matr_arr_[i] * test_matrix,
               std::range_error);
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorMulMatrixNillsOk) {
  int i = GetParam();
  int rows = TestsEnvironment::ut_matr_arr_[i].get_cols();
  int cols = TestsEnvironment::ut_matr_arr_[i].get_rows();
  EMatrix test_matrix(rows, cols);
  EMatrix test_matrix_nills(rows, rows);  // res dimension is (rows_1, cols_2)
  EMatrix test_res_matrix = test_matrix * TestsEnvironment::ut_matr_arr_[i];

  EXPECT_TRUE(test_res_matrix.EqMatrix(test_matrix_nills));
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorMulMatrixUnityThrowRangeErr) {
  int i = GetParam();
  int n = TestsEnvironment::uform_matr_number_;
  EMatrix test_matrix(TestsEnvironment::ut_matr_arr_[i]);

  if (test_matrix.get_cols() !=
      TestsEnvironment::ut_unity_matr_arr_[i % n].get_rows()) {
    EXPECT_THROW(test_matrix * TestsEnvironment::ut_unity_matr_arr_[i % n],
                 std::range_error);
  }
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorMulMatrixUnityOk) {
  int i = GetParam();
  int n = TestsEnvironment::uform_matr_number_;
  EMatrix test_matrix(TestsEnvironment::ut_matr_arr_[i]);

  if (test_matrix.get_cols() ==
      TestsEnvironment::ut_unity_matr_arr_[i % n].get_rows()) {
    EMatrix test_res_matrix =
        test_matrix * TestsEnvironment::ut_unity_matr_arr_[i % n];
    EXPECT_TRUE(test_res_matrix.EqMatrix(TestsEnvironment::ut_matr_arr_[i]));
  }
}

//=============================================================================
// operator==(int row, int col) const;
//=============================================================================

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorEqMatrixTrue) {
  int i = GetParam();
  EMatrix test_matrix(TestsEnvironment::ut_matr_arr_[i]);

  EXPECT_TRUE(TestsEnvironment::ut_matr_arr_[i] == test_matrix);
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorEqMatrixFalse) {
  int i = GetParam();
  EMatrix test_matrix(TestsEnvironment::ut_matr_tr_arr_[i]);

  EXPECT_FALSE(TestsEnvironment::ut_matr_arr_[i] == test_matrix);
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorEqMatrixFalseRows) {
  int i = GetParam();
  int rows = TestsEnvironment::ut_matr_tr_arr_[i].get_rows();
  int cols = TestsEnvironment::ut_matr_tr_arr_[i].get_cols();
  EMatrix test_matrix(rows + 1, cols);

  EXPECT_FALSE(TestsEnvironment::ut_matr_arr_[i] == test_matrix);
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorEqMatrixFalseCols) {
  int i = GetParam();
  int rows = TestsEnvironment::ut_matr_tr_arr_[i].get_rows();
  int cols = TestsEnvironment::ut_matr_tr_arr_[i].get_cols();
  EMatrix test_matrix(rows, cols + 1);

  EXPECT_FALSE(TestsEnvironment::ut_matr_arr_[i] == test_matrix);
}

//=============================================================================
// EMatrix operator+=(const EMatrix& other);
//=============================================================================

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorPlusAssignThrowInvalidArg) {
  int i = GetParam();
  EMatrix test_matrix;

  EXPECT_THROW(test_matrix += TestsEnvironment::ut_matr_arr_[i],
               std::range_error);
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorPlusAssignThrowRangeErr1) {
  int i = GetParam();
  EMatrix test_matrix;

  EXPECT_THROW(TestsEnvironment::ut_matr_arr_[i] += test_matrix,
               std::range_error);
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorPlusAssignThrowRangeErr2) {
  int i = GetParam();
  int rows = TestsEnvironment::ut_matr_arr_[i].get_rows();
  int cols = TestsEnvironment::ut_matr_arr_[i].get_cols();
  EMatrix test_matrix(rows + 1, cols);

  EXPECT_THROW(test_matrix += TestsEnvironment::ut_matr_arr_[i],
               std::range_error);
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorPlusAssignThrowRangeErr3) {
  int i = GetParam();
  int rows = TestsEnvironment::ut_matr_arr_[i].get_rows();
  int cols = TestsEnvironment::ut_matr_arr_[i].get_cols();
  EMatrix test_matrix(rows, cols + 1);

  EXPECT_THROW(test_matrix += TestsEnvironment::ut_matr_arr_[i],
               std::range_error);
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorPlusAssignOk0) {
  int i = GetParam();
  int rows = TestsEnvironment::ut_matr_arr_[i].get_rows();
  int cols = TestsEnvironment::ut_matr_arr_[i].get_cols();
  EMatrix test_matrix(rows, cols);
  test_matrix += TestsEnvironment::ut_matr_arr_[i];

  EXPECT_TRUE(test_matrix.EqMatrix(TestsEnvironment::ut_matr_arr_[i]));
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorPlusAssignOk1) {
  int i = GetParam();
  EMatrix test_matrix(TestsEnvironment::ut_matr_arr_[i]);
  test_matrix += TestsEnvironment::ut_matr_arr_[i];

  EXPECT_TRUE(test_matrix.EqMatrix(TestsEnvironment::ut_matr_x2_arr_[i]));
}

//=============================================================================
// EMatrix operator-=(const EMatrix& other);
//=============================================================================

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorMinusAssignThrowInvalidArg) {
  int i = GetParam();
  EMatrix test_matrix;

  EXPECT_THROW(test_matrix -= TestsEnvironment::ut_matr_arr_[i],
               std::range_error);
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorMinusAssignThrowRangeErr1) {
  int i = GetParam();
  EMatrix test_matrix;

  EXPECT_THROW(TestsEnvironment::ut_matr_arr_[i] -= test_matrix,
               std::range_error);
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorMinusAssignThrowRangeErr2) {
  int i = GetParam();
  int rows = TestsEnvironment::ut_matr_arr_[i].get_rows();
  int cols = TestsEnvironment::ut_matr_arr_[i].get_cols();
  EMatrix test_matrix(rows + 1, cols);

  EXPECT_THROW(test_matrix -= TestsEnvironment::ut_matr_arr_[i],
               std::range_error);
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorMinusAssignThrowRangeErr3) {
  int i = GetParam();
  int rows = TestsEnvironment::ut_matr_arr_[i].get_rows();
  int cols = TestsEnvironment::ut_matr_arr_[i].get_cols();
  EMatrix test_matrix(rows, cols + 1);

  EXPECT_THROW(test_matrix -= TestsEnvironment::ut_matr_arr_[i],
               std::range_error);
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorMinusAssignOk0) {
  int i = GetParam();
  int rows = TestsEnvironment::ut_matr_arr_[i].get_rows();
  int cols = TestsEnvironment::ut_matr_arr_[i].get_cols();
  EMatrix test_matrix(rows, cols);
  EMatrix test_res_matrix = TestsEnvironment::ut_matr_arr_[i];
  test_res_matrix -= test_matrix;

  EXPECT_TRUE(test_res_matrix.EqMatrix(TestsEnvironment::ut_matr_arr_[i]));
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorMinusAssignOk1) {
  int i = GetParam();
  EMatrix test_matrix(TestsEnvironment::ut_matr_x2_arr_[i]);
  test_matrix -= TestsEnvironment::ut_matr_arr_[i];

  EXPECT_TRUE(test_matrix.EqMatrix(TestsEnvironment::ut_matr_arr_[i]));
}

//=============================================================================
// EMatrix operator*=(const double& num);
//=============================================================================

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorMulAssignNumberOkHalf) {
  int i = GetParam();
  EMatrix test_matrix(TestsEnvironment::ut_matr_x2_arr_[i]);
  test_matrix *= 0.5f;

  EXPECT_TRUE(test_matrix.EqMatrix(TestsEnvironment::ut_matr_arr_[i]));
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorMulAssignNumberOkTwix) {
  int i = GetParam();
  EMatrix test_matrix(TestsEnvironment::ut_matr_arr_[i]);
  test_matrix *= 2.f;

  EXPECT_TRUE(test_matrix.EqMatrix(TestsEnvironment::ut_matr_x2_arr_[i]));
}

//=============================================================================
// EMatrix operator*(const EMatrix& other);
//=============================================================================

TEST_P(EMatrixOperatorsOverloadsTSuite,
       OperatorMulAssignMatrixThrowInvalidArgFirst) {
  int i = GetParam();
  EMatrix test_matrix;  // matrix_ = nullptr

  EXPECT_THROW(test_matrix *= TestsEnvironment::ut_matr_arr_[i],
               std::invalid_argument);
}

TEST_P(EMatrixOperatorsOverloadsTSuite,
       OperatorMulAssignMatrixThrowInvalidArgSecond) {
  int i = GetParam();
  EMatrix test_matrix(TestsEnvironment::ut_matr_arr_[i]);
  EMatrix test_matrix_nullptr;  // matrix_ = nullptr

  EXPECT_THROW(test_matrix *= test_matrix_nullptr, std::invalid_argument);
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorMulAssignMatrixThrowRangeErr) {
  int i = GetParam();
  int rows = TestsEnvironment::ut_matr_arr_[i].get_cols() + 1;
  int cols = TestsEnvironment::ut_matr_arr_[i].get_rows();
  EMatrix test_matrix(TestsEnvironment::ut_matr_arr_[i]);
  EMatrix test_matrix_nills(rows, cols);

  EXPECT_THROW(test_matrix *= test_matrix_nills, std::range_error);
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorMulAssignMatrixNillsOk) {
  int i = GetParam();
  int rows = TestsEnvironment::ut_matr_arr_[i].get_cols();
  int cols = TestsEnvironment::ut_matr_arr_[i].get_rows();
  EMatrix test_matrix(rows, cols);
  EMatrix test_matrix_nills(rows, rows);  // res dimension is (rows_1, cols_2)
  test_matrix *= TestsEnvironment::ut_matr_arr_[i];

  EXPECT_TRUE(test_matrix == test_matrix_nills);
}

TEST_P(EMatrixOperatorsOverloadsTSuite,
       OperatorMulAssignMatrixUnityThrowRangeErr) {
  int i = GetParam();
  int n = TestsEnvironment::uform_matr_number_;
  EMatrix test_matrix(TestsEnvironment::ut_matr_arr_[i]);

  if (test_matrix.get_cols() !=
      TestsEnvironment::ut_unity_matr_arr_[i % n].get_rows()) {
    EXPECT_THROW(test_matrix *= TestsEnvironment::ut_unity_matr_arr_[i % n],
                 std::range_error);
  }
}

TEST_P(EMatrixOperatorsOverloadsTSuite, OperatorMulAssignMatrixUnityOk) {
  int i = GetParam();
  int n = TestsEnvironment::uform_matr_number_;
  EMatrix test_matrix(TestsEnvironment::ut_matr_arr_[i]);

  if (test_matrix.get_cols() ==
      TestsEnvironment::ut_unity_matr_arr_[i % n].get_rows()) {
    test_matrix *= TestsEnvironment::ut_unity_matr_arr_[i % n];
    EXPECT_TRUE(test_matrix == TestsEnvironment::ut_matr_arr_[i]);
  }
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
