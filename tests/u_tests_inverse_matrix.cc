#include "e_matrix_u_tests_environment.h"
#include "e_matrix_u_tests_fixtures.h"

namespace e_matrix {

TEST_P(EMatrixInverseMatrixTSuite, InverseMatrixThrowNillMatrices) {
  int sz = GetParam();
  EMatrix test_matrix(sz, sz);

  EXPECT_THROW(test_matrix.InverseMatrix(), std::invalid_argument);
}

TEST_P(EMatrixInverseMatrixTSuite, InverseMatrixThrowNillDet) {
  int sz = GetParam() + 2;
  EMatrix test_matrix(sz, sz);
  for (int i = 1; i <= sz; ++i) {
    for (int j = 1; j <= sz; ++j) {
      test_matrix(i, j) = 10.f * i + j;
    }
  }  // {{11 12 13...} {21 22 23...} {31 32 33...}...}

  EXPECT_THROW(test_matrix.InverseMatrix(), std::invalid_argument);
}

TEST(EMatrixInverseMatrixTSuiteManual, InverseMatrixOk1x1) {
  int sz = 1;
  EMatrix test_matrix(sz, sz);
  test_matrix(1, 1) = 11;

  EMatrix test_ref_matrix(sz, sz);
  test_ref_matrix(1, 1) = 1.f / test_matrix(1, 1);

  EMatrix test_res_matrix = test_matrix.InverseMatrix();

  EXPECT_TRUE(test_res_matrix.EqMatrix(test_ref_matrix));
}

TEST(EMatrixInverseMatrixTSuiteManual, InverseMatrixOk2x2) {
  int sz = 2;
  EMatrix test_matrix(sz, sz);
  for (int i = 1; i <= sz; ++i) {
    for (int j = 1; j <= sz; ++j) {
      test_matrix(i, j) = 10.f * i + j;
    }
  }  // {{11 12} {21 22}}

  EMatrix test_ref_matrix(sz, sz);
  double ref_tmp[4] = {-2.2f, 1.2f, 2.1f, -1.1f};
  for (int i = 1; i <= sz; ++i) {
    for (int j = 1; j <= sz; ++j) {
      test_ref_matrix(i, j) = ref_tmp[(i - 1) * sz + (j - 1)];
    }
  }

  EMatrix test_res_matrix = test_matrix.InverseMatrix();

  EXPECT_TRUE(test_res_matrix.EqMatrix(test_ref_matrix));
}

TEST(EMatrixInverseMatrixTSuiteManual, InverseMatrixOk3x3) {
  int sz = 3;
  EMatrix test_matrix(sz, sz);
  double tmp[9] = {2.f, 5.f, 7.f, 6.f, 3.f, 4.f, 5.f, -2.f, -3.f};
  for (int i = 1; i <= sz; ++i) {
    for (int j = 1; j <= sz; ++j) {
      test_matrix(i, j) = tmp[(i - 1) * sz + (j - 1)];
    }
  }

  EMatrix test_ref_matrix(sz, sz);
  double ref_tmp[9] = {1.f, -1.f, 1.f, -38.f, 41.f, -34.f, 27.f, -29.f, 24.f};
  for (int i = 1; i <= sz; ++i) {
    for (int j = 1; j <= sz; ++j) {
      test_ref_matrix(i, j) = ref_tmp[(i - 1) * sz + (j - 1)];
    }
  }

  EMatrix test_res_matrix = test_matrix.InverseMatrix();

  EXPECT_TRUE(test_res_matrix.EqMatrix(test_ref_matrix));
}

TEST(EMatrixInverseMatrixTSuiteManual, InverseMatrixOk4x4) {
  int sz = 4;
  EMatrix test_matrix(sz, sz);
  double tmp[16] = {10.f, 1.f, 0.f, 6.f, -8.f, -3.f, 2.f, 0.f,
                    9.f,  4.f, 6.f, 6.f, 10.f, 5.f,  8.f, 7.f};
  for (int i = 1; i <= sz; ++i) {
    for (int j = 1; j <= sz; ++j) {
      test_matrix(i, j) = tmp[(i - 1) * sz + (j - 1)];
    }
  }

  EMatrix test_ref_matrix(sz, sz);
  double ref_tmp[16] = {-11.f,  3.f,  95.f,  -72.f, 21.f, -6.f, -182.f, 138.f,
                        -12.5f, 3.5f, 107.f, -81.f, 15.f, -4.f, -128.f, 97.f};
  for (int i = 1; i <= sz; ++i) {
    for (int j = 1; j <= sz; ++j) {
      test_ref_matrix(i, j) = ref_tmp[(i - 1) * sz + (j - 1)];
    }
  }

  EMatrix test_res_matrix = test_matrix.InverseMatrix();

  EXPECT_TRUE(test_res_matrix.EqMatrix(test_ref_matrix));
}

}  // namespace e_matrix
