#include "../e_matrix_oop.h"

namespace e_matrix {

void EMatrix::PrintMatrix() {
  std::cout << "\t\tprintMatrix() {" << std::endl;

  for (int i = 0; i < rows_; ++i) {
    std::cout << "\t\t\t" << matrix_[i] << ":";
    for (int j = 0; j < cols_; ++j) {
      std::cout << std::fixed;  // вывод в фиксированном формате
      std::cout.precision(6);  // вывод до 6 знака после точки, включительно
      std::cout << " " << matrix_[i][j];
    }
    std::cout << std::endl;
  }

  std::cout << "\t\t}  // PrintMatrix()" << std::endl;
}

}  // namespace e_matrix
