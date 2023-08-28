#ifndef E_MATRIXPLUS_E_MATRIX_OOP_H_
#define E_MATRIXPLUS_E_MATRIX_OOP_H_

#include <iostream>

#define EQUAL_MATRICES 1
#define DIFFERENT_MATRICES 0

enum { DIFFERENT_MATRIX_DIMENTIONS = 1 };

#define MATRICES_SUMMATION 1
#define MATRICES_SUBTRACTION -1

class EMatrix {
 public:
  EMatrix();
  EMatrix(int rows, int cols);
  EMatrix(const EMatrix& other);
  EMatrix(EMatrix&& other);
  ~EMatrix();

  void PrintMatrix();
  double** get_matrix();
  int get_rows();
  int get_cols();

  bool EqMatrix(const EMatrix& other);
  void SumMatrix(const EMatrix& other);
  void SubMatrix(const EMatrix& other);
  void MulNumber(const double num);

  EMatrix& operator=(const EMatrix& other);
  EMatrix& operator=(EMatrix&& other);

 private:
  double** matrix_;
  int rows_;
  int cols_;
  int inline_size_;

  void CreateMatrix();
  void DeleteMatrix();

  void SumOrSubMatrix(const EMatrix& other, int operation_select);
};

#endif  // E_MATRIXPLUS_E_MATRIX_OOP_H_
