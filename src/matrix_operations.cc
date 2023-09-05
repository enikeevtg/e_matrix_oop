#include "../e_matrix_oop.h"

/// @brief Checks matrices for equality with each other
/// @param other
/// @return Checking result: equal - 1, not equal - 0
bool EMatrix::EqMatrix(const EMatrix& other) noexcept {
  if (rows_ != other.rows_ || cols_ != other.cols_) return false;

  bool check = true;
  for (size_t i = 0; check == true && i < inline_size_; ++i) {
    if (std::abs(matrix_[0][i] - other.matrix_[0][i]) > EPS) check = false;
  }

  return check;
}

/// @brief Adds the other matrix to the current one
/// @param other
void EMatrix::SumMatrix(const EMatrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::range_error(
        "SumMatrix error: matrices have different dimentions");
  }

  for (size_t i = 0; i < inline_size_; ++i) {
    matrix_[0][i] += other.matrix_[0][i];
  }
}

/// @brief Subtracts other matrix from the current one
/// @param other
void EMatrix::SubMatrix(const EMatrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::range_error(
        "SubMatrix error: matrices have different dimentions");
  }

  for (size_t i = 0; i < inline_size_; ++i) {
    matrix_[0][i] -= other.matrix_[0][i];
  }
}

/// @brief Multiplies the current matrix by a number
/// @param num
void EMatrix::MulNumber(const double num) noexcept {
  if (matrix_ != nullptr) {
    for (size_t i = 0; i < inline_size_; ++i) {
      matrix_[0][i] *= num;
    }
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

  EMatrix result{rows_, other.cols_};

  for (int i = 0; i < result.rows_; ++i) {
    for (int j = 0; j < result.cols_; ++j) {
      for (int k = 0; k < cols_; ++k) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }

  swap(result);
}

/// @brief Creates a new transposed matrix from the current one and returns it
/// @return Transposed matrix
EMatrix EMatrix::Transpose() noexcept {
  EMatrix result{cols_, rows_};

  if (matrix_ != nullptr) {
    for (int i = 0; i < result.rows_; ++i) {
      for (int j = 0; j < result.cols_; ++j) {
        result.matrix_[i][j] = matrix_[j][i];
      }
    }
  }

  return result;
}
