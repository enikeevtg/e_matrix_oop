#ifndef E_MATRIXPLUS_TESTS_U_TESTS_H_
#define E_MATRIXPLUS_TESTS_U_TESTS_H_

#include <gtest/gtest.h>

#include "e_matrix_u_tests_environment.h"

class EMatrixUTestsFixture : public ::testing::TestWithParam<int> {
 protected:
  void SetUp();
};

/*
 protected:
  EMatrixUTestsFixture();
  ~EMatrixUTestsFixture();

  // void SetUp() override;
  // void TearDown() override;
  void InitTestMatrices();
  void FillTestMatrices();

  int uniform_matrices_number_;
  int uniform_types_matrices_number_;
  EMatrix* all_test_matrices_;

  // ROW MATRICES
  // [11 12 ...], [11 12 ...]^T
  EMatrix* row_matrix_pos_indices_val_arr;
  EMatrix* row_matrix_pos_indices_val_tr_arr;
  // [11*2 12*2 ...], [11*2 12*2 ...]^T
  EMatrix* row_matrix_pos_indices_valx2_arr;
  EMatrix* row_matrix_pos_indices_valx2_tr_arr;

  // [-11 -12 ...], [-11 -12 ...]^T
  EMatrix* row_matrix_neg_indices_val_arr;
  EMatrix* row_matrix_neg_indices_val_tr_arr;
  // [-11*2 -12*2 ...], [-11*2 -12*2 ...]^T
  EMatrix* row_matrix_neg_indices_valx2_arr;
  EMatrix* row_matrix_neg_indices_valx2_tr_arr;

  // COLUMN MATRICES
  // [11 21 ...]^T, [11 21 ...]
  EMatrix* column_matrix_pos_indices_val_arr;
  EMatrix* column_matrix_pos_indices_val_tr_arr;
  // [11*2 21*2 ...]^T, [11*2 21*2 ...]
  EMatrix* column_matrix_pos_indices_valx2_arr;
  EMatrix* column_matrix_pos_indices_valx2_tr_arr;

  // [-11 -21 ...]^T, [-11 -21 ...]
  EMatrix* column_matrix_neg_indices_val_arr;
  EMatrix* column_matrix_neg_indices_val_tr_arr;
  // [-11*2 -21*2 ...]^T, [-11*2 -21*2 ...]
  EMatrix* column_matrix_neg_indices_valx2_arr;
  EMatrix* column_matrix_neg_indices_valx2_tr_arr;

  // SQUARE MATRICES
  // [[11 12 ...][21 22 ...] ...]
  EMatrix* square_matrix_pos_indices_val_arr;
  EMatrix* square_matrix_pos_indices_val_tr_arr;
  // [[11*2 12*2 ...][21*2 22*2 ...] ...]
  EMatrix* square_matrix_pos_indices_valx2_arr;
  EMatrix* square_matrix_pos_indices_valx2_tr_arr;

  // [[11 12 ...][21 22 ...] ...]
  EMatrix* square_matrix_neg_indices_val_arr;
  EMatrix* square_matrix_neg_indices_val_tr_arr;
  // [[11*2 12*2 ...][21*2 22*2 ...] ...]
  EMatrix* square_matrix_neg_indices_valx2_arr;
  EMatrix* square_matrix_neg_indices_valx2_tr_arr;

  // VERTICAL RECTANGULAR MATRICES
  // [[11 12 ...][21 22 ...] ...]
  EMatrix* vert_rect_matrix_pos_indices_val_arr;
  EMatrix* vert_rect_matrix_pos_indices_val_tr_arr;
  // [[11*2 12*2 ...][21*2 22*2 ...] ...]
  EMatrix* vert_rect_matrix_pos_indices_valx2_arr;
  EMatrix* vert_rect_matrix_pos_indices_valx2_tr_arr;

  // [[11 12 ...][21 22 ...] ...]
  EMatrix* vert_rect_matrix_neg_indices_val_arr;
  EMatrix* vert_rect_matrix_neg_indices_val_tr_arr;
  // [[11*2 12*2 ...][21*2 22*2 ...] ...]
  EMatrix* vert_rect_matrix_neg_indices_valx2_arr;
  EMatrix* vert_rect_matrix_neg_indices_valx2_tr_arr;

  // HORIZONTAL RECTANGULAR MATRICES
  // [[11 12 ...][21 22 ...] ...]
  EMatrix* horiz_rect_matrix_pos_indices_val_arr;
  EMatrix* horiz_rect_matrix_pos_indices_val_tr_arr;
  // [[11*2 12*2 ...][21*2 22*2 ...] ...]
  EMatrix* horiz_rect_matrix_pos_indices_valx2_arr;
  EMatrix* horiz_rect_matrix_pos_indices_valx2_tr_arr;

  // [[11 12 ...][21 22 ...] ...]
  EMatrix* horiz_rect_matrix_neg_indices_val_arr;
  EMatrix* horiz_rect_matrix_neg_indices_val_tr_arr;
  // [[11*2 12*2 ...][21*2 22*2 ...] ...]
  EMatrix* horiz_rect_matrix_neg_indices_valx2_arr;
  EMatrix* horiz_rect_matrix_neg_indices_valx2_tr_arr;

  // UNITY MATRICES
  EMatrix* unity_matrix_arr;

*/

#endif  // E_MATRIXPLUS_TESTS_U_TESTS_H_
