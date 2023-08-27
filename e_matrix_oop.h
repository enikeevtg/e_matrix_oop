#ifndef E_MATRIXPLUS_E_MATRIX_OOP_H_
#define E_MATRIXPLUS_E_MATRIX_OOP_H_

#include <iostream>

#define EQUAL_MATRICES 1
#define DIFFERENT_MATRICES 0

enum {
  DIFFERENT_MATRIX_DIMENTIONS = 1
};

#define SUM_MATRICES 1
#define SUBTRACT_MATRICES -1

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

  EMatrix& operator=(const EMatrix& other);
  EMatrix& operator=(EMatrix&& other);

 private:
  double** matrix_{nullptr};
  int rows_{0};
  int cols_{0};
  int inline_size_{0};

  void CreateMatrix();
  void DeleteMatrix();

  void SumOrSubMatrix(const EMatrix& other, int operation_select);
};

#endif  // E_MATRIXPLUS_E_MATRIX_OOP_H_
