#include "../e_matrix_oop.h"

void EMatrix::PrintMatrix() {
  std::cout << "\t\tprintMatrix() {" << std::endl;

  for (int i = 0; i < rows_; ++i) {
    std::cout << "\t\t\t" << matrix_[i] << ":";
    for (int j = 0; j < cols_; ++j) {
      std::cout << " " << matrix_[i][j];
    }
    std::cout << std::endl;
  }

  std::cout << "\t\t}  // PrintMatrix()" << std::endl;
}
