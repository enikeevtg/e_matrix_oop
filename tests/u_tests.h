#ifndef E_MATRIXPLUS_TESTS_UNIT_TESTS_H_
#define E_MATRIXPLUS_TESTS_UNIT_TESTS_H_

#include <gtest/gtest.h>

#include "../e_matrix_oop.h"

class EMatrixUTests : public testing::Test {
 protected:
  void SetUp() override;
  void TearDown() override;

  void InitMatrices();
  void FillMatrices();

  int fix_matrix_arr_sz_;
  EMatrix* fix_pos_row_matrix_arr;
  EMatrix* fix_neg_row_matrix_arr;
  EMatrix* fix_pos_x2_row_matrix_arr;
  EMatrix* fix_pos_x2_column_matrix_arr;

  EMatrix* fix_pos_column_matrix_arr;
  EMatrix* fix_neg_column_matrix_arr;
  EMatrix* fix_neg_x2_row_matrix_arr;
  EMatrix* fix_neg_x2_column_matrix_arr;

  EMatrix* fix_unity_matrix_arr;

  EMatrix* fix_pos_square_matrix_arr;
  EMatrix* fix_neg_square_matrix_arr;
  EMatrix* fix_pos_x2_square_matrix_arr;
  EMatrix* fix_neg_x2_square_matrix_arr;

  EMatrix* fix_pos_rect_long_matrix_arr;
  EMatrix* fix_neg_rect_long_matrix_arr;
  EMatrix* fix_pos_x2_rect_long_matrix_arr;
  EMatrix* fix_neg_x2_rect_long_matrix_arr;

  EMatrix* fix_pos_rect_high_matrix_arr;
  EMatrix* fix_neg_rect_high_matrix_arr;
  EMatrix* fix_pos_x2_rect_high_matrix_arr;
  EMatrix* fix_neg_x2_rect_high_matrix_arr;
};

class EMatrixParametrizedUTest : public EMatrixUTests,
                                 public testing::WithParamInterface<int> {};

#endif  // E_MATRIXPLUS_TESTS_UNIT_TESTS_H_
