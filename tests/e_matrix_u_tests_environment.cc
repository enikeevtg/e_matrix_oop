#include "e_matrix_u_tests_environment.h"

void EMatrixUTestsEnvironment::SetUp() {
  TestMatricesArrMemAlloc();
  SetTestMatricesDimensions();
  FillTestMatrices();
};

void EMatrixUTestsEnvironment::TestMatricesArrMemAlloc() {
  test_matrices_arr_ =
      new EMatrix[kEMatrixTypesNumber * uniform_matrices_number_];
}

void EMatrixUTestsEnvironment::TearDown() {
  if (test_matrices_arr_) delete[] test_matrices_arr_;
};

void EMatrixUTestsEnvironment::SetTestMatricesDimensions() {
  SetRowMatricesDimensions(uniform_matrices_number_);
  SetColumnMatricesDimensions(uniform_matrices_number_);
  SetSquareMatricesDimensions(uniform_matrices_number_);
  SetRectMatricesDimensions(uniform_matrices_number_);
}

void EMatrixUTestsEnvironment::SetRowMatricesDimensions(int n) {
  for (int i = 0; i < n; ++i) {
    test_matrices_arr_[kRowPosElems * n + i].SetDimensions(1, i + 1);
    test_matrices_arr_[kRowPosElemsTr * n + i].SetDimensions(i + 1, 1);
    test_matrices_arr_[kRowPosElemsx2 * n + i].SetDimensions(1, i + 1);
    test_matrices_arr_[kRowPosElemsx2Tr * n + i].SetDimensions(i + 1, 1);
    test_matrices_arr_[kRowNegElems * n + i].SetDimensions(1, i + 1);
    test_matrices_arr_[kRowNegElemsTr * n + i].SetDimensions(i + 1, 1);
    test_matrices_arr_[kRowNegElemsx2 * n + i].SetDimensions(1, i + 1);
    test_matrices_arr_[kRowNegElemsx2Tr * n + i].SetDimensions(i + 1, 1);
  }
};

void EMatrixUTestsEnvironment::SetColumnMatricesDimensions(int n) {
  for (int i = 0; i < n; ++i) {
    test_matrices_arr_[kColumnPosElems * n + i].SetDimensions(i + 1, 1);
    test_matrices_arr_[kColumnPosElemsTr * n + i].SetDimensions(1, i + 1);
    test_matrices_arr_[kColumnPosElemsx2 * n + i].SetDimensions(i + 1, 1);
    test_matrices_arr_[kColumnPosElemsx2Tr * n + i].SetDimensions(1, i + 1);
    test_matrices_arr_[kColumnNegElems * n + i].SetDimensions(i + 1, 1);
    test_matrices_arr_[kColumnNegElemsTr * n + i].SetDimensions(1, i + 1);
    test_matrices_arr_[kColumnNegElemsx2 * n + i].SetDimensions(i + 1, 1);
    test_matrices_arr_[kColumnNegElemsx2Tr * n + i].SetDimensions(1, i + 1);
  }
};

void EMatrixUTestsEnvironment::SetSquareMatricesDimensions(int n) {
  for (int i = 0; i < n; ++i) {
    test_matrices_arr_[kSquarePosElems * n + i].SetDimensions(i + 2, i + 2);
    test_matrices_arr_[kSquarePosElemsTr * n + i].SetDimensions(i + 2, i + 2);
    test_matrices_arr_[kSquarePosElemsx2 * n + i].SetDimensions(i + 2, i + 2);
    test_matrices_arr_[kSquarePosElemsx2Tr * n + i].SetDimensions(i + 2, i + 2);
    test_matrices_arr_[kSquareNegElems * n + i].SetDimensions(i + 2, i + 2);
    test_matrices_arr_[kSquareNegElemsTr * n + i].SetDimensions(i + 2, i + 2);
    test_matrices_arr_[kSquareNegElemsx2 * n + i].SetDimensions(i + 2, i + 2);
    test_matrices_arr_[kSquareNegElemsx2Tr * n + i].SetDimensions(i + 2, i + 2);

    test_matrices_arr_[kUnity * n + i].SetDimensions(i + 2, i + 2);
  }
};

void EMatrixUTestsEnvironment::SetRectMatricesDimensions(int n) {
  for (int i = 0; i < n; ++i) {
    test_matrices_arr_[kVertRectPosElems * n + i].SetDimensions(i + 4, i + 2);
    test_matrices_arr_[kVertRectPosElemsTr * n + i].SetDimensions(i + 4, i + 2);
    test_matrices_arr_[kVertRectPosElemsx2 * n + i].SetDimensions(i + 4, i + 2);
    test_matrices_arr_[kVertRectPosElemsx2Tr * n + i].SetDimensions(i + 4,
                                                                    i + 2);
    test_matrices_arr_[kVertRectNegElems * n + i].SetDimensions(i + 4, i + 2);
    test_matrices_arr_[kVertRectNegElemsTr * n + i].SetDimensions(i + 4, i + 2);
    test_matrices_arr_[kVertRectNegElemsx2 * n + i].SetDimensions(i + 4, i + 2);
    test_matrices_arr_[kVertRectNegElemsx2Tr * n + i].SetDimensions(i + 4,
                                                                    i + 2);

    test_matrices_arr_[kHorRectPosElems * n + i].SetDimensions(i + 2, i + 4);
    test_matrices_arr_[kHorRectPosElemsTr * n + i].SetDimensions(i + 2, i + 4);
    test_matrices_arr_[kHorRectPosElemsx2 * n + i].SetDimensions(i + 2, i + 4);
    test_matrices_arr_[kHorRectPosElemsx2Tr * n + i].SetDimensions(i + 2,
                                                                   i + 4);
    test_matrices_arr_[kHorRectNegElems * n + i].SetDimensions(i + 2, i + 4);
    test_matrices_arr_[kHorRectNegElemsTr * n + i].SetDimensions(i + 2, i + 4);
    test_matrices_arr_[kHorRectNegElemsx2 * n + i].SetDimensions(i + 2, i + 4);
    test_matrices_arr_[kHorRectNegElemsx2Tr * n + i].SetDimensions(i + 2,
                                                                   i + 4);
  }
};

void EMatrixUTestsEnvironment::FillTestMatrices() {
  FillRowMatrices(uniform_matrices_number_);
  FillColumnMatrices(uniform_matrices_number_);
  FillSquareMatrices(uniform_matrices_number_);
  FillRectMatrices(uniform_matrices_number_);
}

void EMatrixUTestsEnvironment::FillRowMatrices(int n) {
  for (int k = 0; k < n; ++k) {
    for (int i = 1; i <= k + 1; ++i) {
      test_matrices_arr_[kRowPosElems * n + k](1, i) = 10 + i;
      test_matrices_arr_[kRowPosElemsTr * n + k](i, 1) = 10 + i;
      test_matrices_arr_[kRowPosElemsx2 * n + k](1, i) = 2 * (10 + i);
      test_matrices_arr_[kRowPosElemsx2Tr * n + k](i, 1) = 2 * (10 + i);
      test_matrices_arr_[kRowNegElems * n + k](1, i) = -(10 + i);
      test_matrices_arr_[kRowNegElemsTr * n + k](i, 1) = -(10 + i);
      test_matrices_arr_[kRowNegElemsx2 * n + k](1, i) = -2 * (10 + i);
      test_matrices_arr_[kRowNegElemsx2Tr * n + k](i, 1) = -2 * (10 + i);
    }
  }
};

void EMatrixUTestsEnvironment::FillColumnMatrices(int n) {
  for (int k = 0; k < n; ++k) {
    for (int i = 1; i <= k + 1; ++i) {
      test_matrices_arr_[kColumnPosElems * n + k](i, 1) = i * 10 + 1;
      test_matrices_arr_[kColumnPosElemsTr * n + k](1, i) = i * 10 + 1;
      test_matrices_arr_[kColumnPosElemsx2 * n + k](i, 1) = 2 * (i * 10 + 1);
      test_matrices_arr_[kColumnPosElemsx2Tr * n + k](1, i) = 2 * (i * 10 + 1);
      test_matrices_arr_[kColumnNegElems * n + k](i, 1) = -(i * 10 + 1);
      test_matrices_arr_[kColumnNegElemsTr * n + k](1, i) = -(i * 10 + 1);
      test_matrices_arr_[kColumnNegElemsx2 * n + k](i, 1) = -2 * (i * 10 + 1);
      test_matrices_arr_[kColumnNegElemsx2Tr * n + k](1, i) = -2 * (i * 10 + 1);
    }
  }
};

void EMatrixUTestsEnvironment::FillSquareMatrices(int n) {
  // SQUARE AND UNITY MATRICES
  for (int k = 0; k < n; ++k) {
    for (int i = 1; i <= k + 2; ++i) {
      test_matrices_arr_[kUnity * n + k](i, i) = 1;
      for (int j = 1; j <= k + 2; ++j) {
        test_matrices_arr_[kSquarePosElems * n + k](i, j) = i * 10 + j;
        test_matrices_arr_[kSquarePosElemsTr * n + k](i, j) = i * 10 + j;
        test_matrices_arr_[kSquarePosElemsx2 * n + k](i, j) = 2 * (i * 10 + j);
        test_matrices_arr_[kSquarePosElemsx2Tr * n + k](i, j) =
            2 * (i * 10 + j);
        test_matrices_arr_[kSquareNegElems * n + k](i, j) = -(i * 10 + j);
        test_matrices_arr_[kSquareNegElemsTr * n + k](i, j) = -(i * 10 + j);
        test_matrices_arr_[kSquareNegElemsx2 * n + k](i, j) = -2 * (i * 10 + j);
        test_matrices_arr_[kSquareNegElemsx2Tr * n + k](i, j) =
            -2 * (i * 10 + j);
      }
    }
  }
};

void EMatrixUTestsEnvironment::FillRectMatrices(int n) {
  for (int k = 0; k < n; ++k) {
    // VERTICAL RECTANGULAR MATRICES
    for (int i = 1; i <= k + 4; ++i) {
      for (int j = 1; j <= k + 2; ++j) {
        test_matrices_arr_[kVertRectPosElems * n + k](i, j) = i * 10 + j;
        test_matrices_arr_[kVertRectPosElemsTr * n + k](i, j) = i * 10 + j;
        test_matrices_arr_[kVertRectPosElemsx2 * n + k](i, j) =
            2 * (i * 10 + j);
        test_matrices_arr_[kVertRectPosElemsx2Tr * n + k](i, j) =
            2 * (i * 10 + j);
        test_matrices_arr_[kVertRectNegElems * n + k](i, j) = -(i * 10 + j);
        test_matrices_arr_[kVertRectNegElemsTr * n + k](i, j) = -(i * 10 + j);
        test_matrices_arr_[kVertRectNegElemsx2 * n + k](i, j) =
            -2 * (i * 10 + j);
        test_matrices_arr_[kVertRectNegElemsx2Tr * n + k](i, j) =
            -2 * (i * 10 + j);
      }
    }

    // HORIZONTAL RECTANGULAR MATRICES
    for (int i = 1; i <= k + 2; ++i) {
      for (int j = 1; j <= k + 4; ++j) {
        test_matrices_arr_[kHorRectPosElems * n + k](i, j) = i * 10 + j;
        test_matrices_arr_[kHorRectPosElemsTr * n + k](i, j) = i * 10 + j;
        test_matrices_arr_[kHorRectPosElemsx2 * n + k](i, j) = 2 * (i * 10 + j);
        test_matrices_arr_[kHorRectPosElemsx2Tr * n + k](i, j) =
            2 * (i * 10 + j);
        test_matrices_arr_[kHorRectNegElems * n + k](i, j) = -(i * 10 + j);
        test_matrices_arr_[kHorRectNegElemsTr * n + k](i, j) = -(i * 10 + j);
        test_matrices_arr_[kHorRectNegElemsx2 * n + k](i, j) =
            -2 * (i * 10 + j);
        test_matrices_arr_[kHorRectNegElemsx2Tr * n + k](i, j) =
            -2 * (i * 10 + j);
      }
    }
  }
};
