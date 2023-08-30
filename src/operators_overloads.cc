#include "../e_matrix_oop.h"

double& EMatrix::operator()(int row, int column) const {
  if (row < 1 || column < 1 || row > rows_ || column > cols_) {
    throw std::out_of_range("Matrix(i, j): index is outside the matrix");
  }

  return matrix_[row - 1][column - 1];
}
