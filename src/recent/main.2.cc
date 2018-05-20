// Problem #    :
// Title        :
// Accepted     : No
// Date         : 20180502

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef vector<vector<int>> vec2d;
typedef vector<int> vi;
typedef pair<int, int> ii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

template <typename T>
void printInitList(initializer_list<T> l) {
  for (const auto &i : l) cout << i << ' ';
  cout << endl;
}

// variadic function
// int sum() { return 0; }
// template<typename T, typename... Args>
// T sum(T a, Args... args) { return a + sum(args...); }

// Number of vertices in our graph
int V = 100;

// Adjacency list representation of our directed graph
vector<vector<int>> graph(V);

void dfsUtil(int s, vector<bool> &visited) {
  // mark this node, s, as visited
  visited[s] = true;

  // iterate over each outgoing edge (in the adjacency list) reachable from s
  for (int i = 0; i < graph[s].size(); i++) {
    // recursively call dfsUtil for each node that has NOT been visited already
    if (!visited[i]) {
      // do something
      dfsUtil(graph[s][i], visited);
    }
  }
}

void dfs(int s) {
  // initialize an array to track which nodes have been visited (prevents
  // cycles)
  vector<bool> visited(V, false);

  // use our dfsUtil helper function to recurse in a depth-first search
  dfsUtil(s, visited);
}

int main() {
  int n;
  cin >> n;
  cout << n;

  return 0;
}
