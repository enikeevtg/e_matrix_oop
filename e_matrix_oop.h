#ifndef E_MATRIXPLUS_E_MATRIX_OOP_H_
#define E_MATRIXPLUS_E_MATRIX_OOP_H_

#include <iostream>
#include <stdexcept>

namespace e_matrix {
  
#define EPS 1e-7

class EMatrix {
 public:
  EMatrix();
  EMatrix(int rows, int cols);
  EMatrix(const EMatrix& other);
  EMatrix(EMatrix&& other) noexcept;
  EMatrix& operator=(const EMatrix& other);
  EMatrix& operator=(EMatrix&& other) noexcept;
  ~EMatrix();

  int get_rows() const noexcept;
  int get_cols() const noexcept;
  void set_rows(int rows);
  void set_cols(int cols);

  bool EqMatrix(const EMatrix& other) noexcept;
  void SumMatrix(const EMatrix& other);
  void SubMatrix(const EMatrix& other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const EMatrix& other);
  EMatrix Transpose() noexcept;
  EMatrix CalcComplements();
  double Determinant();
  EMatrix InverseMatrix();

  double& operator()(int row, int column) const;

  void SetDimensions(int rows, int cols);
  void PrintMatrix() noexcept;
  double** get_matrix();  // TMP METHOD

 private:
  double** matrix_{nullptr};
  int rows_{0};
  int cols_{0};
  size_t inline_size_{0};

  void CreateMatrix();
  void DeleteMatrix() noexcept;
  void Swap(EMatrix& other) noexcept;
  EMatrix CreateMinor(int cur_row, int cur_col);
  bool BareissReducingAlgorithm();
  bool ExchangeCurrentRow(int row_col);
  void ReducingIterationStep(int row_col, double pivot);
};

}  // namespace e_matrix

#endif  // E_MATRIXPLUS_E_MATRIX_OOP_H_
