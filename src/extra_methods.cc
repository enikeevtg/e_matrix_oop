#include <iostream>

#include "../e_matrix_oop.h"

namespace e_matrix {

void EMatrix::SetDimensions(int rows, int cols) {
  EMatrix buffer_matrix{rows, cols};

  int rows_bound = std::min(rows_, rows);
  int cols_bound = std::min(cols_, cols);
  for (int i = 0; i < rows_bound; ++i) {
    for (int j = 0; j < cols_bound; ++j) {
      buffer_matrix.matrix_[i][j] = matrix_[i][j];
    }
  }

  Swap(buffer_matrix);
}

/// @brief Matrix minor creation method
/// @param cur_row
/// @param cur_col
/// @return Minor matrix
EMatrix EMatrix::CreateMinor(int cur_row, int cur_col) const {
  EMatrix minor(rows_ - 1, cols_ - 1);
  int k = 0;
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      if (!(i == cur_row - 1 || j == cur_col - 1)) {  // -1 to CreateMinor()
                                                      // origin with (1, 1)
        minor.matrix_[0][k] = matrix_[i][j];
        ++k;
      }
    }
  }

  return minor;
}

void EMatrix::PrintMatrix() const noexcept {
  if (matrix_) {
    std::cout << this << ":" << std::endl;
    std::cout << "\t" << matrix_ << ":" << std::endl;
    for (int i = 0; i < rows_; ++i) {
      std::cout << "\t\t" << matrix_[i] << ":";
      for (int j = 0; j < cols_; ++j) {
        std::cout << " " << matrix_[i][j];
      }
      std::cout << std::endl;
    }
  }
}

}  // namespace e_matrix
