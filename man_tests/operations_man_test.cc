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

void MulMatrixTest() {
  cout << "void MulMatrixTest()" << endl;

  EMatrix matrix_3x3(3, 3);
  EMatrix matrix_2x1(2, 1);
  int inline_size_3x3 = matrix_3x3.get_rows() * matrix_3x3.get_cols();
  for (int i = 0; i < inline_size_3x3; i++) {
    matrix_3x3.get_matrix()[0][i] = (double)i;
  }

  int inline_size_2x1 = matrix_2x1.get_rows() * matrix_2x1.get_cols();
  for (int i = 0; i < inline_size_2x1; i++) {
    matrix_2x1.get_matrix()[0][i] = (double)i;
  }

  matrix_3x3.PrintMatrix();
  matrix_2x1.PrintMatrix();

  try {
    matrix_3x3.MulMatrix(matrix_2x1);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
    matrix_3x3.PrintMatrix();
  }

  try {
    EMatrix matrix;
    matrix.MulMatrix(matrix_3x3);
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    EMatrix matrix;
    matrix_3x3.MulMatrix(matrix);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}

int main() {
  // SumMatrixTest();
  // SubMatrixTest();
  // MulNumberTest();
  MulMatrixTest();

  return 0;
}
