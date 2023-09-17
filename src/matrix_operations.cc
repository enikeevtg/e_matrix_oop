#include <stdexcept>

#include "../e_matrix_oop.h"

namespace e_matrix {

/// @brief Checks matrices for equality with each other
/// @param other
/// @return Checking result: equal - 1, not equal - 0
bool EMatrix::EqMatrix(const EMatrix& other) const noexcept {
  if (rows_ != other.rows_ || cols_ != other.cols_) return false;

  for (size_t i = 0; i < inline_size_; ++i) {
    if (std::abs(matrix_[0][i] - other.matrix_[0][i]) > EPS) {
      return false;
    }
  }

  return true;
}

/// @brief Adds the other matrix to the current one
/// @param other
void EMatrix::SumMatrix(const EMatrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::range_error("SumMatrix(): matrices have different dimentions");
  }

  for (size_t i = 0; i < inline_size_; ++i) {
    matrix_[0][i] += other.matrix_[0][i];
  }
}

/// @brief Subtracts other matrix from the current one
/// @param other
void EMatrix::SubMatrix(const EMatrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::range_error("SubMatrix(): matrices have different dimentions");
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
    throw std::invalid_argument("MulMatrix(): first matrix is empty");
  }
  if (other.matrix_ == nullptr) {
    throw std::invalid_argument("MulMatrix(): second matrix is empty");
  }
  if (cols_ != other.rows_) {
    throw std::range_error(
        "MulMatrix(): the number of columns of the first matrix is not "
        "equal to the number of rows of the second matrix");
  }

  EMatrix result(rows_, other.cols_);
  for (int i = 0; i < result.rows_; ++i) {
    for (int j = 0; j < result.cols_; ++j) {
      for (int k = 0; k < cols_; ++k) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }

  Swap(result);
}

/// @brief Creates a new transposed matrix from the current one and returns it
/// @return Transposed matrix
EMatrix EMatrix::Transpose() const noexcept {
  EMatrix result(cols_, rows_);
  if (matrix_ != nullptr) {
    for (int i = 0; i < result.rows_; ++i) {
      for (int j = 0; j < result.cols_; ++j) {
        result.matrix_[i][j] = matrix_[j][i];
      }
    }
  }

  return result;
}

/// @brief Calculates the algebraic addition matrix of the current one and
/// returns it
/// @return Algebraic addition matrix
EMatrix EMatrix::CalcComplements() const {
  if (rows_ != cols_ || rows_ == 0 || cols_ == 0) {
    throw std::range_error("CalComplements(): the matrix is not square");
  }

  EMatrix result(*this);
  if (result.rows_ > 1) {
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        EMatrix minor_ij = this->CreateMinor(i + 1, j + 1);  // +1 cause
                                                             // CreateMinor()
                                                             // origin is (1, 1)
        result.matrix_[i][j] = minor_ij.Determinant();
        if ((i + j) % 2 == 1) result.matrix_[i][j] *= -1;
      }
    }
  }

  return result;
}

/// @brief Calculates and returns the determinant of the current matrix
/// @return Matrix determinant
double EMatrix::Determinant() const {
  if (rows_ != cols_ || rows_ == 0 || cols_ == 0) {
    throw std::range_error("Determinant(): the matrix is not square");
  }

  double det = 0.f;
  EMatrix reduced(*this);
  if (reduced.BareissReducingAlgorithm() == true) det = reduced(1, 1);

  return det;
}

EMatrix EMatrix::InverseMatrix() const {
  double det = Determinant();
  if (std::abs(det) < EPS) {
    throw std::invalid_argument("InverseMatrix(): matrix determinant is nill");
  }

  EMatrix result(rows_, cols_);
  if (rows_ == 1) {
    result(1, 1) = 1.f / det;
  } else {
    EMatrix complements_matrix = CalcComplements();
    result = complements_matrix.Transpose();
    result.MulNumber(1 / det);
  }

  return result;
}

}  // namespace e_matrix
