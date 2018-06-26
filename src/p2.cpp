#include <iostream>

int sumEvenFibonacciUnder(int limit) {
  int a = 1;
  int b = 1;
  int sum = 0;

  while (b < limit) {
    int next_term = a + b;
    a = b;
    b = next_term;

    if (next_term % 2 == 0) {
      sum += next_term;
    }
  }

  return sum;
}

int main(int argc, char** argv) {
  int sum = sumEvenFibonacciUnder(4000000);

  std::cout << "sum is: " << sum << std::endl;

  return 0;
}
