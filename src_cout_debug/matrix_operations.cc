#include "../e_matrix_oop.h"

namespace e_matrix {

/// @brief Checks matrices for equality with each other
/// @param other
/// @return Checking result
bool EMatrix::EqMatrix(const EMatrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) return DIFFERENT_MATRICES;

  bool check = EQUAL_MATRICES;
  for (size_t i = 0; check == EQUAL_MATRICES && i < inline_size_; ++i) {
    if (matrix_[0][i] != other.matrix_[0][i]) {
      check = DIFFERENT_MATRICES;
    }
  }

  return check;
}

/// @brief Adds the other matrix to the current one
/// @param other
void EMatrix::SumMatrix(const EMatrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::range_error(
        "SumMatrix() error: matrices have different dimentions");

  SumOrSubMatrix(other, MATRICES_SUMMATION);
}

/// @brief Subtracts other matrix from the current one
/// @param other
void EMatrix::SubMatrix(const EMatrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::range_error(
        "SubMatrix() error: matrices have different dimentions");

  SumOrSubMatrix(other, MATRICES_SUBTRACTION);
}

/// @brief Multiplies the current matrix by a number
/// @param num
void EMatrix::MulNumber(const double num) {
  for (size_t i = 0; i < inline_size_; ++i) {
    matrix_[0][i] *= num;
  }
}

}  // namespace e_matrix
