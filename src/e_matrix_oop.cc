#include "../e_matrix_oop.h"

EMatrix::EMatrix() : EMatrix(3, 3){};

EMatrix::EMatrix(int rows, int cols) {
  std::cout << "matrix constructor begin: " << matrix_ << "( " << rows_ << ", "
            << cols_ << " )" << std::endl;

  if (rows > 0 && cols > 0) {
    rows_ = rows;
    cols_ = cols;
    matrix_ = new double*[rows_]();
    for (int i = 0; i < rows_; i++) {
      matrix_[i] = new double[cols_]();
    }
  }

  std::cout << "matrix constructor end:   " << matrix_ << "( " << rows_ << ", "
            << cols_ << " )" << std::endl;
}

EMatrix::~EMatrix() {
  std::cout << "matrix destructor begin: " << matrix_ << "( " << rows_ << ", "
            << cols_ << " )" << std::endl;

  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      if (matrix_[i] != nullptr) {
        delete[] matrix_[i];
        matrix_[i] = nullptr;
      }
    }
    delete matrix_;
    matrix_ = nullptr;
    rows_ = 0;
    cols_ = 0;
  }
  std::cout << "matrix destructor end:   " << matrix_ << "( " << rows_ << ", "
            << cols_ << " )" << std::endl;
}

double** EMatrix::getMatrixPtr() { return matrix_; }
