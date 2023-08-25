#include "../e_matrix_oop.h"

EMatrix& EMatrix::operator=(const EMatrix& other) {
  std::cout << "\toperator=(const EMatrix& other) {" << std::endl;
  std::cout << "\t\tmatrix = " << this << std::endl;
  std::cout << "\t\tmatrix.matrix_ = " << matrix_ << std::endl;
  std::cout << "\t\tmatrix.rows_ = " << rows_ << std::endl;
  std::cout << "\t\tmatrix.cols_ = " << cols_ << std::endl;

  if (this != &other) {
    DeleteMatrix();
    rows_ = other.rows_;
    cols_ = other.cols_;
    CreateMatrix();
    std::copy((double*)other.matrix_ + other.rows_,
            (double*)other.matrix_ + other.rows_ * (1 + other.cols_),
            (double*)matrix_ + rows_);

    PrintMatrix();
  }

  std::cout << "\t}  // operator=(const EMatrix& other)" << std::endl;

  return *this;
}

EMatrix& EMatrix::operator=(EMatrix&& other) {
  std::cout << "\toperator=(EMatrix&& other) {" << std::endl;
  std::cout << "\t\tmatrix = " << this << std::endl;
  std::cout << "\t\tmatrix.matrix_ = " << matrix_ << std::endl;
  std::cout << "\t\tmatrix.rows_ = " << rows_ << std::endl;
  std::cout << "\t\tmatrix.cols_ = " << cols_ << std::endl;

  if (this != &other) {
    DeleteMatrix();
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = other.matrix_;

    other.matrix_ = nullptr;
    other.rows_ = 0;
    other.cols_ = 0;
  }
  std::cout << "\t}  // operator=(EMatrix&& other)" << std::endl;

  return *this;
}
