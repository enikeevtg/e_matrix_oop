#include "u_tests.h"

TEST_P(EMatrixParametrizedUTest, EqMatrixPosMatricesTrue) {
  int i = GetParam();
  EMatrix test_matrix{square_matrix_pos_indices_val_arr[i]};
  EXPECT_TRUE(square_matrix_pos_indices_val_arr[i].EqMatrix(test_matrix));
}

TEST_P(EMatrixParametrizedUTest, EqMatrixNegMatricesTrue) {
  int i = GetParam();
  EMatrix test_matrix{square_matrix_neg_indices_val_arr[i]};
  EXPECT_TRUE(square_matrix_neg_indices_val_arr[i].EqMatrix(test_matrix));
}

TEST_P(EMatrixParametrizedUTest, EqMatrixPosMatricesFalse) {
  int i = GetParam();
  EMatrix test_matrix{square_matrix_neg_indices_val_arr[i]};
  EXPECT_FALSE(square_matrix_pos_indices_val_arr[i].EqMatrix(test_matrix));
}

TEST_P(EMatrixParametrizedUTest, EqMatrixNegMatricesFalse) {
  int i = GetParam();
  EMatrix test_matrix{square_matrix_pos_indices_val_arr[i]};
  EXPECT_FALSE(square_matrix_neg_indices_val_arr[i].EqMatrix(test_matrix));
}

TEST_P(EMatrixParametrizedUTest, EqMatrixMatricesDimensionsFalse) {
  int i = GetParam();
  EXPECT_FALSE(row_matrix_pos_indices_val_arr[i].EqMatrix(column_matrix_pos_indices_val_arr[i]));
}
