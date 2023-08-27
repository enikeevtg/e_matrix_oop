#include <iostream>

#include "../e_matrix_oop.h"
using namespace std;

void test_matrix() {
  cout << "EMatrix matrix:" << endl;
  EMatrix matrix;
}

void test_new_matrix() {
  cout << endl << "EMatrix* matrix = new EMatrix:" << endl;
  EMatrix* matrix = new EMatrix;
  delete matrix;
}

void test_matrix_2x2() {
  cout << endl << "EMatrix matrix(2, 2):" << endl;
  EMatrix matrix(2, 2);
}

void test_matrix_new_11x11() {
  cout << endl << "EMatrix* matrix = new EMatrix(11, 11):" << endl;
  EMatrix* matrix = new EMatrix(11, 11);
  delete matrix;
}

void test_matrix_copy_constructor() {
  cout << endl << "EMatrix matrix_src(5, 5):" << endl;
  EMatrix matrix_src(5, 5);
  int inline_size = matrix_src.get_rows() * matrix_src.get_cols();
  cout << "matrix_src filling:" << endl;
  for (int i = 0; i < inline_size; i++) {
    matrix_src.get_matrix()[0][i] = (double)i;
  }
  matrix_src.PrintMatrix();

  EMatrix matrix_dest(matrix_src);
}

EMatrix return_rvalue() {
  EMatrix return_matrix(3, 4);
  return return_matrix;
}

void test_matrix_move_constructor() {
  cout << endl << "EMatrix dest = std::move(return_rvalue()):" << endl;
  EMatrix dest = std::move(return_rvalue());
  // dest = return_rvalue();

  EMatrix dest2 = dest;
}

int main() {
  test_matrix();
  cout << "========================================================" << endl;

  test_new_matrix();
  cout << "========================================================" << endl;

  test_matrix_2x2();
  cout << "========================================================" << endl;

  test_matrix_new_11x11();
  cout << "========================================================" << endl;

  test_matrix_copy_constructor();
  cout << "========================================================" << endl;

  test_matrix_move_constructor();
  cout << "========================================================" << endl;

  return 0;
}
