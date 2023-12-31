#include "../e_matrix_oop.h"

namespace e_matrix {

/// @brief Copy Constructor
/// @param other
EMatrix::EMatrix(const EMatrix& other)
    : rows_(other.rows_), cols_(other.cols_), inline_size_(other.inline_size_) {
  std::cout << "EMatrix(const EMatrix& other) {" << std::endl;
  std::cout << "\tmatrix = " << this << std::endl;
  std::cout << "\tmatrix.matrix_ = " << matrix_ << std::endl;
  std::cout << "\tmatrix.rows_ = " << rows_ << std::endl;
  std::cout << "\tmatrix.cols_ = " << cols_ << std::endl;

  CreateMatrix();
  std::copy(&other.matrix_[0][0], &other.matrix_[0][other.inline_size_],
            matrix_[0]);

  std::cout << "\t\t// copied from: other.matrix_ = " << other.matrix_
            << std::endl;
  std::cout << "\tmatrix = " << this << std::endl;
  std::cout << "\tmatrix.matrix_ = " << matrix_ << std::endl;
  std::cout << "\tmatrix.rows_ = " << rows_ << std::endl;
  std::cout << "\tmatrix.cols_ = " << cols_ << std::endl;
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
    EMatrix matrix_copy{other};

    *this = std::move(matrix_copy);

    std::cout << "\tmatrix_dest after copying:" << std::endl;
    PrintMatrix();
  }

  std::cout << "\t}  // operator=(const EMatrix& other)" << std::endl;

  return *this;
}

/// @brief Move constructor
/// @param other
EMatrix::EMatrix(EMatrix&& other) noexcept {
  std::cout << "EMatrix(EMatrix&& other) {" << std::endl;
  std::cout << "\tmatrix = " << this << std::endl;
  std::cout << "\tmatrix.matrix_ = " << matrix_ << std::endl;
  std::cout << "\tmatrix.rows_ = " << rows_ << std::endl;
  std::cout << "\tmatrix.cols_ = " << cols_ << std::endl;

  // EMatrix::operator=(other);
  *this = std::move(other);

  std::cout << "\t  // moved from: other.matrix_ = " << other.matrix_
            << std::endl;
  std::cout << "\tmatrix = " << this << std::endl;
  std::cout << "\tmatrix.matrix_ = " << matrix_ << std::endl;
  std::cout << "\tmatrix.rows_ = " << rows_ << std::endl;
  std::cout << "\tmatrix.cols_ = " << cols_ << std::endl;
  PrintMatrix();

  std::cout << "}  //EMatrix(EMatrix&& other)" << std::endl;
}

/// @brief Move assignment operator
/// @param other
/// @return
EMatrix& EMatrix::operator=(EMatrix&& other) noexcept {
  std::cout << "\toperator=(EMatrix&& other) {" << std::endl;
  std::cout << "\t\tmatrix = " << this << std::endl;
  std::cout << "\t\tmatrix.matrix_ = " << matrix_ << std::endl;
  std::cout << "\t\tmatrix.rows_ = " << rows_ << std::endl;
  std::cout << "\t\tmatrix.cols_ = " << cols_ << std::endl;

  if (this != &other) {
    DeleteMatrix();
    rows_ = other.rows_;
    cols_ = other.cols_;
    inline_size_ = other.inline_size_;
    matrix_ = other.matrix_;

    other.rows_ = 0;
    other.cols_ = 0;
    other.inline_size_ = 0;
    other.matrix_ = nullptr;
  }
  std::cout << "\t}  // operator=(EMatrix&& other)" << std::endl;

  return *this;
}

/// @brief Destructor
EMatrix::~EMatrix() {
  std::cout << "~EMatrix() {" << std::endl;
  std::cout << "\tmatrix = " << this << std::endl;
  std::cout << "\tmatrix.matrix_ = " << matrix_ << std::endl;
  std::cout << "\tmatrix.rows_ = " << rows_ << std::endl;
  std::cout << "\tmatrix.cols_ = " << cols_ << std::endl;

  DeleteMatrix();

  std::cout << "\tmatrix = " << this << std::endl;
  std::cout << "\tmatrix.matrix_ = " << matrix_ << std::endl;
  std::cout << "\tmatrix.rows_ = " << rows_ << std::endl;
  std::cout << "\tmatrix.cols_ = " << cols_ << std::endl;
  std::cout << "}  //~EMatrix()" << std::endl;
}

}  // namespace e_matrix
