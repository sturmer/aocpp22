#include "graph.hpp"

#include <iostream>
#include <sstream>
#include <vector>

#include "common.hpp"

using namespace std;

namespace dev {
namespace ciccarelli {

void Graph::addNode(const string& n) {
  assert(adjList.empty());
  adjList[n] = {};
  size[n] = 0;
}

void Graph::addNode(const string& n, const vector<string>& stack) {
	const string parent = join(stack, "-");
	const string label = parent + "-" + n;

  assert(adjList.contains(parent));
  adjList[parent].push_back(label);
  adjList[label] = {};
  size[label] = 0;
}

void Graph::addNode(const string& n, const unsigned long long size, const vector<string>& stack) {
	const string parent = join(stack, "-");
	const string label = parent + "-" + n;

  addNode(n, stack);
  this->size[label] = size;
}

void Graph::computeDirSizes() {
  visited = {};

  for (const pair<string, vector<string>>& p : adjList) {
    string node = p.first;
    computeDirSizes(node);
  }
}

unsigned long long Graph::computeDirSizes(const string& node) {
  if (!visited.contains(node)) {
    if (size.at(node)) {
      visited.insert(node);
      return size.at(node);
    }

    unsigned long long sz = 0L;
    vector<string> children = adjList[node];
    for (const string& c : children) {
      sz += computeDirSizes(c);
    }

    size[node] = sz;
    visited.insert(node);
  }

  return size.at(node);
}

}  // namespace ciccarelli
}  // namespace dev
