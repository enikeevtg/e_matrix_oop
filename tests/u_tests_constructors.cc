#include <limits>

#include "e_matrix_u_tests_environment.h"
// #include "e_matrix_u_tests_fixture.h"

TEST(ConstructorsTests, DefaultConstructor) {
  EMatrix matrix;
  EXPECT_EQ(0, matrix.get_rows());
  EXPECT_EQ(0, matrix.get_cols());
}

TEST(ConstructorsTests, ParametrizedConstructorException1) {
  EXPECT_THROW(EMatrix matrix(0, 1), std::invalid_argument);
}

TEST(ConstructorsTests, ParametrizedConstructorException2) {
  EXPECT_THROW(EMatrix matrix(1, 0), std::invalid_argument);
}

TEST(ConstructorsTests, ParametrizedConstructorException3) {
  EXPECT_THROW(EMatrix matrix(0, 0), std::invalid_argument);
}

TEST(ConstructorsTests, ParametrizedConstructorException4) {
  EXPECT_THROW(EMatrix matrix(-1, 1), std::invalid_argument);
}

TEST(ConstructorsTests, ParametrizedConstructorException5) {
  EXPECT_THROW(EMatrix matrix(1, -1), std::invalid_argument);
}

TEST(ConstructorsTests, ParametrizedConstructorException6) {
  EXPECT_THROW(EMatrix matrix(-1, -1), std::invalid_argument);
}

TEST(ConstructorsTests, ParametrizedConstructorOk1) {
  EMatrix matrix(1, 1);
  EXPECT_EQ(1, matrix.get_rows());
  EXPECT_EQ(1, matrix.get_cols());
}

TEST(ConstructorsTests, ParametrizedConstructorOk2) {
  EMatrix matrix(3, 2);
  EXPECT_EQ(3, matrix.get_rows());
  EXPECT_EQ(2, matrix.get_cols());
}

TEST(ConstructorsTests, ParametrizedConstructorOk3) {
  EMatrix matrix(2, 3);
  EXPECT_EQ(2, matrix.get_rows());
  EXPECT_EQ(3, matrix.get_cols());
}

TEST(ConstructorsTests, ParametrizedConstructorOk4) {

    EMatrix matrix(100, 101);
    EXPECT_EQ(100, matrix.get_rows());
    EXPECT_EQ(101, matrix.get_cols());

}
