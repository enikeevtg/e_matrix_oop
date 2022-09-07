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

void EMatrix::PrintMatrix() noexcept {
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
