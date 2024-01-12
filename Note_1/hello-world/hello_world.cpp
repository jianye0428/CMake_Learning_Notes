#include <cstdlib>
#include <iostream>
#include <string>

std::string SayHello();

int main() {
  std::cout << SayHello() << std::endl;
  return 0;
}

std::string SayHello() { return std::string("Hello, CMake World!"); }
