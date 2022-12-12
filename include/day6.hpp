#ifndef DAY6_HPP
#define DAY6_HPP

#include <string>
#include <unordered_set>

namespace dev {
namespace ciccarelli {

namespace day6 {

int findMarker(const std::string& buf, const int sequence_length);
int solve(const std::string& filename);
std::unordered_set<char> histogram(const std::string& buf);

}  // namespace day6
}  // namespace ciccarelli
}  // namespace dev

#endif
