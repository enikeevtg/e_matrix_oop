#include <iostream>

#include "../e_matrix_oop.h"
using namespace std;

int main() {
  cout << "EMatrix matrix:" << endl;
  {
    EMatrix matrix;
  }
  cout << "========================================================" << endl;

  cout << endl << "EMatrix* matrix = new EMatrix:" << endl;
  {
    EMatrix* matrix = new EMatrix;
    delete matrix;
  }
  cout << "========================================================" << endl;

  cout << endl << "EMatrix matrix(2, 2):" << endl;
  {
    EMatrix matrix(2, 2);
  }
  cout << "========================================================" << endl;

  cout << endl << "EMatrix* matrix = new EMatrix(11, 11):" << endl;
  {
    EMatrix* matrix = new EMatrix(11, 11);
    delete matrix;
  }
  cout << "========================================================" << endl;

  cout << endl
       << "EMatrix matrix_src(5, 5) && matrix_src.matrixInlinePrinting():"
       << endl;
  {
    EMatrix matrix_src(5, 5);
    int inline_size = matrix_src.get_rows() * matrix_src.get_cols();
    cout << "matrix_src filling:" << endl;
    for (int i = 0; i < inline_size; i++) {
      matrix_src.get_matrix()[0][i] = (double)i;
    }
    matrix_src.PrintMatrix();

    EMatrix matrix_dest(matrix_src);
  }
  cout << "===================END===================" << endl;

  return 0;
}
