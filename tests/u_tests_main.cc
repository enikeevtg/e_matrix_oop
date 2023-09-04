#include "e_matrix_u_tests_environment.h"
#include "e_matrix_u_tests_fixture.h"

INSTANTIATE_TEST_SUITE_P(
    EMatrixUTestsFixture, EMatrixUTestsFixture,
    testing::Range(0, TestsEnvironment::uform_matrices_number_*
                              TestsEnvironment::kEMatrixTypesNumber -
                          1));

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::AddGlobalTestEnvironment(new TestsEnvironment);

  return RUN_ALL_TESTS();
}
