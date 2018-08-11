#include <iostream>
#include <math.h>
#include <utils/prime_utils.h>
#include <chrono>

// Tests all numbers beginning with 3 and counts the number of primes
// Until we've reached the nth prime. Returns that nth prime
int32_t bruteForcePrime(int32_t nth_prime) {
  int32_t prime_index = 1;
  int32_t current_num = 3;
  int32_t current_prime = 3;

  while (prime_index < nth_prime) {
    if (utils::isPrime(current_num)) {
      prime_index++;
      current_prime = current_num;
    }

    // Even numbers can't be prime
    current_num += 2;
  }

  return current_prime;
}

// Solves N for x = N / ln(N) = pi(N)
// Essentially uses a binary search b/c we know that pi(N) increases with N
int64_t primeUpperLimit(int32_t x, int32_t guess) {
  int64_t low = 0;
  int64_t high = guess*2;

  // Correct for a bad guess
  while (utils::numPrimesUnder(high) < 2*x) {
    high *= 2;
  }

  while (high > low + 1) {
    // Pick the middle element
    int64_t mid = (high + low) / 2;
    int64_t num_primes_under = (int64_t) utils::numPrimesUnder(mid);

    // std::cout << mid << ":" << high << ":" << low << std::endl;

    // If we hit the exact solution, immediately return
    if (num_primes_under == x) {
      return mid;
    }

    // If the midpoint is above the num, reset the upper limit
    // Else reset the lower limit
    if (num_primes_under > x) {
      high = mid;
    } else {
      low = mid;
    }
  }

  return 0;
}

int32_t sievePrime(int32_t nth_prime) {
  /* Using the prime number theorem: pi(N) ~ N/ln(N)
  * pi(N) = number of prime numbers under N
  * We want pi(N) = nth_prime
  *
  * The tricky part here is solving for N (sieve_limit)
  */

  uint64_t sieve_limit = primeUpperLimit(nth_prime, 500000);
  std::vector<uint64_t> primes = utils::genPrimesUnder(sieve_limit + 1);

  return primes[nth_prime - 1];
}

int main(int argc, char** argv) {
  int32_t n = 10001;
  int32_t result = sievePrime(n);
  std::cout << result << std::endl;

  // Performance testing
  // for (int32_t n = 10000; n < 100000; n += 10000) {
  //   int32_t num_trials = 25;
  //   auto start = std::chrono::high_resolution_clock::now();
  //   for (int i = 0; i < num_trials; i++) {
  //     bruteForcePrime(n);
  //   }
  //   auto mid = std::chrono::high_resolution_clock::now();
  //   for (int i = 0; i < num_trials; i++) {
  //     sievePrime(n);
  //   }
  //   auto stop = std::chrono::high_resolution_clock::now();
  //
  //   auto bruteDuration = std::chrono::duration_cast<std::chrono::microseconds>(mid-start).count();
  //   auto sieveDuration = std::chrono::duration_cast<std::chrono::microseconds>(stop-mid).count();
  //
  //   // From previous runs, sievePrime for n = 10001 is ~1.75  times faster!
  //   // The advantage for n = 50000 grows to over 3.1 times
  //   // std::cout << "performance factor: " << (double) bruteDuration / (double) sieveDuration << std::endl;
  //   double performance_factor = (double) bruteDuration / (double) sieveDuration;
  //
  //   std::cout << "n=" << n << ", performance_factor=" << performance_factor << std::endl;
  // }

  // n=10000, performance_factor=1.80002
  // n=20000, performance_factor=2.13358
  // n=30000, performance_factor=2.49849
  // n=40000, performance_factor=2.90021
  // n=50000, performance_factor=2.77825
  // n=60000, performance_factor=3.049
  // n=70000, performance_factor=2.92771
  // n=90000, performance_factor=3.29885

  return 0;
}
