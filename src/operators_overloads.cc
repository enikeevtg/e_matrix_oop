#include <stdexcept>

#include "../e_matrix_oop.h"

namespace e_matrix {

EMatrix EMatrix::operator+(const EMatrix& other) const {
  EMatrix matrix(*this);
  matrix.SumMatrix(other);
  return matrix;
}

EMatrix EMatrix::operator-(const EMatrix& other) const {
  EMatrix matrix(*this);
  matrix.SubMatrix(other);
  return matrix;
}

EMatrix EMatrix::operator*(const EMatrix& other) const {
  EMatrix matrix(*this);
  matrix.MulMatrix(other);
  return matrix;
}

EMatrix EMatrix::operator*(const double& num) const {
  EMatrix matrix(*this);
  matrix.MulNumber(num);
  return matrix;
}

EMatrix operator*(const double& num, EMatrix& matrix) {
  return matrix * num;
}

bool EMatrix::operator==(const EMatrix& other) const noexcept {
  return EqMatrix(other);
}

void EMatrix::operator+=(const EMatrix& other) { return SumMatrix(other); }

void EMatrix::operator-=(const EMatrix& other) { return SubMatrix(other); }

void EMatrix::operator*=(const double& num) noexcept { MulNumber(num); }

void EMatrix::operator*=(const EMatrix& other) { MulMatrix(other); }

double EMatrix::operator()(int row, int column) const {
  if (row < 1 || column < 1 || row > rows_ || column > cols_) {
    throw std::out_of_range("Matrix(i, j): index is outside the matrix");
  }

  return matrix_[row - 1][column - 1];
}

double& EMatrix::operator()(int row, int column) {
  if (row < 1 || column < 1 || row > rows_ || column > cols_) {
    throw std::out_of_range("Matrix(i, j): index is outside the matrix");
  }

  return matrix_[row - 1][column - 1];
}

}  // namespace e_matrix
