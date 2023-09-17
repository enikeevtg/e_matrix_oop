#ifndef E_MATRIX_OOP_E_MATRIX_OOP_H_
#define E_MATRIX_OOP_E_MATRIX_OOP_H_

#include <iostream>

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

  bool EqMatrix(const EMatrix& other) const noexcept;
  void SumMatrix(const EMatrix& other);
  void SubMatrix(const EMatrix& other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const EMatrix& other);
  EMatrix Transpose() const noexcept;
  EMatrix CalcComplements() const;
  double Determinant() const;
  EMatrix InverseMatrix() const;

  EMatrix operator+(const EMatrix& other) const;
  EMatrix operator-(const EMatrix& other) const;
  EMatrix operator*(const double& num) const;
  friend EMatrix operator*(const double& num, const EMatrix& matrix);
  EMatrix operator*(const EMatrix& other) const;
  bool operator==(const EMatrix& other) const noexcept;
  void operator+=(const EMatrix& other);
  void operator-=(const EMatrix& other);
  void operator*=(const double& num) noexcept;
  void operator*=(const EMatrix& other);
  double& operator()(int row, int column);
  double operator()(int row, int column) const;

  void SetDimensions(int rows, int cols);
  EMatrix CreateMinor(int cur_row, int cur_col) const;
  void PrintMatrix() const noexcept;

 private:
  void CreateMatrix();
  void DeleteMatrix() noexcept;
  void Swap(EMatrix& other) noexcept;
  bool BareissReducingAlgorithm();
  bool ExchangeCurrentRow(int row_col);
  void ReducingIterationStep(int row_col, double pivot);

  double** matrix_{nullptr};
  int rows_{0};
  int cols_{0};
  size_t inline_size_{0};
};

}  // namespace e_matrix

#endif  // E_MATRIX_OOP_E_MATRIX_OOP_H_
