#include "../e_matrix_oop.h"

/// @brief Copy Constructor
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
    swap(matrix_copy);
  }
  return *this;
}

/// @brief Move constructor
/// @param other
EMatrix::EMatrix(EMatrix&& other) noexcept : EMatrix() { swap(other); }

/// @brief Move assignment operator
/// @param other
/// @return
EMatrix& EMatrix::operator=(EMatrix&& other) noexcept {
  if (this != &other) swap(other);
  return *this;
}

/// @brief Destructor
EMatrix::~EMatrix() {
  // std::cout << "Destruction matrix: " << this << std::endl;
  DeleteMatrix();
}
