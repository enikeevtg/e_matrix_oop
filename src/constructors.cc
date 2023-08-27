#include "../e_matrix_oop.h"

/// @brief Default constructor
EMatrix::EMatrix() {
  std::cout << "EMatrix() {" << std::endl;
  std::cout << "\tmatrix = " << this << std::endl;
  std::cout << "\tmatrix.matrix_ = " << matrix_ << std::endl;
  std::cout << "\tmatrix.rows_ = " << rows_ << std::endl;
  std::cout << "\tmatrix.cols_ = " << cols_ << std::endl;
  std::cout << "}  // EMatrix()" << std::endl;
}

/// @brief Parametrized constructor with number of rows and columns
/// @param rows
/// @param cols
EMatrix::EMatrix(int rows, int cols)
    : rows_(rows), cols_(cols), inline_size_(rows * cols) {
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
