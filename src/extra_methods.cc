#include "../e_matrix_oop.h"

void EMatrix::PrintMatrix() {
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
