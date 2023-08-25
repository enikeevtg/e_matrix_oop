#include "../e_matrix_oop.h"

// A basic constructor that initialises a matrix of some predefined dimension
EMatrix::EMatrix() : EMatrix(3, 3){};

// Parametrized constructor with number of rows and columns
EMatrix::EMatrix(int rows, int cols) {
  // std::cout << "matrix constructor begin: " << matrix_ << "( " << rows_ << ",
  // "
  //           << cols_ << " )" << std::endl;

  if (rows > 0 && cols > 0) {
    rows_ = rows;
    cols_ = cols;
    matrix_ = new double*[rows_]();
    for (int i = 0; i < rows_; i++) {
      matrix_[i] = new double[cols_]();
    }
  }

  // std::cout << "matrix constructor end:   " << matrix_ << "( " << rows_ << ",
  // "
  //           << cols_ << " )" << std::endl;
}

// Copy constructor
EMatrix::EMatrix(const EMatrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  std::cout << "EMatrix(const EMatrix& other) {" << std::endl;
  std::cout << "\tmatrix_ = " << matrix_ << std::endl;
  std::cout << "\trows_ = " << rows_ << std::endl;
  std::cout << "\tcols_ = " << cols_ << std::endl;

  CreateMatrix();

  size_t last_inline_index = rows_ * cols_;
  for (size_t i = 0; i < last_inline_index; i++) {
    matrix_[0][i] = other.matrix_[0][i] + 1;
  }

  std::cout << "\t  // copied from: other.matrix_ = " << other.matrix_
            << std::endl;
  PrintMatrix();

  std::cout << "}  //EMatrix(const EMatrix& other)" << std::endl;
}

EMatrix::~EMatrix() {
  // std::cout << "matrix destructor begin: " << matrix_ << "( " << rows_ << ",
  // "
  //           << cols_ << " )" << std::endl;

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

  // std::cout << "matrix destructor end:   " << matrix_ << "( " << rows_ << ",
  // "
  //           << cols_ << " )" << std::endl;
}
