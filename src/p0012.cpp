#include <iostream>
#include <math.h>
#include "utils/prime_utils.h"

// Just uses trial division and counts. This is fine for small numbers,
// but breaks down quickly as the numbers get larger
int32_t get_num_factors(int64_t num) {
  int32_t num_factors = 0;

  // int64_t limit = (int) sqrt(num);

  for (int64_t i = 1; i <= num/2; i++) {
    if (num % i == 0) {
      num_factors++;
    }
  }

  return num_factors + 1;
}

// Uses the prime factorization to quickly calculate the number of factors
// e.g. 72 = 2^3 * 3*2 so it has (3+1) * (2+1) = 12 factors product of (exponents + 1)
int32_t get_num_factors_fast(int64_t n) {
  auto factorization = utils::genPrimeFactorization(n);

  int32_t num_factors = 1;
  for (const auto& elem : factorization) {
    // std::cout << elem.first << ": " << elem.second << std::endl;
    num_factors *= elem.second + 1;
  }

  return num_factors;
}

int64_t get_triangle_num(int32_t n) {
  return n * (n+1) / 2;
}

int main(int argc, char** argv) {

  int64_t n = 0;

  while (get_num_factors_fast(get_triangle_num(++n)) < 500);

  std::cout << get_triangle_num(n) << std::endl;

  return 0;
}
