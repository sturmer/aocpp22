
#include "day7.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "common.hpp"

using namespace std;
namespace dev {
namespace ciccarelli {
namespace day7 {

int solve(const string& filename) {
  auto lines = readInput(filename);

  Graph graph = parseInstructions(lines);
  graph.computeDirSizes();

  int res = 0;
  for (const pair<string, vector<string>>& p : graph.adjList) {
    if (!p.second.empty() && graph.size[p.first] <= 100000) {
      res += graph.size[p.first];
    }
  }

  return res;
}

int solvePartTwo(const std::string& filename) {
  const int totalFilesystemSize = 70000000;
  const int neededUnusedSpace = 30000000;

  auto lines = readInput(filename);

  Graph graph = parseInstructions(lines);
  graph.computeDirSizes();

  const int usedSpace = graph.size["/"];
  const int currentlyUnusedSpace = totalFilesystemSize - usedSpace;
  // cout << "Used space: " << usedSpace << endl;

  vector<int> candidates;
  for (const pair<string, vector<string>>& p : graph.adjList) {
    if (!p.second.empty() && currentlyUnusedSpace + graph.size[p.first] >= neededUnusedSpace) {
      candidates.push_back(graph.size[p.first]);
    }
  }

  // printContainer(candidates);
  return *min_element(candidates.cbegin(), candidates.cend());
}

Graph parseInstructions(const vector<string>& instructions) {
  Graph g;
  vector<string> stack;

  for (const auto& i : instructions) {
    // cout << "Parse `" << i << "`\n";
    // cout << "Stack: ";
    // printContainer(stack);
    // cout << "Graph: " << g << endl;

    if (i.starts_with("$ cd ")) {
      const string dirName = i.substr(strlen("$ cd "));
      // cout << "cd to directory '" << dirName << "'\n";

      // TODO(gianluca): separate stack-related operations from graph-related ones
      if (dirName == "..") {
        assert(!stack.empty());
        stack.pop_back();
      } else {
        if (!stack.empty()) {
          g.addNode(dirName, stack);
        } else {
          g.addNode(dirName);
        }

        // cout << "pushing " << dirName << " on the stack\n";
        stack.push_back(dirName);
      }
    } else if (i.starts_with("dir ")) {
      const string dirName = i.substr(strlen("dir "));
      // cout << "dir '" << dirName << "' found" << endl;

      assert(!stack.empty());
    } else if (i == "$ ls") {
      // cout << "about to list content of directory...\n";
    } else {
      auto parts = split(i, " ");
      int size = stoi(parts[0]);
      string fileName = parts[1];

      // cout << "file '" << fileName << "' has size " << size << endl;
      assert(!stack.empty());
      g.addNode(fileName, size, stack);
    }
  }

  // cout << "Graph parsed: \n"
  //      << g << endl;
  return g;
}

}  // namespace day7
}  // namespace ciccarelli
}  // namespace dev
