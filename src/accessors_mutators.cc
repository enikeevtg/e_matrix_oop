#include "../e_matrix_oop.h"

double** EMatrix::get_matrix() { return matrix_; }  // temp method

/// @brief rows_ accessor
/// @return matrix rows number
int EMatrix::get_rows() const noexcept { return rows_; }

/// @brief cols_ accessor
/// @return matrix columns number
int EMatrix::get_cols() const noexcept { return cols_; }

void EMatrix::set_rows(int rows) { SetDimensions(rows, cols_); }

void EMatrix::set_cols(int cols) { SetDimensions(rows_, cols); }
