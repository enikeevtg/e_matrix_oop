#ifndef E_MATRIXPLUS_E_MATRIX_OOP_H_
#define E_MATRIXPLUS_E_MATRIX_OOP_H_

#include <iostream>

class EMatrix {
 private:
  double** matrix_{nullptr};
  int rows_{0};
  int cols_{0};

 public:
  EMatrix();
  EMatrix(int rows, int cols);
  EMatrix(const EMatrix& other);
  ~EMatrix();

  double** getMatrixPtr();
  void matrixPrinting();
  int getRows();
  int getCols();

 private:
  void createMatrix();
};

#endif  // E_MATRIXPLUS_E_MATRIX_OOP_H_
