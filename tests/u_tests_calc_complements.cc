#include "e_matrix_u_tests_environment.h"
#include "e_matrix_u_tests_fixtures.h"

namespace e_matrix {

TEST_P(EMatrixCalcComplementsTSuite, CalcComplementsThrow) {
  int i = GetParam();
  if (TestsEnvironment::ut_matr_arr_[i].get_rows() !=
      TestsEnvironment::ut_matr_arr_[i].get_cols()) {
    EXPECT_THROW(TestsEnvironment::ut_matr_arr_[i].CalcComplements(),
                 std::range_error);
  }
}

TEST(EMatrixCalcComplementsTSuiteManual, CalcComplementsOkNills) {
  int sz = 3;
  EMatrix test_matrix(sz, sz);
  EMatrix test_ref_matrix(sz, sz);
  EMatrix test_res_matrix = test_matrix.CalcComplements();

  EXPECT_TRUE(test_res_matrix.EqMatrix(test_ref_matrix));
}

TEST(EMatrixCalcComplementsTSuiteManual, CalcComplementsOk1x1) {
  int sz = 1;
  EMatrix test_matrix(sz, sz);
  test_matrix(1, 1) = 11;

  EMatrix test_ref_matrix(sz, sz);
  test_ref_matrix(1, 1) = 11;

  EMatrix test_res_matrix = test_matrix.CalcComplements();

  EXPECT_TRUE(test_res_matrix.EqMatrix(test_ref_matrix));
}

TEST(EMatrixCalcComplementsTSuiteManual, CalcComplementsOk2x2) {
  int sz = 2;
  EMatrix test_matrix(sz, sz);
  double elem_value = 1.f;
  for (int i = 1; i <= sz; ++i) {
    for (int j = 1; j <= sz; ++j) {
      test_matrix(i, j) = elem_value;
      elem_value += 1.f;
    }
  }  // -> {{1 2} {3 4}}

  EMatrix test_ref_matrix(sz, sz);
  test_ref_matrix(1, 1) = 4.f;
  test_ref_matrix(1, 2) = -3.f;
  test_ref_matrix(2, 1) = -2.f;
  test_ref_matrix(2, 2) = 1.f;

  EMatrix test_res_matrix = test_matrix.CalcComplements();

  EXPECT_TRUE(test_res_matrix.EqMatrix(test_ref_matrix));
}

TEST(EMatrixCalcComplementsTSuiteManual, CalcComplementsOk3x3) {
  int sz = 3;
  EMatrix test_matrix(sz, sz);
  double elem_value = 1.f;
  for (int i = 1; i <= sz; ++i) {
    for (int j = 1; j <= sz; ++j) {
      test_matrix(i, j) = elem_value;
      elem_value += 1.f;
    }
  }  // -> {{1 2 3} {4 5 6} {7 8 9}}

  EMatrix test_ref_matrix(sz, sz);
  double ref_tmp[9] = {-3.f, 6.f, -3.f, 6.f, -12.f, 6.f, -3.f, 6.f, -3.f};
  for (int i = 1; i <= sz; ++i) {
    for (int j = 1; j <= sz; ++j) {
      test_ref_matrix(i, j) = ref_tmp[(i - 1) * sz + (j - 1)];
    }
  }

  EMatrix test_res_matrix = test_matrix.CalcComplements();

  EXPECT_TRUE(test_res_matrix.EqMatrix(test_ref_matrix));
}

TEST(EMatrixCalcComplementsTSuiteManual, CalcComplementsOk4x4) {
  int sz = 4;
  EMatrix test_matrix(sz, sz);
  double elem_value = 1.f;
  for (int i = 1; i <= sz; ++i) {
    for (int j = 1; j <= sz; ++j) {
      test_matrix(i, j) = elem_value;
      elem_value += 1.f;
    }
  }  // -> {{1 2 3 4} {5 6 7 8} {9 10 11 12} {13 14 15 16}}

  EMatrix test_ref_matrix(sz, sz);

  EMatrix test_res_matrix = test_matrix.CalcComplements();

  EXPECT_TRUE(test_res_matrix.EqMatrix(test_ref_matrix));
}

}  // namespace e_matrix
