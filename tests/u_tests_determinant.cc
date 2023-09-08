#include "e_matrix_u_tests_environment.h"
#include "e_matrix_u_tests_fixtures.h"

namespace e_matrix {

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

TEST(EMatrixDeterminantTSuiteManual, DeterminantOkNillElement1) {
  int sz = 3;
  EMatrix test_matrix(sz, sz);
  double elem_value = 1.f;
  for (int i = 1; i <= sz; ++i) {
    for (int j = 1; j <= sz; ++j) {
      test_matrix(i, j) = elem_value;
      elem_value += 1.f;
    }
  }                         // -> {{1 2 3} {4 5 6} {7 8 9}}
  test_matrix(1, 1) = 0.f;  // -> {{0 2 3} {4 5 6} {7 8 9}}

  double det = 3.f;

  EXPECT_EQ(test_matrix.Determinant(), det);
}

TEST(EMatrixDeterminantTSuiteManual, DeterminantOkNillElement1and4) {
  int sz = 3;
  EMatrix test_matrix(sz, sz);
  double elem_value = 1;
  for (int i = 1; i <= sz; ++i) {
    for (int j = 1; j <= sz; ++j) {
      test_matrix(i, j) = elem_value;
      elem_value += 1.f;
    }
  }                         // -> {{1 2 3} {4 5 6} {7 8 9}}
  test_matrix(1, 1) = 0.f;  // -> {{0 2 3} {4 5 6} {7 8 9}}
  test_matrix(2, 1) = 0.f;  // -> {{0 2 3} {0 5 6} {7 8 9}}

  double det = -21.f;

  EXPECT_EQ(test_matrix.Determinant(), det);
}

TEST(EMatrixDeterminantTSuiteManual, DeterminantOkNillElement11) {
  int sz = 3;
  EMatrix test_matrix(sz, sz);
  for (int i = 1; i <= sz; ++i) {
    for (int j = 1; j <= sz; ++j) {
      test_matrix(i, j) = 10.f * i + j;
    }
  }                         // {{11 12 13} {21 22 23} {31 32 33}}
  test_matrix(1, 1) = 0.f;  // {{ 0 12 13} {21 22 23} {31 32 33}}

  double det = 110.f;

  EXPECT_EQ(test_matrix.Determinant(), det);
}

}  // namespace e_matrix
