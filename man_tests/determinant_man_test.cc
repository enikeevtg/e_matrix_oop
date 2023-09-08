#include <iostream>

#include "../e_matrix_oop.h"
using namespace std;
using namespace e_matrix;

int main() {
  int sz = 2;
  EMatrix test_matrix(sz, sz);
  for (int i = 1; i <= sz; ++i) {
    for (int j = 1; j <= sz; ++j) {
      test_matrix(i, j) = rand() % 10;
    }
  }
  test_matrix.PrintMatrix();
  // test_matrix(1, 1) = 0.f;
  std::cout << test_matrix.Determinant() << std::endl;
  return 0;
}
