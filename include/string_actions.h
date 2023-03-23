#pragma once
#include <string>

template<class Out>
void SplitString(const std::string &str, Out os, const char sep = '\t') {
  typedef std::string::const_iterator iter;
  auto not_sep = [sep](const char c) { return c != sep; };
  auto is_sep = [sep](const char c) { return c == sep; };

  iter i = str.begin();
  while (i != str.end()) {
    i = std::find_if(i, str.end(), not_sep);
    iter j = std::find_if(i, str.end(), is_sep);
    if (i != str.end()) {
      *os++ = std::string(i, j);
    }
    i = j;
  }
}