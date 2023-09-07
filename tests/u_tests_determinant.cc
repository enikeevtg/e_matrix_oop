#include "e_matrix_u_tests_environment.h"
#include "e_matrix_u_tests_fixtures.h"

TEST_P(EMatrixDeterminantTSuite, DeterminantThrow) {
  int i = GetParam();
  if (TestsEnvironment::ut_matr_arr_[i].get_rows() !=
      TestsEnvironment::ut_matr_arr_[i].get_cols()) {
    EXPECT_THROW(TestsEnvironment::ut_matr_arr_[i].Determinant(),
                 std::range_error);
  }
}

TEST_P(EMatrixDeterminantTSuite, DeterminantOk) {
  int i = GetParam();
  if (TestsEnvironment::ut_matr_arr_[i].get_rows() ==
      TestsEnvironment::ut_matr_arr_[i].get_cols()) {
    EXPECT_EQ(TestsEnvironment::ut_matr_arr_[i].Determinant(),
              TestsEnvironment::ut_det_arr_[i]);
  }
}
