#include "../e_matrix_oop.h"

/// @brief Copy Constructor
/// @param other
EMatrix::EMatrix(const EMatrix& other) { *this = other; }

/// @brief Copy assignment operator
/// @param other
/// @return
EMatrix& EMatrix::operator=(const EMatrix& other) {
  if (this != &other) {
    if (!(rows_ == other.rows_ && cols_ == other.cols_)) {
      DeleteMatrix();
      rows_ = other.rows_;
      cols_ = other.cols_;
      inline_size_ = other.inline_size_;
      CreateMatrix();
    }

    std::copy(&other.matrix_[0][0],
              &other.matrix_[other.rows_ - 1][other.cols_], matrix_[0]);
  }
  return *this;
}

/// @brief Move constructor
/// @param other
EMatrix::EMatrix(EMatrix&& other) noexcept { *this = std::move(other); }

/// @brief Move assignment operator
/// @param other
/// @return
EMatrix& EMatrix::operator=(EMatrix&& other) noexcept {
  if (this != &other) {
    DeleteMatrix();
    rows_ = other.rows_;
    cols_ = other.cols_;
    inline_size_ = other.inline_size_;
    matrix_ = other.matrix_;

    other.rows_ = 0;
    other.cols_ = 0;
    other.inline_size_ = 0;
    other.matrix_ = nullptr;
  }
  return *this;
}

/// @brief Destructor
EMatrix::~EMatrix() { DeleteMatrix(); }
