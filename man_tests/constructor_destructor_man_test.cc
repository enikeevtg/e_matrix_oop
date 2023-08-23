#include <iostream>

#include "../e_matrix_oop.h"
using namespace std;

int main() {
  cout << "Constructor without parameters:" << endl;
  {
    EMatrix matrix;
    cout << "matrix.matrix_: " << matrix.getMatrixPtr() << endl;
  }

  cout << endl << "Constructor without parameters:" << endl;
  {
    EMatrix* matrix = new EMatrix;
    cout << "matrix.matrix_: " << matrix->getMatrixPtr() << endl;
    delete matrix;
  }

  cout << endl
       << "Parametrized constructor with number of rows and columns:" << endl;
  {
    EMatrix matrix(2, 2);
    cout << "matrix.matrix_: " << matrix.getMatrixPtr() << endl;
  }

  cout << endl
       << "Parametrized constructor with number of rows and columns:" << endl;
  {
    EMatrix* matrix = new EMatrix(11, 11);
    cout << "matrix.matrix_: " << matrix->getMatrixPtr() << endl;
    delete matrix;
  }
  cout << "===================END===================" << endl;
  return 0;
}
