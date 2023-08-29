#include <iostream>
#include <stdexcept>

#include "../e_matrix_oop.h"
using namespace std;

void test_matrix() {
  cout << "test_matrix:" << endl;
  EMatrix matrix;
}

void test_new_matrix() {
  cout << endl << "test_new_matrix:" << endl;
  EMatrix* matrix = new EMatrix;
  delete matrix;
}

void test_matrix_2x2() {
  cout << endl << "test_matrix_2x2:" << endl;
  EMatrix matrix(2, 2);
}

void test_matrix_0x2() {
  cout << endl << "test_matrix_0x2:" << endl;
  try {
    EMatrix matrix(0, 2);
  } catch (const std::exception& e) {
    cout << e.what() << endl;
  }
}

void test_matrix_new_11x11() {
  cout << endl << "test_matrix_new_11x11:" << endl;
  EMatrix* matrix = new EMatrix(11, 11);
  delete matrix;
}

void test_matrix_copy_constructor() {
  cout << endl << "test_matrix_copy_constructor:" << endl;
  EMatrix matrix_src(5, 5);
  int inline_size = matrix_src.get_rows() * matrix_src.get_cols();
  cout << "matrix_src filling:" << endl;
  for (int i = 0; i < inline_size; i++) {
    matrix_src.get_matrix()[0][i] = (double)i;
  }
  matrix_src.PrintMatrix();

  EMatrix matrix_dest{matrix_src};
}

void test_matrix_copy_assignment() {
  cout << endl << "test_matrix_copy_assignment:" << endl;
  EMatrix matrix_src(5, 5);
  int inline_size = matrix_src.get_rows() * matrix_src.get_cols();
  cout << "matrix_src filling:" << endl;
  for (int i = 0; i < inline_size; i++) {
    matrix_src.get_matrix()[0][i] = (double)i;
  }
  matrix_src.PrintMatrix();

  EMatrix matrix_dest{3, 1};
  matrix_dest = matrix_src;
}

void test_matrix_move_constructor() {
  cout << endl << "test_matrix_move_constructor" << endl;
  EMatrix src(3, 4);

  EMatrix dest = std::move(src);
}

int main() {
  // test_matrix();
  // cout << "========================================================" << endl;

  // test_new_matrix();
  // cout << "========================================================" << endl;

  // test_matrix_2x2();
  // cout << "========================================================" << endl;

  // test_matrix_0x2();
  // cout << "========================================================" << endl;

  // test_matrix_new_11x11();
  // cout << "========================================================" << endl;

  // test_matrix_copy_constructor();
  // cout << "========================================================" << endl;

  test_matrix_copy_assignment();
  cout << "========================================================" << endl;

  // test_matrix_move_constructor();
  // cout << "========================================================" << endl;

  return 0;
}
