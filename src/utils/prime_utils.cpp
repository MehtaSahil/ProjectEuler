#include "prime_utils.h"
#include <math.h>
#include <iostream>

bool isPrime(uint64_t n) {
  if (n <= 1) {
    return false;
  }

  int num_divisors = 0;

  int divisor_limit = (int) sqrt(n);
  for (int i = 2; i <= divisor_limit; i++) {
    if (n % i == 0) {
      num_divisors++;
    }
  }

  return num_divisors == 0;
}

bool isPrimeFactor(uint64_t factor, uint64_t n) {
  return isPrime(factor) && (n % factor) == 0;
}

std::vector<uint64_t> genPrimesUnder(uint64_t limit) {
  std::vector<uint64_t> primes;

  // There are no primes less than 2
  if (limit < 2) {
    return primes;
  }

  // Using the sieve of Eratosthenes
  // sieve[n] == false if n is prime
  // sieve[n] == true if n is composite
  bool* sieve = new bool[limit];
  uint64_t current_prime = 2;
  while (current_prime < limit) {
    primes.push_back(current_prime);
    // Mark multiplesof the current prime (under limit) as composite
    uint64_t start = current_prime*current_prime;
    for (uint64_t i = start; i < limit; i += current_prime) {
      sieve[i] = true;
    }

    // Move to next prime (next unmarked number)
    int scanner = current_prime;
    while (sieve[scanner]) {
      scanner++;
    }

    current_prime = scanner;
  }

  delete[] sieve;

  return primes;
}
