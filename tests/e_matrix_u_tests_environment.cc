#include "e_matrix_u_tests_environment.h"

void TestsEnvironment::SetUp() {
  TestMatricesArraysMemAlloc();
  SetTestMatricesDimensions();
  FillTestMatrices();
  // for (int i = 0; i < uform_matrices_number_ /* * kEMatrixTypesNumber*/; ++i)
  // {
  //   std::cout << i << std::endl;
  //   ut_matrices_arr_[i].PrintMatrix();
  //   ut_matrices_tr_arr_[i].PrintMatrix();
  // }
  // for (int i = 0; i < uform_matrices_number_; ++i) {
  //   ut_unity_matrices_arr_[i].PrintMatrix();
  // }
}

void TestsEnvironment::TestMatricesArraysMemAlloc() {
  ut_unity_matrices_arr_ = new EMatrix[uform_matrices_number_];
  ut_matrices_arr_ = new EMatrix[kEMatrixTypesNumber * uform_matrices_number_];
  ut_matrices_tr_arr_ =
      new EMatrix[kEMatrixTypesNumber * uform_matrices_number_];
}

void TestsEnvironment::SetTestMatricesDimensions() {
  SetRowMatricesDimensions(uform_matrices_number_);
  SetColumnMatricesDimensions(uform_matrices_number_);
  SetSquareMatricesDimensions(uform_matrices_number_);
  SetRectMatricesDimensions(uform_matrices_number_);
}

void TestsEnvironment::FillTestMatrices() {
  FillRowMatrices(uform_matrices_number_);
  FillColumnMatrices(uform_matrices_number_);
  FillSquareMatrices(uform_matrices_number_);
  FillRectMatrices(uform_matrices_number_);
}

void TestsEnvironment::SetRowMatricesDimensions(int& n) {
  for (int type = kRowPosElems; type <= kRowNegElemsx2; ++type) {
    for (int i = 0; i < n; ++i) {
      ut_matrices_arr_[type * n + i].SetDimensions(1, i + 2);
      ut_matrices_tr_arr_[type * n + i].SetDimensions(i + 2, 1);
    }
  }
}

void TestsEnvironment::SetColumnMatricesDimensions(int& n) {
  for (int type = kColumnPosElems; type <= kColumnNegElemsx2; ++type) {
    for (int i = 0; i < n; ++i) {
      ut_matrices_arr_[type * n + i].SetDimensions(i + 2, 1);
      ut_matrices_tr_arr_[type * n + i].SetDimensions(1, i + 2);
    }
  }
}

void TestsEnvironment::SetSquareMatricesDimensions(int& n) {
  for (int i = 0; i < n; ++i) {
    ut_unity_matrices_arr_[i].SetDimensions(i + 2, i + 2);
    for (int type = kSquarePosElems; type <= kSquareNegElemsx2; ++type) {
      ut_matrices_arr_[type * n + i].SetDimensions(i + 2, i + 2);
      ut_matrices_tr_arr_[type * n + i].SetDimensions(i + 2, i + 2);
    }
  }
}

void TestsEnvironment::SetRectMatricesDimensions(int& n) {
  int type = kVertRectPosElems;
  for (; type <= kVertRectNegElemsx2; ++type) {
    for (int i = 0; i < n; ++i) {
      ut_matrices_arr_[type * n + i].SetDimensions(i + 4, i + 2);
      ut_matrices_tr_arr_[type * n + i].SetDimensions(i + 4, i + 2);
    }
  }
  for (; type <= kHorRectNegElemsx2; ++type) {
    for (int i = 0; i < n; ++i) {
      ut_matrices_arr_[type * n + i].SetDimensions(i + 2, i + 4);
      ut_matrices_tr_arr_[type * n + i].SetDimensions(i + 2, i + 4);
    }
  }
}

void TestsEnvironment::FillRowMatrices(int& n) {
  for (int k = 0; k < n; ++k) {
    for (int i = 1; i <= k + 2; ++i) {
      ut_matrices_arr_[kRowPosElems * n + k](1, i) = 10 + i;
      ut_matrices_arr_[kRowPosElemsx2 * n + k](1, i) = 2 * (10 + i);
      ut_matrices_arr_[kRowNegElems * n + k](1, i) = -(10 + i);
      ut_matrices_arr_[kRowNegElemsx2 * n + k](1, i) = -2 * (10 + i);

      ut_matrices_tr_arr_[kRowPosElems * n + k](i, 1) = 10 + i;
      ut_matrices_tr_arr_[kRowPosElemsx2 * n + k](i, 1) = 2 * (10 + i);
      ut_matrices_tr_arr_[kRowNegElems * n + k](i, 1) = -(10 + i);
      ut_matrices_tr_arr_[kRowNegElemsx2 * n + k](i, 1) = -2 * (10 + i);
    }
  }
}

void TestsEnvironment::FillColumnMatrices(int& n) {
  for (int k = 0; k < n; ++k) {
    for (int i = 1; i <= k + 2; ++i) {
      ut_matrices_arr_[kColumnPosElems * n + k](i, 1) = i * 10 + 1;
      ut_matrices_arr_[kColumnPosElemsx2 * n + k](i, 1) = 2 * (i * 10 + 1);
      ut_matrices_arr_[kColumnNegElems * n + k](i, 1) = -(i * 10 + 1);
      ut_matrices_arr_[kColumnNegElemsx2 * n + k](i, 1) = -2 * (i * 10 + 1);

      ut_matrices_tr_arr_[kColumnPosElems * n + k](1, i) = i * 10 + 1;
      ut_matrices_tr_arr_[kColumnPosElemsx2 * n + k](1, i) = 2 * (i * 10 + 1);
      ut_matrices_tr_arr_[kColumnNegElems * n + k](1, i) = -(i * 10 + 1);
      ut_matrices_tr_arr_[kColumnNegElemsx2 * n + k](1, i) = -2 * (i * 10 + 1);
    }
  }
}

void TestsEnvironment::FillSquareMatrices(int& n) {
  for (int k = 0; k < n; ++k) {
    for (int i = 1; i <= k + 2; ++i) {
      ut_unity_matrices_arr_[k](i, i) = 1;
      for (int j = 1; j <= k + 2; ++j) {
        ut_matrices_arr_[kSquarePosElems * n + k](i, j) = i * 10 + j;
        ut_matrices_arr_[kSquarePosElemsx2 * n + k](i, j) = 2 * (i * 10 + j);
        ut_matrices_arr_[kSquareNegElems * n + k](i, j) = -(i * 10 + j);
        ut_matrices_arr_[kSquareNegElemsx2 * n + k](i, j) = -2 * (i * 10 + j);

        ut_matrices_tr_arr_[kSquarePosElems * n + k](i, j) = j * 10 + i;
        ut_matrices_tr_arr_[kSquarePosElemsx2 * n + k](i, j) = 2 * (j * 10 + i);
        ut_matrices_tr_arr_[kSquareNegElems * n + k](i, j) = -(j * 10 + i);
        ut_matrices_tr_arr_[kSquareNegElemsx2 * n + k](i, j) =
            -2 * (j * 10 + i);
      }
    }
  }
}

void TestsEnvironment::FillRectMatrices(int& n) {
  for (int k = 0; k < n; ++k) {
    // VERTICAL RECTANGULAR MATRICES
    for (int i = 1; i <= k + 4; ++i) {
      for (int j = 1; j <= k + 2; ++j) {
        ut_matrices_arr_[kVertRectPosElems * n + k](i, j) = i * 10 + j;
        ut_matrices_arr_[kVertRectPosElemsx2 * n + k](i, j) = 2 * (i * 10 + j);
        ut_matrices_arr_[kVertRectNegElems * n + k](i, j) = -(i * 10 + j);
        ut_matrices_arr_[kVertRectNegElemsx2 * n + k](i, j) = -2 * (i * 10 + j);

        ut_matrices_tr_arr_[kVertRectPosElems * n + k](i, j) = j * 10 + i;
        ut_matrices_tr_arr_[kVertRectPosElemsx2 * n + k](i, j) =
            2 * (j * 10 + i);
        ut_matrices_tr_arr_[kVertRectNegElems * n + k](i, j) = -(j * 10 + i);
        ut_matrices_tr_arr_[kVertRectNegElemsx2 * n + k](i, j) =
            -2 * (j * 10 + i);
      }
    }

    // HORIZONTAL RECTANGULAR MATRICES
    for (int i = 1; i <= k + 2; ++i) {
      for (int j = 1; j <= k + 4; ++j) {
        ut_matrices_arr_[kHorRectPosElems * n + k](i, j) = i * 10 + j;
        ut_matrices_arr_[kHorRectPosElemsx2 * n + k](i, j) = 2 * (i * 10 + j);
        ut_matrices_arr_[kHorRectNegElems * n + k](i, j) = -(i * 10 + j);
        ut_matrices_arr_[kHorRectNegElemsx2 * n + k](i, j) = -2 * (i * 10 + j);

        ut_matrices_tr_arr_[kHorRectPosElems * n + k](i, j) = j * 10 + i;
        ut_matrices_tr_arr_[kHorRectPosElemsx2 * n + k](i, j) =
            2 * (j * 10 + i);
        ut_matrices_tr_arr_[kHorRectNegElems * n + k](i, j) = -(j * 10 + i);
        ut_matrices_tr_arr_[kHorRectNegElemsx2 * n + k](i, j) =
            -2 * (j * 10 + i);
      }
    }
  }
}

void TestsEnvironment::TearDown() {
  TestMatricesArrayDel(ut_matrices_arr_);
  TestMatricesArrayDel(ut_matrices_tr_arr_);
}

void TestsEnvironment::TestMatricesArrayDel(EMatrix*& matrices_array) {
  if (matrices_array) {
    delete[] matrices_array;
    matrices_array = nullptr;
  }
}
