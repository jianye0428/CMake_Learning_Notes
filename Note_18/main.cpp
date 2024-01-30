#include <iostream>
#include <string>

#include "sum_integers.h"

int main(int argc, char *argv[]) {
  std::vector<int> integers;
  for (auto i = 1; i < argc; i++) {
    integers.push_back(std::stoi(argv[i]));
  }
  auto sum = sum_integers(integers);
  std::cout << sum << std::endl;

  return 0;
}