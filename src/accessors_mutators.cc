#include "../e_matrix_oop.h"

double** EMatrix::get_matrix() { return matrix_; }  // temp method

/// @brief rows_ accessor
/// @return matrix rows number
int EMatrix::get_rows() const noexcept { return rows_; }

/// @brief cols_ accessor
/// @return matrix columns number
int EMatrix::get_cols() const noexcept { return cols_; }

void EMatrix::set_rows(int rows) {
  set_dimensions(rows, cols_);
}

void EMatrix::set_cols(int cols) {
  set_dimensions(rows_, cols);
}

void EMatrix::set_dimensions(int rows, int cols) {
  EMatrix buffer_matrix{rows, cols};

  int rows_bound = std::min(rows_, rows);
  int cols_bound = std::min(cols_, cols);
  for (int i = 0; i < rows_bound; ++i) {
    for (int j = 0; j < cols_bound; ++j) {
      buffer_matrix.matrix_[i][j] = matrix_[i][j];
    }
  }

  swap(buffer_matrix);
}

