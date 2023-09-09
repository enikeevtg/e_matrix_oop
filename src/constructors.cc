#include <stdexcept>

#include "../e_matrix_oop.h"

namespace e_matrix {

/// @brief default constructor creates matrix 0x0 dimensions
EMatrix::EMatrix() {}

/// @brief parametrized constructor with number of rows and columns
/// @throw rows (cols) value is less than 1
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

}  // namespace e_matrix
