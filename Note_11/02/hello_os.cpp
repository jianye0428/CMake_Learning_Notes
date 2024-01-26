#include <string>
#include <iostream>
/**
 * @brief Hello compiler function, this function implemented the function of
 * outputting different information based on different compilers.
 **/
std::string HelloOS();

int main() {
  std::cout << HelloOS() << std::endl;
  return EXIT_SUCCESS;
}

std::string HelloOS() {
#ifdef IS_WINDOWS
  return std::string("Hello from Windows!");
#elif IS_LINUX
  return std::string("Hello from Linux!");
#elif IS_MACOS
  return std::string("Hello from macOS!");
#else
  return std::string("Hello from an unknown system!");
#endif
}