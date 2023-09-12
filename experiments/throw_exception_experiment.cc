#include <iostream>

double divide(int a, int b) {
  if (b == 0) throw "Division by zero!";
  return a / b;
}

int main() {
  std::cout << "First try\n4 / 0:" << std::endl;
  try {
    double c{divide(4, 0)};
    std::cout << c << std::endl;
  } catch (const char* error_message) {
    std::cout << error_message << std::endl;
  }
  std::cout << "Second try\n4 / 2:" << std::endl;
  try {
    double c{divide(4, 2)};
    std::cout << c << std::endl;
  } catch (const char* error_message) {
    std::cout << error_message << std::endl;
  }
  std::cout << "The End..." << std::endl;
}
