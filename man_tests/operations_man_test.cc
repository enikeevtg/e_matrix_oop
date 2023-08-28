#include <iostream>

#include "../e_matrix_oop.h"
using namespace std;

void SumMatrixTest() {
  cout << "void SumMatrixTest()" << endl;

  EMatrix matrix_1(3, 2);
  EMatrix matrix_2(3, 2);

  int inline_size = matrix_1.get_rows() * matrix_1.get_cols();
  for (int i = 0; i < inline_size; i++) {
    matrix_1.get_matrix()[0][i] = (double)(rand() % 10);
  }

  for (int i = 0; i < inline_size; i++) {
    matrix_2.get_matrix()[0][i] = (double)(rand() % 10);
  }

  matrix_1.PrintMatrix();
  matrix_2.PrintMatrix();

  matrix_1.SumMatrix(matrix_2);

  matrix_1.PrintMatrix();
}

void SubMatrixTest() {
  cout << "void SubMatrixTest()" << endl;

  EMatrix matrix_1(3, 2);
  EMatrix matrix_2(3, 2);

  int inline_size = matrix_1.get_rows() * matrix_1.get_cols();
  for (int i = 0; i < inline_size; i++) {
    matrix_1.get_matrix()[0][i] = (double)(rand() % 10);
  }

  for (int i = 0; i < inline_size; i++) {
    matrix_2.get_matrix()[0][i] = (double)(rand() % 10);
  }

  matrix_1.PrintMatrix();
  matrix_2.PrintMatrix();

  matrix_1.SubMatrix(matrix_2);

  matrix_1.PrintMatrix();
}

void MulNumberTest() {
  cout << "void MulNumberTest()" << endl;

  EMatrix matrix(5, 5);
  int inline_size = matrix.get_rows() * matrix.get_cols();
  for (int i = 0; i < inline_size; i++) {
    matrix.get_matrix()[0][i] = (double)i;
  }
  double num = 11;

  matrix.PrintMatrix();

  matrix.MulNumber(num);

  matrix.PrintMatrix();
}

int main() {
  SumMatrixTest();
  SubMatrixTest();  
  MulNumberTest();
  
  return 0;
}
