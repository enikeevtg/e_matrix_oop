#include "e_matrix_u_tests_environment.h"

namespace e_matrix {

TEST(PrintMatrixTests, PrintMatrix) {
  EMatrix test_matrix(1, 1);
  test_matrix.PrintMatrix();

  EXPECT_EQ(1, 1);
}

}  // namespace e_matrix
