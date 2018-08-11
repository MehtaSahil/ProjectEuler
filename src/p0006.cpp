#include <iostream>

// Returns (1 + 2 + ... + n)^2
uint64_t squareOfSumN(uint64_t n) {
  // Recall that 1 + 2 + ... + n = (1/2)*n*(n+1)
  // (1 + 2 + ... + n)^2 = 1^3 + 2^3 + ... + n^3

  uint64_t sum = n*(n+1) / 2;

  return sum*sum;
}

uint64_t sumOfSquareN(uint64_t n) {
  return (n*(n+1))*(2*n + 1) / 6;
}

int main(int argc, char** argv) {

  uint64_t n = 100;

  uint64_t sum = n*(n+1) / 2;

  // After a little bit of algebra...
  uint64_t result = sum*(sum - (2*n + 1)/3);
  // uint64_t result = squareOfSumN(n) - sumOfSquareN(n);

  std::cout << result << std::endl;

  return 0;
}
