#include "../e_matrix_oop.h"

/// @brief Default constructor
EMatrix::EMatrix() : EMatrix(3, 3){};

/// @brief Parametrized constructor with number of rows and columns
/// @param rows
/// @param cols
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
