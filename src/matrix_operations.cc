#include "../e_matrix_oop.h"

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
        "SumMatrix error: matrices have different dimentions");

  SumOrSubMatrix(other, MATRICES_SUMMATION);
}

/// @brief Subtracts other matrix from the current one
/// @param other
void EMatrix::SubMatrix(const EMatrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::range_error(
        "SubMatrix error: matrices have different dimentions");

  SumOrSubMatrix(other, MATRICES_SUBTRACTION);
}

/// @brief Multiplies the current matrix by a number
/// @param num
void EMatrix::MulNumber(const double num) noexcept {
  for (size_t i = 0; i < inline_size_; ++i) {
    matrix_[0][i] *= num;
  }
}

/// @brief Multiplies the current matrix by the second matrix
/// @param other 
void EMatrix::MulMatrix(const EMatrix& other) {
  if (matrix_ == nullptr) {
    throw std::invalid_argument("MulMatrix error: first matrix is empty");
  }
  if (other.matrix_ == nullptr) {
    throw std::invalid_argument("MulMatrix error: second matrix is empty");
  }
  if (cols_ != other.rows_) {
    throw std::range_error(
        "MulMatrix error: the number of columns of the first matrix is not "
        "equal to the number of rows of the second matrix");
  }

  EMatrix result_matrix{rows_, other.cols_};

  for (int i = 0; i < result_matrix.rows_; ++i) {
    for (int j = 0; j < result_matrix.cols_; ++j) {
      for (int k = 0; k < cols_; ++k) {
        result_matrix.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }

  swap(result_matrix);
}

