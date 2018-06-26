#include <iostream>
#include <utils/prime_utils.h>

int main(int argc, char** argv) {
  // uint64_t limit = 600851475143;
  // for (uint64_t i = limit; i > 0; i--) {
  //   std::cout << i << std::endl;
  //   if (isPrimeFactor(i, limit)) {
  //     std::cout << i << std::endl;
  //     break;
  //   }
  // }

  std::vector<uint64_t> primes = genPrimesUnder(600851475143);
  std::cout << primes.size() << std::endl;

  return 0;
}
