#include "../e_matrix_oop.h"

void EMatrix::CreateMatrix() {
  std::cout << "\tCreateMatrix() {" << std::endl;

  std::size_t memory_allocation_size =
      rows_ * sizeof(double*) + rows_ * cols_ * sizeof(double);
  matrix_ = (double**)operator new[](memory_allocation_size);

  if (matrix_ != nullptr) {
    double* start = (double*)matrix_ + rows_;
    for (int i = 0; i < rows_; ++i) {
      matrix_[i] = start + i * cols_;
    }
  }

  std::cout << "\t\tmatrix = " << this << std::endl;
  std::cout << "\t\tmatrix.matrix_ = " << matrix_ << std::endl;
  std::cout << "\t\tmatrix.rows_ = " << rows_ << std::endl;
  std::cout << "\t\tmatrix.cols_ = " << cols_ << std::endl;

  PrintMatrix();

  std::cout << "\t}  // CreateMatrix()" << std::endl;
}

void EMatrix::DeleteMatrix() {
  std::cout << "\tDeleteMatrix() {" << std::endl;

  if (matrix_ != nullptr) {
    operator delete[](matrix_);
    matrix_ = nullptr;
    // rows_ = 0;
    // cols_ = 0;
    std::cout << "\t\tmatrix = " << this << std::endl;
    std::cout << "\t\tmatrix.matrix_ = " << matrix_ << std::endl;
    std::cout << "\t\tmatrix.rows_ = " << rows_ << std::endl;
    std::cout << "\t\tmatrix.cols_ = " << cols_ << std::endl;
  }

  std::cout << "\t}  // DeleteMatrix()" << std::endl;
}
