#include "../e_matrix_oop.h"

namespace e_matrix {

/// @brief Matrix creation method
void EMatrix::CreateMatrix() {
  size_t malloc_sz =
      (size_t)rows_ * sizeof(double*) + inline_size_ * sizeof(double);
  matrix_ = (double**)operator new[](malloc_sz);

  if (matrix_ != nullptr) {
    double* start = (double*)matrix_ + rows_;
    for (int i = 0; i < rows_; ++i) {
      matrix_[i] = start + i * cols_;
    }
    for (size_t i = 0; i < inline_size_; ++i) {
      matrix_[0][i] = 0;
    }
  }
}

/// @brief Matrix deletion method
void EMatrix::DeleteMatrix() noexcept {
  if (matrix_ != nullptr) {
    operator delete[](matrix_);
    matrix_ = nullptr;
    rows_ = 0;
    cols_ = 0;
  }
}

/// @brief Matrices swapping
/// @param other 
void EMatrix::Swap(EMatrix& other) noexcept {
  std::swap(matrix_, other.matrix_);
  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
  std::swap(inline_size_, other.inline_size_);
}

/// @brief Matrix minor creation method
/// @param cur_row 
/// @param cur_col 
/// @return Minor matrix
EMatrix EMatrix::CreateMinor(int cur_row, int cur_col) {
  EMatrix minor(rows_ - 1, cols_ - 1);
  int k = 0;
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      if (!(i == cur_row || j == cur_col)) {
        minor.matrix_[0][k] = matrix_[i][j];
        ++k;
      }
    }
  }

  return minor;
}

/// @brief Bareiss reducing algorithm for matrix determinant calculation
/// @return Reducing success/error status
bool EMatrix::BareissReducingAlgorithm() {
  double pivot = 1.f;
  bool process_state = true;

  for (int row_col = 0; row_col < rows_ && process_state == true; ++row_col) {
    if (matrix_[row_col][row_col] == 0.f) {
      process_state = ExchangeCurrentRow(row_col);
    }
    if (process_state == true) {
      ReducingIterationStep(row_col, pivot);
      pivot = 1.f / matrix_[row_col][row_col];
    }
  }

  return process_state;
}

/// @brief Search for replacement row and swap "row_col" row with it for Bareiss reducing algorithm
/// @param row_col 
/// @return Excanging success/error status
bool EMatrix::ExchangeCurrentRow(int row_col) {
  bool process_state = true;
  int i = row_col;

  while (i < rows_ && matrix_[i][row_col] == 0) ++i;  // search for replacement
  if (i == rows_) {  // if all down column elements is nills
    process_state = false;
  } else {
    for (int j = 0; j < cols_; ++j) {
      std::swap(matrix_[row_col][j], matrix_[i][j]);
      matrix_[i][j] *= -1.f;
    }
  }

  return process_state;
}

/// @brief Bareiss reducing algorithm calculation iteration
/// @param row_col 
/// @param pivot 
void EMatrix::ReducingIterationStep(int row_col, double pivot) {
  EMatrix tmp(*this);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      if (i != row_col) {
        tmp.matrix_[i][j] = pivot * (matrix_[row_col][row_col] * matrix_[i][j] -
                                     matrix_[row_col][j] * matrix_[i][row_col]);
      }
    }
  }
  Swap(tmp);
}

}  // namespace e_matrix
