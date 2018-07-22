// Problem #    : bfs
// Created on   : 2018-07-21 14:25:56

#include <algorithm>
#include <assert.h>
#include <bitset>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> ii; // pair of ints
typedef vector<int> vi;    // 1d vector of ints
typedef vector<ii> vii;    // 1d vector of pairs
typedef vector<vi> vvi;    // 2d vector of ints
typedef vector<vii> vvii;  // 2d vector of pairs
typedef vector<bool> vb;   // 1d vector of bools
typedef long long ll;

ostream &operator<<(ostream &os, vi &v) {
  for (auto &i : v)
    os << i << " ";
  os << endl;
}

#define INF -1

vvi g;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // 'n' nodes, 'm' edges
  int n, m;
  while (cin >> n >> m) {
    g.resize(n);
    for (auto &i : g) {
      i.reserve(n);
    }

    // read 'm' directed edges
    int u, v;
    for (int i = 0; i < m; i++) {
      cin >> u >> v;
      g[u].push_back(v);
    }

    // 'distance' vector for each node, initially INF
    vi d(n, INF);

    int src = 0;
    d[src] = 0;
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      // for each neighbor 'v' of 'u', if INF (i.e. unseen), set to
      // d[u] + 1 (since step size is always 1 here) and push onto queue
      for (auto &v : g[u]) {
        if (d[v] == INF) {
          d[v] = d[u] + 1;
          q.push(v);
        }
      }
    }
  }

  return 0;
}
