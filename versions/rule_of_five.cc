#include "../e_matrix_oop.h"

/// @brief Destructor
EMatrix::~EMatrix() {
  std::cout << "matrix destructor begin: " << matrix_ << "( " << rows_ << ", "
            << cols_ << " )" << std::endl;

  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      if (matrix_[i] != nullptr) {
        delete[] matrix_[i];
        matrix_[i] = nullptr;
      }
    }
    delete matrix_;
    matrix_ = nullptr;
    rows_ = 0;
    cols_ = 0;
  }

  std::cout << "matrix destructor end:   " << matrix_ << "( " << rows_ << ", "
            << cols_ << " )" << std::endl;
}

/// @brief Copy assignment operator
/// @param other
/// @return
EMatrix::EMatrix(const EMatrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  std::cout << "EMatrix(const EMatrix& other) {" << std::endl;
  std::cout << "\tmatrix_ = " << matrix_ << std::endl;
  std::cout << "\trows_ = " << rows_ << std::endl;
  std::cout << "\tcols_ = " << cols_ << std::endl;

  CreateMatrix();

  size_t last_inline_index = rows_ * cols_;
  for (size_t i = 0; i < last_inline_index; i++) {
    matrix_[0][i] = other.matrix_[0][i] + 1;
  }

  std::cout << "\t  // copied from: other.matrix_ = " << other.matrix_
            << std::endl;
  PrintMatrix();

  std::cout << "}  //EMatrix(const EMatrix& other)" << std::endl;
}

/// @brief Copy assignment operator
/// @param other
/// @return
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

    std::cout << "\tmatrix_dest after copying:" << std::endl;
    PrintMatrix();
  }

  std::cout << "\t}  // operator=(const EMatrix& other)" << std::endl;

  return *this;
}
