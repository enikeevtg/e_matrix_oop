#include "e_matrix_u_tests_environment.h"

void TestsEnvironment::SetUp() {
  TestArraysMemAlloc();
  SetTestMatricesDimensions();
  FillTestMatrices();
  // for (int i = 0; i < uform_matr_number_ /* * kMatrTypesNumber*/; ++i)
  // {
  //   std::cout << i << std::endl;
  //   ut_matr_arr_[i].PrintMatrix();
  //   ut_matr_tr_arr_[i].PrintMatrix();
  // }
  // for (int i = 0; i < uform_matr_number_; ++i) {
  //   ut_unity_matr_arr_[i].PrintMatrix();
  // }
}

void TestsEnvironment::TestArraysMemAlloc() {
  ut_unity_matr_arr_ = new EMatrix[uform_matr_number_];
  ut_matr_arr_ = new EMatrix[kMatrTypesNumber * uform_matr_number_];
  ut_matr_x2_arr_ = new EMatrix[kMatrTypesNumber * uform_matr_number_];
  ut_matr_tr_arr_ = new EMatrix[kMatrTypesNumber * uform_matr_number_];
}

void TestsEnvironment::SetTestMatricesDimensions() {
  int n = uform_matr_number_;
  for (int i = 0; i < n; ++i) {
    // unity matrices setting:
    ut_unity_matr_arr_[i].SetDimensions(i + 2, i + 2);
    // row matrices setting:
    for (int type = kRowPosElems; type <= kRowNegElems; ++type) {
      ut_matr_arr_[type * n + i].SetDimensions(1, i + 2);
      ut_matr_x2_arr_[type * n + i].SetDimensions(1, i + 2);
      ut_matr_tr_arr_[type * n + i].SetDimensions(i + 2, 1);
    }
    // column matrices setting:
    for (int type = kColumnPosElems; type <= kColumnNegElems; ++type) {
      ut_matr_arr_[type * n + i].SetDimensions(i + 2, 1);
      ut_matr_x2_arr_[type * n + i].SetDimensions(i + 2, 1);
      ut_matr_tr_arr_[type * n + i].SetDimensions(1, i + 2);
    }
    // square matrices setting:
    for (int type = kSquarePosElems; type <= kSquareNegElems; ++type) {
      ut_matr_arr_[type * n + i].SetDimensions(i + 2, i + 2);
      ut_matr_x2_arr_[type * n + i].SetDimensions(i + 2, i + 2);
      ut_matr_tr_arr_[type * n + i].SetDimensions(i + 2, i + 2);
    }
    // horizontal matrices setting:
    for (int type = kHorRectPosElems; type <= kHorRectNegElems; ++type) {
      ut_matr_arr_[type * n + i].SetDimensions(i + 2, i + 4);
      ut_matr_x2_arr_[type * n + i].SetDimensions(i + 2, i + 4);
      ut_matr_tr_arr_[type * n + i].SetDimensions(i + 4, i + 2);
      // vertical matrices setting:
      for (int type = kVertRectPosElems; type <= kVertRectNegElems; ++type) {
        ut_matr_arr_[type * n + i].SetDimensions(i + 4, i + 2);
        ut_matr_x2_arr_[type * n + i].SetDimensions(i + 4, i + 2);
        ut_matr_tr_arr_[type * n + i].SetDimensions(i + 2, i + 4);
      }
    }
  }
}

void TestsEnvironment::FillTestMatrices() {
  int n = uform_matr_number_;
  for (int k = 0; k < n; ++k) {
    for (int i = 1; i <= k + 2; ++i) {
      // unity matrices filling:
      ut_unity_matr_arr_[k](i, i) = 1;
      // row matrices filling:
      ut_matr_arr_[kRowPosElems * n + k](1, i) = 10 + i;
      ut_matr_arr_[kRowNegElems * n + k](1, i) = -(10 + i);
      ut_matr_x2_arr_[kRowPosElems * n + k](1, i) = 2 * (10 + i);
      ut_matr_x2_arr_[kRowNegElems * n + k](1, i) = -2 * (10 + i);
      ut_matr_tr_arr_[kRowPosElems * n + k](i, 1) = 10 + i;
      ut_matr_tr_arr_[kRowNegElems * n + k](i, 1) = -(10 + i);
      // column matrices filling:
      ut_matr_arr_[kColumnPosElems * n + k](i, 1) = i * 10 + 1;
      ut_matr_arr_[kColumnNegElems * n + k](i, 1) = -(i * 10 + 1);
      ut_matr_x2_arr_[kColumnPosElems * n + k](i, 1) = 2 * (i * 10 + 1);
      ut_matr_x2_arr_[kColumnNegElems * n + k](i, 1) = -2 * (i * 10 + 1);
      ut_matr_tr_arr_[kColumnPosElems * n + k](1, i) = i * 10 + 1;
      ut_matr_tr_arr_[kColumnNegElems * n + k](1, i) = -(i * 10 + 1);
      // square matrices filling:
      for (int j = 1; j <= k + 2; ++j) {
        ut_matr_arr_[kSquarePosElems * n + k](i, j) = i * 10 + j;
        ut_matr_arr_[kSquareNegElems * n + k](i, j) = -(i * 10 + j);
        ut_matr_x2_arr_[kSquarePosElems * n + k](i, j) = 2 * (i * 10 + j);
        ut_matr_x2_arr_[kSquareNegElems * n + k](i, j) = -2 * (i * 10 + j);
        ut_matr_tr_arr_[kSquarePosElems * n + k](i, j) = j * 10 + i;
        ut_matr_tr_arr_[kSquareNegElems * n + k](i, j) = -(j * 10 + i);
      }
      // rectangular matrices filling:
      for (int j = 1; j <= k + 4; ++j) {
        // horizontal:
        ut_matr_arr_[kHorRectPosElems * n + k](i, j) = i * 10 + j;
        ut_matr_arr_[kHorRectNegElems * n + k](i, j) = -(i * 10 + j);
        ut_matr_x2_arr_[kHorRectPosElems * n + k](i, j) = 2 * (i * 10 + j);
        ut_matr_x2_arr_[kHorRectNegElems * n + k](i, j) = -2 * (i * 10 + j);
        ut_matr_tr_arr_[kHorRectPosElems * n + k](j, i) = i * 10 + j;
        ut_matr_tr_arr_[kHorRectNegElems * n + k](j, i) = -(i * 10 + j);
        // vertical:
        ut_matr_arr_[kVertRectPosElems * n + k](j, i) = i * 10 + j;
        ut_matr_arr_[kVertRectNegElems * n + k](j, i) = -(i * 10 + j);
        ut_matr_x2_arr_[kVertRectPosElems * n + k](j, i) = 2 * (i * 10 + j);
        ut_matr_x2_arr_[kVertRectNegElems * n + k](j, i) = -2 * (i * 10 + j);
        ut_matr_tr_arr_[kVertRectPosElems * n + k](i, j) = i * 10 + j;
        ut_matr_tr_arr_[kVertRectNegElems * n + k](i, j) = -(i * 10 + j);
      }
    }
  }
}

void TestsEnvironment::TearDown() {
  DeleteTestArray(ut_unity_matr_arr_);
  DeleteTestArray(ut_matr_arr_);
  DeleteTestArray(ut_matr_x2_arr_);
  DeleteTestArray(ut_matr_tr_arr_);
}

void TestsEnvironment::DeleteTestArray(EMatrix*& matrices_array) {
  if (matrices_array) {
    delete[] matrices_array;
    matrices_array = nullptr;
  }
}
