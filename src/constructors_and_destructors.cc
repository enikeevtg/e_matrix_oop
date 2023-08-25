#include "../e_matrix_oop.h"

EMatrix::EMatrix() {}

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

EMatrix::EMatrix(const EMatrix& other) {
    // : rows_(other.rows_), cols_(other.cols_) {
  std::cout << "EMatrix(const EMatrix& other) {" << std::endl;
  std::cout << "\tmatrix_ = " << matrix_ << std::endl;
  std::cout << "\trows_ = " << rows_ << std::endl;
  std::cout << "\tcols_ = " << cols_ << std::endl;

  CreateMatrix();

  *this = EMatrix::operator=(other);

  std::cout << "\t  // copied from: other.matrix_ = " << other.matrix_
            << std::endl;
  PrintMatrix();

  std::cout << "}  //EMatrix(const EMatrix& other)" << std::endl;
}

EMatrix::EMatrix(EMatrix&& other) {
  std::cout << "EMatrix(EMatrix&& other) {" << std::endl;
  std::cout << "\tmatrix_ = " << matrix_ << std::endl;
  std::cout << "\trows_ = " << rows_ << std::endl;
  std::cout << "\tcols_ = " << cols_ << std::endl;

  *this = std::move(other);

  std::cout << "\t  // copied from: other.matrix_ = " << other.matrix_
            << std::endl;
  PrintMatrix();

  std::cout << "}  //EMatrix(EMatrix&& other)" << std::endl;
}

EMatrix::~EMatrix() {
  std::cout << "~EMatrix() {" << std::endl;

  DeleteMatrix();

  std::cout << "}  //~EMatrix()" << std::endl;
}
