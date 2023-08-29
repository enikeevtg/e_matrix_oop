#include "../e_matrix_oop.h"

/// @brief Default constructor
/// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c45-dont-define-a-default-constructor-that-only-initializes-data-members-use-in-class-member-initializers-instead
EMatrix::EMatrix() {}

/// @brief Parametrized constructor with number of rows and columns
/// @param rows
/// @param cols
EMatrix::EMatrix(int rows, int cols)
    : rows_(rows), cols_(cols), inline_size_(rows * cols) {
  if (rows <= 0) {
    throw std::invalid_argument("Invalid rows value: " + std::to_string(rows));
  }
  if (cols <= 0) {
    throw std::invalid_argument("Invalid columns value: " +
                                std::to_string(cols));
  }

  CreateMatrix();
}
