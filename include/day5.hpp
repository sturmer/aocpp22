#ifndef DAY5_HPP
#define DAY5_HPP
#include <array>
#include <string>
#include <vector>

#include "common.hpp"

using namespace std;

namespace day5 {
tuple<vector<string>, vector<string>::const_iterator> parsePiles(const vector<string>& lines);

vector<array<int, 3>> parseInstructions(const vector<string>& instructions,
                                        vector<string>::const_iterator cur_line);
string solve(const string& filename);

string solvePartTwo(const string& filename);
}  // namespace day5

#endif
