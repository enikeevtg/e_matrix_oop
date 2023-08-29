#include "../e_matrix_oop.h"

/// @brief Default constructor
EMatrix::EMatrix() {
  std::cout << "EMatrix() {" << std::endl;
  std::cout << "\tmatrix = " << this << std::endl;
  std::cout << "\tmatrix.matrix_ = " << matrix_ << std::endl;
  std::cout << "\tmatrix.rows_ = " << rows_ << std::endl;
  std::cout << "\tmatrix.cols_ = " << cols_ << std::endl;
  std::cout << "}  // EMatrix()" << std::endl;
}  // https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c45-dont-define-a-default-constructor-that-only-initializes-data-members-use-in-class-member-initializers-instead

/// @brief Parametrized constructor with number of rows and columns
/// @param rows
/// @param cols
EMatrix::EMatrix(int rows, int cols)
    : rows_(rows), cols_(cols), inline_size_(rows * cols) {
  std::cout << "EMatrix(int rows, int cols) {" << std::endl;
  std::cout << "\tmatrix = " << this << std::endl;
  std::cout << "\tmatrix.matrix_ = " << matrix_ << std::endl;
  std::cout << "\tmatrix.rows_ = " << rows_ << std::endl;
  std::cout << "\tmatrix.cols_ = " << cols_ << std::endl;

  if (rows <= 0) {
    throw std::invalid_argument("Invalid rows value: " + std::to_string(rows));
  }
  if (cols <= 0) {
    throw std::invalid_argument("Invalid columns value: " +
                                std::to_string(cols));
    // throw std::string{"Invalid columns value: " + std::to_string(cols)};
  }

  CreateMatrix();

  std::cout << "}  // EMatrix(int rows, int cols)" << std::endl;
}
