#ifndef COMMON_HPP
#define COMMON_HPP

#include <string>
#include <vector>

namespace dev {
namespace ciccarelli {

std::vector<std::string> readInput(const std::string& filename);
std::vector<std::string> split(const std::string& s, const std::string& delimiter);

}  // namespace ciccarelli
}  // namespace dev
#endif
