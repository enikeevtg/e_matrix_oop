#include "e_matrix_u_tests_environment.h"
#include "e_matrix_u_tests_fixtures.h"

namespace e_matrix {

TEST_P(EMatrixAccessorsMutators, GetRowsOk) {
  int i = GetParam();
  EMatrix test_matrix(i, 1);

  EXPECT_EQ(test_matrix.get_rows(), i);
}

TEST_P(EMatrixAccessorsMutators, GetColsOk) {
  int i = GetParam();
  EMatrix test_matrix(1, i);

  EXPECT_EQ(test_matrix.get_cols(), i);
}

TEST_P(EMatrixAccessorsMutators, SetRowsThrow0) {
  int i = GetParam();
  EMatrix test_matrix(i, i);

  EXPECT_THROW(test_matrix.set_rows(0), std::invalid_argument);
}

TEST_P(EMatrixAccessorsMutators, SetRowsThrowINTMIN) {
  int i = GetParam();
  EMatrix test_matrix(i, i);

  EXPECT_THROW(test_matrix.set_rows(INT32_MIN), std::invalid_argument);
}

TEST_P(EMatrixAccessorsMutators, SetRowsOk) {
  int i = GetParam();
  EMatrix test_matrix(1, 1);
  test_matrix.set_rows(i);

  EXPECT_EQ(test_matrix.get_rows(), i);
}

TEST_P(EMatrixAccessorsMutators, SetColsThrow0) {
  int i = GetParam();
  EMatrix test_matrix(i, i);

  EXPECT_THROW(test_matrix.set_cols(0), std::invalid_argument);
}

TEST_P(EMatrixAccessorsMutators, SetColsThrowINTMIN) {
  int i = GetParam();
  EMatrix test_matrix(i, i);

  EXPECT_THROW(test_matrix.set_cols(INT32_MIN), std::invalid_argument);
}

TEST_P(EMatrixAccessorsMutators, SetColsOk) {
  int i = GetParam();
  EMatrix test_matrix(1, 1);
  test_matrix.set_cols(i);

  EXPECT_EQ(test_matrix.get_cols(), i);
}

TEST_P(EMatrixAccessorsMutators, SetDimensionsThrow0) {
  int i = GetParam();
  EMatrix test_matrix(i, i);

  EXPECT_THROW(test_matrix.SetDimensions(0, i), std::invalid_argument);
  EXPECT_THROW(test_matrix.SetDimensions(i, 0), std::invalid_argument);
  EXPECT_THROW(test_matrix.SetDimensions(0, 0), std::invalid_argument);
}

TEST_P(EMatrixAccessorsMutators, SetDimensionsThrowINTMIN) {
  int i = GetParam();
  EMatrix test_matrix(i, i);

  EXPECT_THROW(test_matrix.SetDimensions(i, INT32_MIN), std::invalid_argument);
  EXPECT_THROW(test_matrix.SetDimensions(INT32_MIN, i), std::invalid_argument);
  EXPECT_THROW(test_matrix.SetDimensions(INT32_MIN, INT32_MIN),
               std::invalid_argument);
}

TEST_P(EMatrixAccessorsMutators, SetDimensionsOk) {
  int i = GetParam();
  EMatrix test_matrix(1, 1);
  test_matrix.SetDimensions(i, i);

  EXPECT_EQ(test_matrix.get_rows(), i);
  EXPECT_EQ(test_matrix.get_cols(), i);
}

}  // namespace e_matrix
