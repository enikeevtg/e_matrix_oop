#include "../e_matrix_oop.h"

EMatrix::EMatrix() : EMatrix(3, 3){};

EMatrix::EMatrix(int rows, int cols) : rows_(rows), cols_(cols) {
  std::cout << "\tEMatrix(int rows, int cols) start" << std::endl;
  if (rows_ > 0 && cols_ > 0) {
    this->createMatrix();
  }
  std::cout << "\tEMatrix(int rows, int cols) end" << std::endl;
  matrixPrinting();
}

EMatrix::EMatrix(const EMatrix& other) {
  std::cout << "EMatrix(const EMatrix& other) start" << std::endl;

  rows_ = other.rows_;
  cols_ = other.cols_;
  this->createMatrix();

  int last_inline_index = rows_ + rows_ * cols_;
  for (int i = rows_; i < last_inline_index; i++) {
    this->matrix_[i] = other.matrix_[i];
  }

  std::cout << "EMatrix(const EMatrix& other) end" << std::endl;
  matrixPrinting();
}

EMatrix::~EMatrix() {
  if (matrix_ != nullptr) {
    operator delete[](matrix_);
  }
}

void EMatrix::createMatrix() {
  std::cout << "\t\tcreateMatrix() calling" << std::endl;
  std::size_t memory_allocation_size =
      rows_ * sizeof(double*) + rows_ * cols_ * sizeof(double);
  matrix_ = (double**)operator new[](memory_allocation_size);

  if (matrix_ != nullptr) {
    double* start = (double*)matrix_ + rows_;
    for (int i = 0; i < rows_; i++) {
      matrix_[i] = start + i * cols_;
    }
  }
}

void EMatrix::matrixPrinting() {
  for (int i = 0; i < rows_; i++) {
    std::cout << matrix_[i] << ":";
    for (int j = 0; j < cols_; j++) {
      std::cout << " " << matrix_[i][j];
    }
    std::cout << std::endl;
  }
}

double** EMatrix::getMatrixPtr() { return matrix_; }

int EMatrix::getRows() { return rows_; }

int EMatrix::getCols() { return cols_; }
