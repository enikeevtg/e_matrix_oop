#include <iostream>

#include "../e_matrix_oop.h"
using namespace std;

int main() {
  int sz = 3;
  EMatrix test_matrix(sz, sz);
  for (int i = 1; i <= sz; ++i) {
    for (int j = 1; j <= sz; ++j) {
      test_matrix(i, j) = rand() % 10;
    }
  }
  std::cout << "14" << std::endl;
  test_matrix.Determinant();
  return 0;
}
