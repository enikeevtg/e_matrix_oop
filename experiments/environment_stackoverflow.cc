#include <chrono>
#include <iostream>

#include "gtest/gtest.h"

std::string currentDateTime() {
  return std::to_string(
      std::chrono::steady_clock::now().time_since_epoch().count());
}

class TestEnvironment : public ::testing::Environment {
 public:
  // Assume there's only going to be a single instance of this class, so we can
  // just hold the timestamp as a const static local variable and expose it
  // through a static member function
  static std::string getStartTime() {
    static const std::string timestamp = currentDateTime();
    return timestamp;
  }

  // Initialise the timestamp.
  virtual void SetUp() { getStartTime(); }
};

class CnFirstTest : public ::testing::Test {
 protected:
  virtual void SetUp() { m_string = currentDateTime(); }
  std::string m_string;
};

TEST_F(CnFirstTest, Test1) {
  std::cout << TestEnvironment::getStartTime() << std::endl;
  std::cout << m_string << std::endl;
}

TEST_F(CnFirstTest, Test2) {
  std::cout << TestEnvironment::getStartTime() << std::endl;
  std::cout << m_string << std::endl;
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  // gtest takes ownership of the TestEnvironment ptr - we don't delete it.
  ::testing::AddGlobalTestEnvironment(new TestEnvironment);
  return RUN_ALL_TESTS();
}
