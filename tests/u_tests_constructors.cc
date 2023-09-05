#include "e_matrix_u_tests_environment.h"

TEST(ConstructorsTests, DefaultConstructor) {
  EMatrix test_matrix;

  EXPECT_EQ(test_matrix.get_rows(), 0);
  EXPECT_EQ(test_matrix.get_cols(), 0);
}

TEST(ConstructorsTests, ParametrizedConstructorInvalidArg1) {
  EXPECT_THROW(EMatrix test_matrix(0, 1), std::invalid_argument);
}

TEST(ConstructorsTests, ParametrizedConstructorInvalidArg2) {
  EXPECT_THROW(EMatrix test_matrix(1, 0), std::invalid_argument);
}

TEST(ConstructorsTests, ParametrizedConstructorInvalidArg3) {
  EXPECT_THROW(EMatrix test_matrix(0, 0), std::invalid_argument);
}

TEST(ConstructorsTests, ParametrizedConstructorInvalidArg4) {
  EXPECT_THROW(EMatrix test_matrix(-1, 1), std::invalid_argument);
}

TEST(ConstructorsTests, ParametrizedConstructorInvalidArg5) {
  EXPECT_THROW(EMatrix test_matrix(1, -1), std::invalid_argument);
}

TEST(ConstructorsTests, ParametrizedConstructorInvalidArg6) {
  EXPECT_THROW(EMatrix test_matrix(-1, -1), std::invalid_argument);
}

TEST(ConstructorsTests, ParametrizedConstructorOk1) {
  EMatrix test_matrix(1, 1);

  EXPECT_EQ(test_matrix.get_rows(), 1);
  EXPECT_EQ(test_matrix.get_cols(), 1);
}

TEST(ConstructorsTests, ParametrizedConstructorOk2) {
  EMatrix test_matrix(3, 2);

  EXPECT_EQ(test_matrix.get_rows(), 3);
  EXPECT_EQ(test_matrix.get_cols(), 2);
}

TEST(ConstructorsTests, ParametrizedConstructorOk3) {
  EMatrix test_matrix(2, 3);

  EXPECT_EQ(test_matrix.get_rows(), 2);
  EXPECT_EQ(test_matrix.get_cols(), 3);
}

TEST(ConstructorsTests, ParametrizedConstructorOk4) {
  EMatrix test_matrix(100, 101);

  EXPECT_EQ(test_matrix.get_rows(), 100);
  EXPECT_EQ(test_matrix.get_cols(), 101);
}
