#ifndef E_MATRIXPLUS_E_MATRIX_OOP_H_
#define E_MATRIXPLUS_E_MATRIX_OOP_H_

#include <iostream>

class EMatrix {
 public:
  EMatrix();
  EMatrix(int rows, int cols);
  EMatrix(const EMatrix& other);
  ~EMatrix();

  void PrintMatrix();
  double** get_matrix();
  int get_rows();
  int get_cols();

 private:
  double** matrix_{nullptr};
  int rows_{0};
  int cols_{0};

  void CreateMatrix();
};

#endif  // E_MATRIXPLUS_E_MATRIX_OOP_H_
