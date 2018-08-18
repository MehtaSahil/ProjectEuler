#include <algorithm>
#include <iostream>
#include <string>
#include <limits>

// Returns true if val is a palindome, false otherwise
bool isPalindrome(int32_t val) {
  /*
  Easy way (maybe): turn into a string, reverse the string, compare versions
  Medium way (maybe): compare the first and last elements of the int and move inwards
  Harder way (maybe): find a pattern in those numbers which create palindromes
  Might be able to do something
  */

  std::string valStr = std::to_string(val);
  std::string valStrRev = valStr;
  std::reverse(valStrRev.begin(), valStrRev.end());

  // compare returns 0 if the strings are equal
  // We want to return true (1) if the strings are equal
  return !valStr.compare(valStrRev);
}

int main(int argc, char** argv) {
  int limit = 1000;

  int max_val = std::numeric_limits<int>::min();
  for (int32_t i = 100; i < limit; i++) {

    // start from j = i to prevent testing the same pair twice
    // e.g. i=5, j=78 AND i=78, j=5 don't both need to be tested
    for (int32_t j = i; j < limit; j++) {
      int32_t product = i * j;
      if (isPalindrome(product)) {
        if (product > max_val) {
          max_val = product;
        }
      }
    }
  }

  std::cout << max_val << std::endl;

  return 0;
}
