#include "e_matrix_u_tests_environment.h"
#include "e_matrix_u_tests_fixture.h"

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::AddGlobalTestEnvironment(new EMatrixUTestsEnvironment);

  return RUN_ALL_TESTS();
}
