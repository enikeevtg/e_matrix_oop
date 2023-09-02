#ifndef E_MATRIXPLUS_TESTS_TESTS_ENV_H_
#define E_MATRIXPLUS_TESTS_TESTS_ENV_H_

#include <gtest/gtest.h>

#include "../e_matrix_oop.h"

class EMatrixUTestsEnvironment : public ::testing::Environment {
 public:
  enum EMatrixTypes {
    kRowPosElems = 0,
    kRowPosElemsx2,
    kRowNegElems,
    kRowNegElemsx2,

    kColumnPosElems,
    kColumnPosElemsx2,
    kColumnNegElems,
    kColumnNegElemsx2,

    kSquarePosElems,
    kSquarePosElemsx2,
    kSquareNegElems,
    kSquareNegElemsx2,

    kUnity,

    kVertRectPosElems,
    kVertRectPosElemsx2,
    kVertRectNegElems,
    kVertRectNegElemsx2,

    kHorRectPosElems,
    kHorRectPosElemsx2,
    kHorRectNegElems,
    kHorRectNegElemsx2,

    kEMatrixTypesNumber
  };

  void SetUp() override;
  void TearDown() override;

  void TestMatricesArraysMemAlloc();
  void SetTestMatricesDimensions();
  void SetRowMatricesDimensions(int& n);
  void SetColumnMatricesDimensions(int& n);
  void SetSquareMatricesDimensions(int& n);
  void SetRectMatricesDimensions(int& n);
  void FillTestMatrices();
  void FillRowMatrices(int& n);
  void FillColumnMatrices(int& n);
  void FillSquareMatrices(int& n);
  void FillRectMatrices(int& n);
  void TestMatricesArrayDel(EMatrix*& matrices_array);

  int uniform_matrices_number_{5};
  EMatrix* ut_matrices_arr_{nullptr};
  EMatrix* ut_matrices_tr_arr_{nullptr};
};

#endif  // E_MATRIXPLUS_TESTS_TESTS_ENV_H_

// enum EMatrixTypes {
//   kRowPosElems = 0,
//   kRowPosElemsTr,
//   kRowPosElemsx2,
//   kRowPosElemsx2Tr,
//   kRowNegElems,
//   kRowNegElemsTr,
//   kRowNegElemsx2,
//   kRowNegElemsx2Tr,

//   kColumnPosElems,
//   kColumnPosElemsTr,
//   kColumnPosElemsx2,
//   kColumnPosElemsx2Tr,
//   kColumnNegElems,
//   kColumnNegElemsTr,
//   kColumnNegElemsx2,
//   kColumnNegElemsx2Tr,

//   kSquarePosElems,
//   kSquarePosElemsTr,
//   kSquarePosElemsx2,
//   kSquarePosElemsx2Tr,
//   kSquareNegElems,
//   kSquareNegElemsTr,
//   kSquareNegElemsx2,
//   kSquareNegElemsx2Tr,

//   kUnity,

//   kVertRectPosElems,
//   kVertRectPosElemsTr,
//   kVertRectPosElemsx2,
//   kVertRectPosElemsx2Tr,
//   kVertRectNegElems,
//   kVertRectNegElemsTr,
//   kVertRectNegElemsx2,
//   kVertRectNegElemsx2Tr,

//   kHorRectPosElems,
//   kHorRectPosElemsTr,
//   kHorRectPosElemsx2,
//   kHorRectPosElemsx2Tr,
//   kHorRectNegElems,
//   kHorRectNegElemsTr,
//   kHorRectNegElemsx2,
//   kHorRectNegElemsx2Tr,

//   kEMatrixTypesNumber
// };
