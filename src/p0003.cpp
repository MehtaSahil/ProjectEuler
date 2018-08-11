#include <iostream>
#include <math.h>
#include <utils/prime_utils.h>

int main(int argc, char** argv) {
  int64_t limit = 600851475143;
  int64_t sqrt_limit = (int64_t) sqrt(limit) + 1;

  // Instead of maximizing over all, just pick the first when iterating backward
  for (uint64_t i = sqrt_limit; i > 0; i--) {
    // Even numbers can't be prime factors
    if (i % 2 == 0) {
      continue;
    }

    if (utils::isPrimeFactor(i, limit)) {
      std::cout << i << std::endl;
      break;
    }
  }

  return 0;
}
