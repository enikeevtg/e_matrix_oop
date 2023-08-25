#include <iostream>

#include "../e_matrix_oop.h"
using namespace std;

int main() {
  cout << "EMatrix matrix:" << endl;
  {
    EMatrix matrix;
    cout << "matrix.matrix_: " << matrix.get_matrix() << endl
         << "========================================================" << endl;
  }

  cout << endl << "EMatrix* matrix = new EMatrix:" << endl;
  {
    EMatrix* matrix = new EMatrix;
    cout << "matrix.matrix_: " << matrix->get_matrix() << endl
         << "========================================================" << endl;
    delete matrix;
  }

  cout << endl << "EMatrix matrix(2, 2):" << endl;
  {
    EMatrix matrix(2, 2);
    cout << "matrix.matrix_: " << matrix.get_matrix() << endl
         << "========================================================" << endl;
  }

  cout << endl << "EMatrix* matrix = new EMatrix(11, 11):" << endl;
  {
    EMatrix* matrix = new EMatrix(11, 11);
    cout << "matrix.matrix_: " << matrix->get_matrix() << endl
         << "========================================================" << endl;
    delete matrix;
  }

  cout << endl
       << "EMatrix matrix_src(5, 5) && matrix_src.matrixInlinePrinting():"
       << endl;
  {
    EMatrix matrix_src(5, 5);
    cout << "matrix_src.matrix_: " << matrix_src.get_matrix() << endl;
    int inline_size = matrix_src.get_rows() * matrix_src.get_cols();
    for (int i = 0; i < inline_size; i++) {
      matrix_src.get_matrix()[0][i] = (double)i;
    }
    matrix_src.PrintMatrix();

    EMatrix matrix_dest(matrix_src);
    cout << "matrix_dest.matrix_: " << matrix_dest.get_matrix() << endl;
  }
  cout << "===================END===================" << endl;

  return 0;
}
