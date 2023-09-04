#include "e_matrix_u_tests_environment.h"
#include "e_matrix_u_tests_fixtures.h"

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::AddGlobalTestEnvironment(new TestsEnvironment);

  return RUN_ALL_TESTS();
}
