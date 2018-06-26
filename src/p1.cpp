// Project Euler problem 1: https://projecteuler.net/problem=1
#include <iostream>

// My solution
int sumThreeOrFiveBelow(int limit) {
  int sum = 0;
  for (int i = 0; i < limit; i++) {
    if (i % 3 == 0 || i % 5 == 0) {
      sum += i;
    }
  }

  return sum;
}

// Fast solution (from solutions)
int sumDivisibleByN(int n, int limit) {
  int p = limit / n;
  return n*(p*(p+1)) / 2;
}

int main(int argc, char** argv) {
  // My solution
  int limit = 1000;
  int sum = sumThreeOrFiveBelow(limit);
  std::cout << "sum is: " << sum << std::endl;

  // Fast solution (from solutions)
  sum = sumDivisibleByN(3, limit)
        + sumDivisibleByN(5, limit)
        - sumDivisibleByN(15, limit);
  std::cout << "sum is: " << sum << std::endl;

  return 0;
}
