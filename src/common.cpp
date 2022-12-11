#include "common.hpp"

#include <fstream>
#include <iostream>

#include "doctest.h"

using namespace std;

namespace dev {
namespace ciccarelli {

vector<string> readInput(const string& filename) {
  ifstream file(filename);
  string line;
  vector<string> file_contents;

  while (getline(file, line)) {
    file_contents.push_back(line);
  }

  // for (auto line : file_contents)
  // 	cout << line << endl;

  return file_contents;
}

vector<string> split(const string& s, const string& delimiter) {
  if (s.empty())
    return {};

  vector<string> res = {};
  size_t old_pos = 0;
  size_t new_pos = s.find(delimiter);

  string token;

  while (new_pos != string::npos) {
    token = s.substr(old_pos, new_pos - old_pos);
		if (!token.empty())
    	res.push_back(token);

    old_pos = new_pos + 1;
    new_pos = s.find(delimiter, new_pos + 1);
    // cout << "old_pos: " << old_pos << ", new_pos: " << new_pos << "\n";
  }

  res.push_back(s.substr(old_pos, string::npos));

  return res;
}

TEST_CASE("can split string") {
  string s = "move 11 from 3 to 4";
  vector<string> splits = split(s, " ");
  CHECK(splits.size() == 6);
  CHECK(splits[0] == "move");
  CHECK(splits[1] == "11");
  CHECK(splits[2] == "from");
  CHECK(splits[3] == "3");
  CHECK(splits[4] == "to");
  CHECK(splits[5] == "4");
}

}  // namespace ciccarelli
}  // namespace dev
