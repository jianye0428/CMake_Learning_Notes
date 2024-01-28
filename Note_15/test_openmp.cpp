#include <omp.h>

#include <iostream>
#include <string>
int main(int argc, char *argv[]) {
  auto n = 1000000000;
  std::cout << "we will form sum of numbers from 1 to " << n << std::endl;
  // start timer
  auto t0 = omp_get_wtime();
  auto s = 0LL;
  for (auto i = 1; i <= n; i++) {
    s += i;
  }
  // stop timer
  auto t1 = omp_get_wtime();
  std::cout << "sum: " << s << std::endl;
  std::cout << "elapsed wall clock time: " << t1 - t0 << " seconds"
            << std::endl;
  return 0;
}