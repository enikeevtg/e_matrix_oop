#ifndef E_MATRIXPLUS_TESTS_TESTS_ENV_H_
#define E_MATRIXPLUS_TESTS_TESTS_ENV_H_

#include <gtest/gtest.h>

#include "../e_matrix_oop.h"

class TestsEnvironment : public ::testing::Environment {
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

    kVertRectPosElems,
    kVertRectPosElemsx2,
    kVertRectNegElems,
    kVertRectNegElemsx2,

    kHorRectPosElems,
    kHorRectPosElemsx2,
    kHorRectNegElems,
    kHorRectNegElemsx2,

    kMatrTypesNumber
  };

  void SetUp() override;
  void TearDown() override;

  static void TestArraysMemAlloc();
  static void SetTestMatricesDimensions();
  static void SetRowMatricesDimensions(int& n);
  static void SetColumnMatricesDimensions(int& n);
  static void SetSquareMatricesDimensions(int& n);
  static void SetRectMatricesDimensions(int& n);
  static void FillTestMatrices();
  static void FillRowMatrices(int& n);
  static void FillColumnMatrices(int& n);
  static void FillSquareMatrices(int& n);
  static void FillRectMatrices(int& n);
  static void TestMatricesArrayDel(EMatrix*& matrices_array);

  static inline int uform_matr_number_{5};
  static inline EMatrix* ut_unity_matr_arr_{nullptr};
  static inline EMatrix* ut_matrices_arr_{nullptr};
  static inline EMatrix* ut_matr_tr_arr_{nullptr};
};

#endif  // E_MATRIXPLUS_TESTS_TESTS_ENV_H_
