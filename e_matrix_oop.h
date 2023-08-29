#ifndef E_MATRIXPLUS_E_MATRIX_OOP_H_
#define E_MATRIXPLUS_E_MATRIX_OOP_H_

#include <iostream>
#include <stdexcept>

#define EQUAL_MATRICES 1
#define DIFFERENT_MATRICES 0

#define MATRICES_SUMMATION 1
#define MATRICES_SUBTRACTION -1

class EMatrix {
 public:
  EMatrix();
  EMatrix(int rows, int cols);
  EMatrix(const EMatrix& other);
  EMatrix(EMatrix&& other) noexcept;
  ~EMatrix();

  void PrintMatrix();     // TMP METHOD
  double** get_matrix();  // TMP METHOD
  int get_rows() const;
  int get_cols() const;

  bool EqMatrix(const EMatrix& other);
  void SumMatrix(const EMatrix& other);
  void SubMatrix(const EMatrix& other);
  void MulNumber(const double num);

  EMatrix& operator=(const EMatrix& other);
  EMatrix& operator=(EMatrix&& other) noexcept;

 private:
  double** matrix_{nullptr};
  int rows_{0};
  int cols_{0};
  size_t inline_size_{0};

  void CreateMatrix();
  void swap(EMatrix& other) noexcept;
  void DeleteMatrix() noexcept;

  void SumOrSubMatrix(const EMatrix& other, int operation_select);
};

#endif  // E_MATRIXPLUS_E_MATRIX_OOP_H_
