#include "../e_matrix_oop.h"

namespace e_matrix {

double** EMatrix::get_matrix() { return matrix_; }  // temp method

/// @brief rows_ accessor
/// @return matrix rows number
int EMatrix::get_rows() const { return rows_; }

/// @brief cols_ accessor
/// @return matrix columns number
int EMatrix::get_cols() const { return cols_; }

}  // namespace e_matrix
