#ifndef DAY7_HPP
#define DAY7_HPP

#include <string>
#include "graph.hpp"

namespace dev {
namespace ciccarelli {
namespace day7 {
	int solve(const std::string& filename);
	Graph parseInstructions(const std::vector<std::string>& instructions);
} // namespace day7
} // namespace ciccarelli
} // namespace dev
#endif // DAY7_HPP
