#pragma once

#include <cstdint>
#include <vector>
#include <unordered_map>

namespace utils {

// Is n a prime number?
bool isPrime(uint64_t n);

// Is factor a prime factor of n?
bool isPrimeFactor(uint64_t factor, uint64_t n);

// Returns an ordered list (asc) of all primes under limit
std::vector<uint64_t> genPrimesUnder(uint64_t limit);

// Returns a map {factor: exponent} in the prime factorization of n
// e.g. for 72 => {2: 3, 3: 2} b/c 72 = 2^3 * 3^2
std::unordered_map<uint32_t, uint32_t> genPrimeFactorization(uint32_t n);

// Uses the prime number theorem to APPROXIMATE the number of primes under n
// NOTE: This is not exact
double numPrimesUnder(uint64_t n);

} // namespace utils
