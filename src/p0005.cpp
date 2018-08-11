#include <iostream>

// Returns true if n is evenly divisible by all [low, high] inclusive
bool divisibleByAll(int low, int high, int n) {
  for (int i = low; i <= high; i++) {
    // If not evenly divisible
    if (!((n % i) == 0)) {
      return false;
    }
  }

  return true;
}

int main(int argc, char** argv) {
  int i = 0;
  while (true) {
    if (divisibleByAll(1, 20, ++i)) {
      break;
    }
  }

  std::cout << i << std::endl;

  return 0;
}
