#pragma once
#include <cstdint>
#include <vector>

// Is n a prime number?
bool isPrime(uint64_t n);

// Is factor a prime factor of n?
bool isPrimeFactor(uint64_t factor, uint64_t n);

// Returns an ordered list (asc) of all primes under limit
std::vector<uint64_t> genPrimesUnder(uint64_t limit);
