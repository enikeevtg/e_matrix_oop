#include "../e_matrix_oop.h"

/// @brief Checks matrices for equality with each other
/// @param other 
/// @return Checking result
bool EMatrix::EqMatrix(const EMatrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) return DIFFERENT_MATRICES;

  bool check = EQUAL_MATRICES;
  int inline_size = rows_ * cols_;
  for (int i = 0; check == EQUAL_MATRICES && i < inline_size; ++i) {
    if (matrix_[0][i] != other.matrix_[0][i]) {
      check = DIFFERENT_MATRICES;
    }
  }
  
  return check;
}
