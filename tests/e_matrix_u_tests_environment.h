#ifndef E_MATRIXPLUS_TESTS_TESTS_ENV_H_
#define E_MATRIXPLUS_TESTS_TESTS_ENV_H_

#include <gtest/gtest.h>

#include "../e_matrix_oop.h"

namespace e_matrix {

class TestsEnvironment : public ::testing::Environment {
 public:
  enum EMatrixTypes {
    kRowPosElems = 0,
    kRowNegElems,

    kColumnPosElems,
    kColumnNegElems,

    kSquarePosElems,
    kSquareNegElems,

    kHorRectPosElems,
    kHorRectNegElems,

    kVertRectPosElems,
    kVertRectNegElems,

    kMatrTypesNumber
  };

  void SetUp() override;
  void TearDown() override;

  static void TestArraysMemAlloc();
  static void SetTestMatricesDimensions();
  static void FillTestArrays();
  static void DeleteTestArray(EMatrix*& matrices_array);

  static inline int uform_matr_number_{5};
  static inline EMatrix* ut_unity_matr_arr_{nullptr};
  static inline EMatrix* ut_matr_arr_{nullptr};
  static inline EMatrix* ut_matr_x2_arr_{nullptr};
  static inline EMatrix* ut_matr_tr_arr_{nullptr};
  static inline double* ut_det_arr_{nullptr};
};

}  // namespace e_matrix

#endif  // E_MATRIXPLUS_TESTS_TESTS_ENV_H_

