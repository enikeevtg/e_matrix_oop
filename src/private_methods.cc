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

void EMatrix::DeleteMatrix() {
  if (matrix_ != nullptr) {
    operator delete[](matrix_);
    matrix_ = nullptr;
    // rows_ = 0;
    // cols_ = 0;
  }
}

void EMatrix::SumOrSubMatrix(const EMatrix& other, int operation_select) {
  for (size_t i = 0; i < inline_size_; ++i) {
    matrix_[0][i] += operation_select * other.matrix_[0][i];
  }
}
