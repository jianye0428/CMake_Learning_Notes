#include <cstdlib>
#include <iostream>
#include <string>

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

std::string ArchInfo();

int main() {
  std::cout << ArchInfo() << std::endl;
  return EXIT_SUCCESS;
}

std::string ArchInfo() {
  std::string arch_info(TOSTRING(ARCHITECTURE));
  arch_info += std::string(" architecture.  ");
#ifdef IS_32_BIT_ARCH
  return arch_info + std::string("Compiled on a 32 bit host processor.");
#elif IS_64_BIT_ARCH
  return arch_info + std::string("Compiled on a 64 bit host processor.");
#else
  return arch_info + std::string("Neither 32 not 64 bit, puzzling ...");
#endif
}