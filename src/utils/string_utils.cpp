#include "string_utils.h"
#include <iostream>

namespace utils {

std::vector<std::string> tokenize(
  const std::string& str,
  const std::string& delimeter
) {

  int32_t token_start = 0;
  int32_t token_stop = 0;
  int32_t delimeter_length = delimeter.length();

  // Ignore a leading delimeter
  if (str.substr(0, delimeter_length).compare(delimeter) == 0) {
    token_start += delimeter_length;
    token_stop += delimeter_length;
  }

  std::vector<std::string> tokens;

  // Iterate through str and look for delimeters. If there is a delimeter
  // we capture the string, move to the end of the delimeter, and start again.
  while (token_stop + delimeter_length <= str.length()) {

    // Consider a potential delimeter
    std::string potential_delimeter = str.substr(token_stop, delimeter_length);

    // Was it really the delimeter?
    if (potential_delimeter.compare(delimeter) == 0) {
      // If so, capture the token
      std::string token = str.substr(token_start, token_stop - token_start);
      tokens.push_back(token);

      // move to the next token. This handles trailing delimeters fine, but if
      // We don't have a trailing delimeter this will miss the last token
      token_start = token_stop + delimeter_length;
      token_stop = token_start;
    } else {
      // Consider the next possible delimeter
      token_stop++;
    }
  }

  // Capture the final token in the case that we don't have a trailing delimeter
  if (token_start != token_stop) {
    tokens.push_back(str.substr(token_start, token_stop + delimeter_length - token_start));
  }

  return tokens;
}

} // namespace utils
