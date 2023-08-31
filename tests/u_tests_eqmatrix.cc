#include "u_tests.h"

TEST_P(EMatrixParametrizedUTest, EqMatrixPosMatricesTrue) {
  int i = GetParam();
  EMatrix test_matrix{fix_pos_square_matrix_arr[i]};
  EXPECT_TRUE(fix_pos_square_matrix_arr[i].EqMatrix(test_matrix));
}

TEST_P(EMatrixParametrizedUTest, EqMatrixNegMatricesTrue) {
  int i = GetParam();
  EMatrix test_matrix{fix_neg_square_matrix_arr[i]};
  EXPECT_TRUE(fix_neg_square_matrix_arr[i].EqMatrix(test_matrix));
}

TEST_P(EMatrixParametrizedUTest, EqMatrixPosMatricesFalse) {
  int i = GetParam();
  EMatrix test_matrix{fix_neg_square_matrix_arr[i]};
  EXPECT_FALSE(fix_pos_square_matrix_arr[i].EqMatrix(test_matrix));
}

TEST_P(EMatrixParametrizedUTest, EqMatrixNegMatricesFalse) {
  int i = GetParam();
  EMatrix test_matrix{fix_pos_square_matrix_arr[i]};
  EXPECT_FALSE(fix_neg_square_matrix_arr[i].EqMatrix(test_matrix));
}

TEST_P(EMatrixParametrizedUTest, EqMatrixMatricesDimensionsFalse) {
  int i = GetParam();
  EMatrix test_matrix{fix_matrix_arr_sz_, fix_matrix_arr_sz_};
  EXPECT_FALSE(fix_pos_square_matrix_arr[i].EqMatrix(test_matrix));
}
