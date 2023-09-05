#include "e_matrix_u_tests_environment.h"
#include "e_matrix_u_tests_fixtures.h"

TEST_P(EMatrixMulTSuite, MulMatrixThrowInvalidArgFirst) {
  int i = GetParam();

  EMatrix test_matrix;  // matrix_ = nullptr

  EXPECT_THROW(test_matrix.MulMatrix(TestsEnvironment::ut_matrices_arr_[i]),
               std::invalid_argument);
}

TEST_P(EMatrixMulTSuite, MulMatrixThrowInvalidArgSecond) {
  int i = GetParam();

  EMatrix test_matrix;  // matrix_ = nullptr

  EXPECT_THROW(TestsEnvironment::ut_matrices_arr_[i].MulMatrix(test_matrix),
               std::invalid_argument);
}

TEST_P(EMatrixMulTSuite, MulMatrixThrowRangeErr) {
  int i = GetParam();

  EMatrix test_matrix(TestsEnvironment::ut_matrices_arr_[i].get_cols() + 1,
                      TestsEnvironment::ut_matrices_arr_[i].get_rows());

  EXPECT_THROW(TestsEnvironment::ut_matrices_arr_[i].MulMatrix(test_matrix),
               std::range_error);
}

TEST_P(EMatrixMulTSuite, MulMatrixNillsOk) {
  int i = GetParam();

  EMatrix test_matrix(TestsEnvironment::ut_matrices_arr_[i].get_cols(),
                      TestsEnvironment::ut_matrices_arr_[i].get_rows());
  EMatrix test_matrix_nills(test_matrix.get_rows(),
                            TestsEnvironment::ut_matrices_arr_[i].get_cols());

  test_matrix.MulMatrix(TestsEnvironment::ut_matrices_arr_[i]);
  EXPECT_TRUE(test_matrix.EqMatrix(test_matrix_nills));
}

TEST_P(EMatrixMulTSuite, MulMatrixUnityOk) {
  int i = GetParam();
  int n = TestsEnvironment::uform_matrices_number_;

  EMatrix test_matrix(TestsEnvironment::ut_matrices_arr_[i]);

  if (test_matrix.get_cols() ==
      TestsEnvironment::ut_unity_matrices_arr_[i % n].get_rows()) {
    test_matrix.MulMatrix(TestsEnvironment::ut_unity_matrices_arr_[i % n]);
    EXPECT_TRUE(TestsEnvironment::ut_matrices_arr_[i].EqMatrix(test_matrix));
  }
}

TEST_P(EMatrixMulTSuite, MulMatrixUnityThrow) {
  int i = GetParam();
  int n = TestsEnvironment::uform_matrices_number_;

  EMatrix test_matrix(TestsEnvironment::ut_matrices_arr_[i]);

  if (test_matrix.get_cols() !=
      TestsEnvironment::ut_unity_matrices_arr_[i % n].get_rows()) {
    ASSERT_THROW(
        test_matrix.MulMatrix(TestsEnvironment::ut_unity_matrices_arr_[i % n]),
        std::range_error);
  }
}
