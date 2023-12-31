#include <stdexcept>

#include "../e_matrix_oop.h"

namespace e_matrix {

/// @brief rows_ accessor
/// @return matrix rows number
int EMatrix::get_rows() const noexcept { return rows_; }

/// @brief cols_ accessor
/// @return matrix columns number
int EMatrix::get_cols() const noexcept { return cols_; }

void EMatrix::set_rows(int rows) {
  if (rows < 1) {
    throw std::invalid_argument(
        "set_rows(): rows value must be greater than nill");
  }

  SetDimensions(rows, cols_);
}

void EMatrix::set_cols(int cols) {
  if (cols < 1) {
    throw std::invalid_argument(
        "set_cols(): cols value must be greater than nill");
  }

  SetDimensions(rows_, cols);
}

}  // namespace e_matrix
