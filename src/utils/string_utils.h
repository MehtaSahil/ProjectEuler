#pragma once
#include <string>
#include <vector>

namespace utils {

/**
* Splits the input string into smaller strings split by delimeter
* e.g. if str="hello-world" calling tokenize(str, "-") returns ["hello", "world"]
*/
std::vector<std::string> tokenize(
  const std::string& str,
  const std::string& delimeter
);

} // namespace utils
