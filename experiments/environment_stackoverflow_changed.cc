#include <chrono>
#include <iostream>

#include "gtest/gtest.h"

class TestsEnvironment : public ::testing::Environment {
 public:
  // Assume there's only going to be a single instance of this class, so we can
  // just hold the timestamp as a const static local variable and expose it
  // through a static member function
  static std::string currentDateTime() {
    std::cout << "currentDateTime() calling" << std::endl;
    return std::to_string(
        std::chrono::steady_clock::now().time_since_epoch().count());
  }

  static std::string getStartTime() {
    std::cout << "getStartTime() calling" << std::endl;
    static const std::string timestamp = currentDateTime();
    return timestamp;
  }

  // Initialise the timestamp.
  virtual void SetUp() { getStartTime(); }
};

class CnFirstTest : public ::testing::Test {
 protected:
  // virtual void SetUp() { m_string = currentDateTime(); }
  // std::string m_string;
};

TEST_F(CnFirstTest, Test1) {
  std::cout << TestsEnvironment::getStartTime() << std::endl;
  // std::cout << m_string << std::endl;
}

TEST_F(CnFirstTest, Test2) {
  std::cout << TestsEnvironment::getStartTime() << std::endl;
  // std::cout << m_string << std::endl;
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  // gtest takes ownership of the TestsEnvironment ptr - we don't delete it.
  ::testing::AddGlobalTestEnvironment(new TestsEnvironment);
  return RUN_ALL_TESTS();
}
