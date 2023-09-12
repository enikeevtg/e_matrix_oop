#include "../e_matrix_oop.h"

int main() {
  int n = 3;
  EMatrix* test_unity_matrices = new EMatrix[n];
  EMatrix* test_matrices = new EMatrix[n];

  for (int i = 0; i < n; i++) {
    test_unity_matrices[i].SetDimensions(i + 1, i + 1);
    test_matrices[i].SetDimensions(i + 1, i + 1);
    test_matrices[i].PrintMatrix();
    test_unity_matrices[i].PrintMatrix();
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= i + 1; ++j) {
      test_unity_matrices[i](j, j) = 1;
      for (int k = 1; k <= i + 1; ++k) {
        test_matrices[i](j, k) = j * 10 + k;
      }
    }
    test_unity_matrices[i].PrintMatrix();
    test_matrices[i].PrintMatrix();
  }

  delete[] test_matrices;
  delete[] test_unity_matrices;

  return 0;
}
