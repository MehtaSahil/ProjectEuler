#include <iostream>
#include "utils/prime_utils.h"

int main(int argc, char** argv) {

  uint64_t limit = 2000000;
  auto primes = utils::genPrimesUnder(limit);

  uint64_t sum = 0;
  for (int32_t i = 0; i < primes.size(); i++) {
    sum += primes[i];
  }

  std::cout << sum << std::endl;

  return 0;
}
