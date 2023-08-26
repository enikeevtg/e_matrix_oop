#include "../e_matrix_oop.h"

EMatrix::EMatrix() {
  std::cout << "EMatrix() {" << std::endl;
  std::cout << "\tmatrix = " << this << std::endl;
  std::cout << "\tmatrix.matrix_ = " << matrix_ << std::endl;
  std::cout << "\tmatrix.rows_ = " << rows_ << std::endl;
  std::cout << "\tmatrix.cols_ = " << cols_ << std::endl;
  std::cout << "}  // EMatrix()" << std::endl;
}

EMatrix::EMatrix(int rows, int cols) : rows_(rows), cols_(cols) {
  std::cout << "EMatrix(int rows, int cols) {" << std::endl;
  std::cout << "\tmatrix = " << this << std::endl;
  std::cout << "\tmatrix.matrix_ = " << matrix_ << std::endl;
  std::cout << "\tmatrix.rows_ = " << rows_ << std::endl;
  std::cout << "\tmatrix.cols_ = " << cols_ << std::endl;

  if (rows_ > 0 && cols_ > 0) {
    CreateMatrix();
  }

  std::cout << "}  // EMatrix(int rows, int cols)" << std::endl;
}
