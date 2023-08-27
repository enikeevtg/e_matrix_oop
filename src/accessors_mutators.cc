#include "../e_matrix_oop.h"

double** EMatrix::get_matrix() { return matrix_; } // temp method

/// @brief rows_ accessor
/// @return matrix rows number
int EMatrix::get_rows() { return rows_; }

/// @brief cols_ accessor
/// @return matrix columns number
int EMatrix::get_cols() { return cols_; }
