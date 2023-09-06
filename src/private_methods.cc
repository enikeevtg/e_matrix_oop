#include "../e_matrix_oop.h"

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

void EMatrix::DeleteMatrix() noexcept {
  if (matrix_ != nullptr) {
    operator delete[](matrix_);
    matrix_ = nullptr;
    rows_ = 0;
    cols_ = 0;
  }
}

void EMatrix::Swap(EMatrix& other) noexcept {
  std::swap(matrix_, other.matrix_);
  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
  std::swap(inline_size_, other.inline_size_);
}

bool EMatrix::BareissReducingAlgorithm() {
  double pivot = 1.f;
  bool process_state = true;

  for (int row_col = 0; row_col < rows_ && process_state == true; ++row_col) {
    if (matrix_[row_col][row_col] == 0.f) {
      process_state = ExchangeCurrentRow(row_col);
    }
    if (process_state == true) {
      ReducingStep(row_col, pivot);
      pivot = 1.f / matrix_[row_col][row_col];
    }
  }

  return process_state;
}

bool EMatrix::ExchangeCurrentRow(int row_col) {
  bool process_state = true;
  int i = row_col;

  while (matrix_[i][row_col] == 0 && i < rows_) ++i;  // search for replacement
  if (matrix_[i][row_col] != 0) {
    for (int j = 0; j < cols_; ++j) {
      std::swap(matrix_[row_col][j], matrix_[i][j]);
      matrix_[i][j] *= -1.f;
    }
  } else {
    process_state = false;
  }
  
  return process_state;
}

void EMatrix::ReducingStep(int row_col, double pivot) {
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
