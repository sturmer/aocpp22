#ifndef COMMON_HPP
#define COMMON_HPP

#include <string>
#include <vector>
#include <iostream>

namespace dev {
namespace ciccarelli {

template <class T>
void printContainer(const std::vector<T>& c) {
  for (auto i : c)
    std::cout << i << " ";
  std::cout << '\n';
}

template <class T>
void printContainer(const std::vector<T>& c, const char* label) {
  for (auto i : c)
    std::cout << label <<  i << " ";
  std::cout << '\n';
}

std::vector<std::string> readInput(const std::string& filename);
std::vector<std::string> split(const std::string& s, const std::string& delimiter);
std::string join(const std::vector<std::string>& s, const std::string& delimiter);

/**
 * Strip blanks from front and back of the string.
 */
std::string chomp(const std::string& s);

}  // namespace ciccarelli
}  // namespace dev
#endif
