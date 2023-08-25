#include "../e_matrix_oop.h"

EMatrix::EMatrix() : EMatrix(0, 0){};

EMatrix::EMatrix(int rows, int cols) : rows_(rows), cols_(cols) {
  std::cout << "EMatrix(int rows, int cols) {" << std::endl;
  std::cout << "\tmatrix_ = " << matrix_ << std::endl;
  std::cout << "\trows_ = " << rows_ << std::endl;
  std::cout << "\tcols_ = " << cols_ << std::endl;

  if (rows_ > 0 && cols_ > 0) {
    CreateMatrix();
  }

  std::cout << "}  // EMatrix(int rows, int cols)" << std::endl;
}

EMatrix::EMatrix(const EMatrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  std::cout << "EMatrix(const EMatrix& other) {" << std::endl;
  std::cout << "\tmatrix_ = " << matrix_ << std::endl;
  std::cout << "\trows_ = " << rows_ << std::endl;
  std::cout << "\tcols_ = " << cols_ << std::endl;

  CreateMatrix();

  std::copy((double*)other.matrix_ + other.rows_,
            (double*)other.matrix_ + other.rows_ * (1 + other.cols_),
            (double*)matrix_ + rows_);

  std::cout << "\t  // copied from: other.matrix_ = " << other.matrix_
            << std::endl;
  PrintMatrix();

  std::cout << "}  //EMatrix(const EMatrix& other)" << std::endl;
}

EMatrix::~EMatrix() {
  if (matrix_ != nullptr) {
    operator delete[](matrix_);
  }
}

void EMatrix::CreateMatrix() {
  std::cout << "\tcreateMatrix() {" << std::endl;

  std::size_t memory_allocation_size =
      rows_ * sizeof(double*) + rows_ * cols_ * sizeof(double);
  matrix_ = (double**)operator new[](memory_allocation_size);

  if (matrix_ != nullptr) {
    double* start = (double*)matrix_ + rows_;
    for (int i = 0; i < rows_; ++i) {
      matrix_[i] = start + i * cols_;
    }
  }
  PrintMatrix();

  std::cout << "\t}  // CreateMatrix()" << std::endl;
}

void EMatrix::PrintMatrix() {
  std::cout << "\t\tprintMatrix() {" << std::endl;

  for (int i = 0; i < rows_; i++) {
    std::cout << "\t\t\t" << matrix_[i] << ":";
    for (int j = 0; j < cols_; j++) {
      std::cout << " " << matrix_[i][j];
    }
    std::cout << std::endl;
  }

  std::cout << "\t\t}  // PrintMatrix()" << std::endl;
}

double** EMatrix::get_matrix() { return matrix_; }

int EMatrix::get_rows() { return rows_; }

int EMatrix::get_cols() { return cols_; }
