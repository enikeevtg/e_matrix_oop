#include "../e_matrix_oop.h"

namespace e_matrix {

/// @brief Copy constructor
/// @param other
EMatrix::EMatrix(const EMatrix& other) : EMatrix(other.rows_, other.cols_) {
  std::copy(&other.matrix_[0][0], &other.matrix_[0][other.inline_size_],
            matrix_[0]);
}

/// @brief Copy assignment operator
/// @param other
/// @return
EMatrix& EMatrix::operator=(const EMatrix& other) {
  if (this != &other) {
    EMatrix matrix_copy{other};
    Swap(matrix_copy);
  }
  return *this;
}

/// @brief Move constructor
/// @param other
EMatrix::EMatrix(EMatrix&& other) noexcept : EMatrix() { Swap(other); }

/// @brief Move assignment operator
/// @param other
/// @return
EMatrix& EMatrix::operator=(EMatrix&& other) noexcept {
  if (this != &other) Swap(other);
  return *this;
}

/// @brief Destructor
EMatrix::~EMatrix() { DeleteMatrix(); }

}  // namespace e_matrix
