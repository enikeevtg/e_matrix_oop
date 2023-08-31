#include "u_tests.h"

void EMatrixUTests::SetUp() {
  InitMatrices();
  FillMatrices();
}

void EMatrixUTests::InitMatrices() {
  fix_matrix_arr_sz_ = 5;

  fix_pos_row_matrix_arr = new EMatrix[fix_matrix_arr_sz_];
  fix_neg_row_matrix_arr = new EMatrix[fix_matrix_arr_sz_];
  fix_pos_x2_row_matrix_arr = new EMatrix[fix_matrix_arr_sz_];
  fix_pos_x2_column_matrix_arr = new EMatrix[fix_matrix_arr_sz_];

  fix_pos_column_matrix_arr = new EMatrix[fix_matrix_arr_sz_];
  fix_neg_column_matrix_arr = new EMatrix[fix_matrix_arr_sz_];
  fix_neg_x2_row_matrix_arr = new EMatrix[fix_matrix_arr_sz_];
  fix_neg_x2_column_matrix_arr = new EMatrix[fix_matrix_arr_sz_];

  fix_unity_matrix_arr = new EMatrix[fix_matrix_arr_sz_];

  fix_pos_square_matrix_arr = new EMatrix[fix_matrix_arr_sz_];
  fix_neg_square_matrix_arr = new EMatrix[fix_matrix_arr_sz_];
  fix_pos_x2_square_matrix_arr = new EMatrix[fix_matrix_arr_sz_];
  fix_neg_x2_square_matrix_arr = new EMatrix[fix_matrix_arr_sz_];

  fix_pos_rect_long_matrix_arr = new EMatrix[fix_matrix_arr_sz_];
  fix_neg_rect_long_matrix_arr = new EMatrix[fix_matrix_arr_sz_];
  fix_pos_x2_rect_long_matrix_arr = new EMatrix[fix_matrix_arr_sz_];
  fix_neg_x2_rect_long_matrix_arr = new EMatrix[fix_matrix_arr_sz_];

  fix_pos_rect_high_matrix_arr = new EMatrix[fix_matrix_arr_sz_];
  fix_neg_rect_high_matrix_arr = new EMatrix[fix_matrix_arr_sz_];
  fix_pos_x2_rect_high_matrix_arr = new EMatrix[fix_matrix_arr_sz_];
  fix_neg_x2_rect_high_matrix_arr = new EMatrix[fix_matrix_arr_sz_];

  for (int i = 0; i < fix_matrix_arr_sz_; ++i) {
    fix_pos_row_matrix_arr[i].SetDimensions(1, i + 1);
    fix_neg_row_matrix_arr[i].SetDimensions(1, i + 1);
    fix_pos_x2_row_matrix_arr[i].SetDimensions(1, i + 1);
    fix_pos_x2_column_matrix_arr[i].SetDimensions(1, i + 1);

    fix_pos_column_matrix_arr[i].SetDimensions(i + 1, 1);
    fix_neg_column_matrix_arr[i].SetDimensions(i + 1, 1);
    fix_neg_x2_row_matrix_arr[i].SetDimensions(i + 1, 1);
    fix_neg_x2_column_matrix_arr[i].SetDimensions(i + 1, 1);

    fix_unity_matrix_arr[i].SetDimensions(i + 1, i + 1);

    fix_pos_square_matrix_arr[i].SetDimensions(i + 1, i + 1);
    fix_neg_square_matrix_arr[i].SetDimensions(i + 1, i + 1);
    fix_pos_x2_square_matrix_arr[i].SetDimensions(i + 1, i + 1);
    fix_neg_x2_square_matrix_arr[i].SetDimensions(i + 1, i + 1);

    fix_pos_rect_long_matrix_arr[i].SetDimensions(i + 2, i + 5);
    fix_neg_rect_long_matrix_arr[i].SetDimensions(i + 2, i + 5);
    fix_pos_x2_rect_long_matrix_arr[i].SetDimensions(i + 2, i + 5);
    fix_neg_x2_rect_long_matrix_arr[i].SetDimensions(i + 2, i + 5);
  }
}

void EMatrixUTests::FillMatrices() {
  for (int i = 0; i < fix_matrix_arr_sz_; ++i) {
    for (int j = 1; j <= i + 1; ++j) {
      fix_pos_row_matrix_arr[i](1, j) = 10 * j + j;
      fix_pos_row_matrix_arr[i](j, 1) = 10 * j + j;
      fix_unity_matrix_arr[i](j, j) = 1;
    }

    for (int j = 1; j <= i + 1; ++j) {
      for (int k = 1; k <= i + 1; ++k) {
        fix_pos_square_matrix_arr[i](j, k) = j * 10 + k;
        fix_neg_square_matrix_arr[i](j, k) = -(j * 10 + k);
        fix_pos_x2_square_matrix_arr[i](j, k) = 2 * (j * 10 + k);
        fix_neg_x2_square_matrix_arr[i](j, k) = -2 * (j * 10 + k);
      }
    }
  }  // for (int i = 0; i < fix_matrix_arr_sz_; ++i)
}

void EMatrixUTests::TearDown() {
  delete[] fix_pos_square_matrix_arr;
  delete[] fix_neg_square_matrix_arr;
  delete[] fix_unity_matrix_arr;
}

INSTANTIATE_TEST_SUITE_P(EMatrixUTests, EMatrixParametrizedUTest,
                         ::testing::Values(0, 1, 2, 3, 4));

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
