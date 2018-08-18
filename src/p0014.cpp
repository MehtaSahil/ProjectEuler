#include <iostream>
#include <unordered_map>
#include <chrono>
#include <limits>
#include <cstdint>

/**
* Returns length of collatz sequence starting from n and ending at 1
*/
int32_t collatz_sequence_length(
    int64_t n,
    const std::unordered_map<int64_t, int32_t>& length_cache
) {
  if (n <= 1) {
    return 0;
  }

  int32_t num_steps = 0;

  while (n != 1) {

    // If we've seen this value before, just use the cached value
    if (length_cache.count(n) > 0) {
      return length_cache.at(n) + num_steps;
    }

    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = 3*n + 1;
    }

    num_steps++;
  }

  return num_steps;
}

int main(int argc, char** argv) {

  int64_t limit = 1000000;

  // Map from n : collatz_sequence_length(n) used to avoid duplicate work
  // Based on preliminary tests, expect speed increases of about 2x
  std::unordered_map<int64_t, int32_t> length_cache;

  int32_t max_length = std::numeric_limits<int32_t>::min();
  int32_t max_num = 0;

  auto start = std::chrono::high_resolution_clock::now();
  for (int64_t i = 1; i < limit; i++) {
    int32_t sequence_length = collatz_sequence_length(i, length_cache);

    // std::cout << "inserting " << i << " into length_cache with value " << sequence_length << std::endl;
    length_cache[i] = sequence_length;
    // std::cout << i << " : " << length_cache[i] << std::endl;
    if (sequence_length > max_length) {
       max_length = sequence_length;
       max_num = i;
    }
  }

  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(
      stop-start
  ).count();

  std::cout << max_length << std::endl;
  std::cout << max_num << std::endl;
  std::cout << "time for run: " << (float)(duration)/1e6 << " seconds" << std::endl;


  return 0;
}
