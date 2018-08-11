#include "prime_utils.h"
#include <math.h>

namespace utils {

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

  uint64_t sqrt_limit = (uint64_t) sqrt(limit);

  // There are no primes less than 2
  if (limit < 2) {
    return primes;
  }

  // Using the sieve of Eratosthenes
  // sieve[n] == false if n is prime
  // sieve[n] == true if n is composite
  std::unordered_map<uint64_t, bool> sieve;
  uint64_t current_prime = 2;
  while (current_prime < limit) {
    primes.push_back(current_prime);
    // Mark multiplesof the current prime (under limit) as composite
    uint64_t start = current_prime;
    for (uint64_t i = start; i < limit; i += current_prime) {
      sieve[i] = true;
    }

    // Move to next prime (next unmarked number)
    int scanner = current_prime;
    while (sieve[scanner]) {
      scanner++;
    }

    current_prime = scanner;

    if (current_prime > sqrt_limit) {
      break;
    }
  }

  for (uint64_t i = current_prime; i < limit; i++) {
    if (sieve[i]) {
      continue;
    }

    primes.push_back(i);
  }

  return primes;
}

std::unordered_map<uint32_t, uint32_t> genPrimeFactorization(uint32_t n) {
  std::unordered_map<uint32_t, uint32_t> factors;

  /*
  1) generate the primes under n
  2) Starting with 2, if the prime is a factor increment the val in the map
      where the key is the current prime. Additionally divide n by the prime
  3) continue to divide by the prime factor until this is no longer possible
  4) move to the next prime stopping at the end of the list
  */

  return factors;
}

double numPrimesUnder(uint64_t n) {
  // Use the prime number theorem
  // https://en.wikipedia.org/wiki/Prime_number_theorem
  return n / log(n);
}

} // namespace utils
