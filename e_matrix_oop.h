#ifndef E_MATRIXPLUS_E_MATRIX_OOP_H_
#define E_MATRIXPLUS_E_MATRIX_OOP_H_

#include <iostream>
#include <stdexcept>

#define EPS 1e-8

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
  void swap(EMatrix& other) noexcept;
};

#endif  // E_MATRIXPLUS_E_MATRIX_OOP_H_
