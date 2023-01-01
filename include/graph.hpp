#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace dev {
namespace ciccarelli {

using namespace std;

struct Graph {
  unordered_map<string, vector<string>> adjList;
  unordered_map<string, unsigned long long> size;
  unordered_set<string> visited;

  bool contains(const string& k) {
    return adjList.contains(k);
  }

  void addNode(const string& n);
  void addNode(const string& n, const vector<string>& stack);
  void addNode(const string& n, const unsigned long long size, const vector<string>& stack);

  friend ostream& operator<<(ostream& os, const Graph& g) {
    for (const pair<string, vector<string>>& p : g.adjList) {
      os << "  " << p.first << "(" << g.size.at(p.first) << "): ";
      for (const auto& n : p.second) {
        os << " " << n;
      }
      os << endl;
    }

    return os;
  }

  void computeDirSizes();
  unsigned long long computeDirSizes(const string& node);
};

}  // namespace ciccarelli
}  // namespace dev
#endif  // GRAPH_HPP
