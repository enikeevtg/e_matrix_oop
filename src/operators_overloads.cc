#include "../e_matrix_oop.h"

EMatrix& EMatrix::operator=(const EMatrix& other) {
  std::cout << "\toperator=(const EMatrix& other) {" << std::endl;
  std::cout << "\t\tmatrix_ = " << matrix_ << std::endl;
  std::cout << "\t\trows_ = " << rows_ << std::endl;
  std::cout << "\t\tcols_ = " << cols_ << std::endl;

  if (this != &other) {
    DeleteMatrix();
    rows_ = other.rows_;
    cols_ = other.cols_;
    std::copy((double*)other.matrix_ + other.rows_,
            (double*)other.matrix_ + other.rows_ * (1 + other.cols_),
            (double*)matrix_ + rows_);
  }

  std::cout << "\t}  // operator=(const EMatrix& other)" << std::endl;

  return *this;
}

EMatrix& EMatrix::operator=(EMatrix&& other) {
  std::cout << "\toperator=(EMatrix&& other) {" << std::endl;
  std::cout << "\t\tmatrix_ = " << matrix_ << std::endl;
  std::cout << "\t\trows_ = " << rows_ << std::endl;
  std::cout << "\t\tcols_ = " << cols_ << std::endl;

  if (this != &other) {
    DeleteMatrix();
    matrix_ = other.matrix_;
    rows_ = other.rows_;
    cols_ = other.cols_;

    other.matrix_ = nullptr;
    other.rows_ = 0;
    other.cols_ = 0;
  }
  std::cout << "\t}  // operator=(EMatrix&& other)" << std::endl;

  return *this;
}
