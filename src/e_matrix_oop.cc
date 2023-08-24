#include "../e_matrix_oop.h"

EMatrix::EMatrix() : EMatrix(3, 3){};

EMatrix::EMatrix(int rows, int cols) {
  // std::cout << "matrix constructor begin: " << matrix_ << "( " << rows_ << ",
  // "
  //           << cols_ << " )" << std::endl;

  if (rows > 0 && cols > 0) {
    rows_ = rows;
    cols_ = cols;
    std::size_t memory_allocation_size =
        rows_ * sizeof(double*) + rows_ * cols_ * sizeof(double);
    matrix_ = (double**)operator new[](memory_allocation_size);

    double* start = (double*)matrix_ + rows_;
    for (int i = 0; i < rows_; i++) {
      matrix_[i] = start + i * cols_;
    }
  }

  // std::cout << "matrix constructor end:   " << matrix_ << "( " << rows_ << ",
  // "
  //           << cols_ << " )" << std::endl;
}

EMatrix::~EMatrix() {
  // std::cout << "matrix destructor begin: " << matrix_ << "( " << rows_ << ",
  // "
  //           << cols_ << " )" << std::endl;

  if (matrix_ != nullptr) {
    operator delete[](matrix_);
  }

  // std::cout << "matrix destructor end:   " << matrix_ << "( " << rows_ << ",
  // "
  //           << cols_ << " )" << std::endl;
}

double** EMatrix::getMatrixPtr() { return matrix_; }
