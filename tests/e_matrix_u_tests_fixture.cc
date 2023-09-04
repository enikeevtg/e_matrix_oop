#include "e_matrix_u_tests_fixture.h"

void EMatrixUTestsFixture::SetUp() {
  // EMatrix* ut_matrices_arr_ = ;
  // EMatrix* ut_matrices_tr_arr_ = ;
}

/*

EMatrixUTestsFixture::EMatrixUTestsFixture()
    : uniform_matrices_number_(5),
      uniform_types_matrices_number_(41),
      all_test_matrices_(nullptr) {
  InitTestMatrices();
  FillTestMatrices();
}

EMatrixUTestsFixture::~EMatrixUTestsFixture() {
  if (all_test_matrices_) delete[] all_test_matrices_;
}

// void EMatrixUTestsFixture::SetUp() {
//   InitTestMatrices();
//   FillTestMatrices();
// }

// void EMatrixUTestsFixture::TearDown() {
//   if (all_test_matrices_) delete[] all_test_matrices_;
// }

void EMatrixUTestsFixture::InitTestMatrices() {
  size_t all_test_matrices_sz =
      uniform_matrices_number_ * uniform_types_matrices_number_;
  all_test_matrices_ = new EMatrix[all_test_matrices_sz];
  EMatrix* all_test_matrices_ptr;

  // ROW MATRICES
  all_test_matrices_ptr = all_test_matrices_;
  row_matrix_pos_indices_val_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  row_matrix_pos_indices_val_tr_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  row_matrix_pos_indices_valx2_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  row_matrix_pos_indices_valx2_tr_arr = all_test_matrices_ptr;

  all_test_matrices_ptr += uniform_matrices_number_;
  row_matrix_neg_indices_val_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  row_matrix_neg_indices_val_tr_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  row_matrix_neg_indices_valx2_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  row_matrix_neg_indices_valx2_tr_arr = all_test_matrices_ptr;

  // COLUMN MATRICES
  all_test_matrices_ptr += uniform_matrices_number_;
  column_matrix_pos_indices_val_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  column_matrix_pos_indices_val_tr_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  column_matrix_pos_indices_valx2_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  column_matrix_pos_indices_valx2_tr_arr = all_test_matrices_ptr;

  all_test_matrices_ptr += uniform_matrices_number_;
  column_matrix_neg_indices_val_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  column_matrix_neg_indices_val_tr_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  column_matrix_neg_indices_valx2_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  column_matrix_neg_indices_valx2_tr_arr = all_test_matrices_ptr;

  // SQUARE MATRICES
  all_test_matrices_ptr += uniform_matrices_number_;
  square_matrix_pos_indices_val_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  square_matrix_pos_indices_val_tr_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  square_matrix_pos_indices_valx2_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  square_matrix_pos_indices_valx2_tr_arr = all_test_matrices_ptr;

  all_test_matrices_ptr += uniform_matrices_number_;
  square_matrix_neg_indices_val_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  square_matrix_neg_indices_val_tr_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  square_matrix_neg_indices_valx2_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  square_matrix_neg_indices_valx2_tr_arr = all_test_matrices_ptr;

  // VERTICAL RECTANGULAR MATRICES
  all_test_matrices_ptr += uniform_matrices_number_;
  vert_rect_matrix_pos_indices_val_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  vert_rect_matrix_pos_indices_val_tr_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  vert_rect_matrix_pos_indices_valx2_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  vert_rect_matrix_pos_indices_valx2_tr_arr = all_test_matrices_ptr;

  all_test_matrices_ptr += uniform_matrices_number_;
  vert_rect_matrix_neg_indices_val_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  vert_rect_matrix_neg_indices_val_tr_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  vert_rect_matrix_neg_indices_valx2_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  vert_rect_matrix_neg_indices_valx2_tr_arr = all_test_matrices_ptr;

  // HORIZONTAL RECTANGULAR MATRICES
  all_test_matrices_ptr += uniform_matrices_number_;
  horiz_rect_matrix_pos_indices_val_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  horiz_rect_matrix_pos_indices_val_tr_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  horiz_rect_matrix_pos_indices_valx2_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  horiz_rect_matrix_pos_indices_valx2_tr_arr = all_test_matrices_ptr;

  all_test_matrices_ptr += uniform_matrices_number_;
  horiz_rect_matrix_neg_indices_val_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  horiz_rect_matrix_neg_indices_val_tr_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  horiz_rect_matrix_neg_indices_valx2_arr = all_test_matrices_ptr;
  all_test_matrices_ptr += uniform_matrices_number_;
  horiz_rect_matrix_neg_indices_valx2_tr_arr = all_test_matrices_ptr;

  // UNITY MATRICES
  all_test_matrices_ptr += uniform_matrices_number_;
  unity_matrix_arr = all_test_matrices_ptr;

  for (int i = 0; i < uniform_matrices_number_; ++i) {
    row_matrix_pos_indices_val_arr[i].SetDimensions(1, i + 1);
    row_matrix_pos_indices_val_tr_arr[i].SetDimensions(1, i + 1);
    row_matrix_pos_indices_valx2_arr[i].SetDimensions(1, i + 1);
    row_matrix_pos_indices_valx2_tr_arr[i].SetDimensions(1, i + 1);

    row_matrix_neg_indices_val_arr[i].SetDimensions(1, i + 1);
    row_matrix_neg_indices_val_tr_arr[i].SetDimensions(1, i + 1);
    row_matrix_neg_indices_valx2_arr[i].SetDimensions(1, i + 1);
    row_matrix_neg_indices_valx2_tr_arr[i].SetDimensions(1, i + 1);

    column_matrix_pos_indices_val_arr[i].SetDimensions(i + 1, 1);
    column_matrix_pos_indices_val_tr_arr[i].SetDimensions(i + 1, 1);
    column_matrix_pos_indices_valx2_arr[i].SetDimensions(i + 1, 1);
    column_matrix_pos_indices_valx2_tr_arr[i].SetDimensions(i + 1, 1);

    column_matrix_neg_indices_val_arr[i].SetDimensions(i + 1, 1);
    column_matrix_neg_indices_val_tr_arr[i].SetDimensions(i + 1, 1);
    column_matrix_neg_indices_valx2_arr[i].SetDimensions(i + 1, 1);
    column_matrix_neg_indices_valx2_tr_arr[i].SetDimensions(i + 1, 1);

    unity_matrix_arr[i].SetDimensions(i + 1, i + 1);
  }
}

void EMatrixUTestsFixture::FillTestMatrices() {
  for (int i = 0; i < uniform_matrices_number_; ++i) {
    for (int j = 1; j <= i + 1; ++j) {
      row_matrix_pos_indices_val_arr[i](1, j) = 10 * j + j;
      column_matrix_pos_indices_val_arr[i](j, 1) = 10 * j + j;
      unity_matrix_arr[i](j, j) = 1;
    }

    for (int j = 1; j <= i + 1; ++j) {
      for (int k = 1; k <= i + 1; ++k) {
        square_matrix_pos_indices_val_arr[i](j, k) = j * 10 + k;
        square_matrix_neg_indices_val_arr[i](j, k) = -(j * 10 + k);
        square_matrix_pos_indices_valx2_arr[i](j, k) = 2 * (j * 10 + k);
        square_matrix_neg_indices_valx2_arr[i](j, k) = -2 * (j * 10 + k);
      }
    }
  }  // for (int i = 0; i < matrix_arr_sz_; ++i)
}


*/
