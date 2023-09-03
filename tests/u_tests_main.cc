#include "e_matrix_u_tests_environment.h"
#include "e_matrix_u_tests_fixture.h"

// ::testing::Environment* const env = ::testing::AddGlobalTestEnvironment(new TestsEnvironment);

INSTANTIATE_TEST_SUITE_P(
    EMatrixUTestsFixture, EMatrixUTestsFixture,
    // testing::Range(0, 5 * TestsEnvironment::kEMatrixTypesNumber));
    testing::Range(0, 1 * 8));

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::AddGlobalTestEnvironment(new TestsEnvironment);
  // TestsEnvironment* const env = new TestsEnvironment;

  return RUN_ALL_TESTS();
}
