// Problem #    : 1112
// Created on   : 2018-06-18 00:38:35

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

ostream &operator<<(ostream &os, ii &p) {
  os << "(" << p.first << ", " << p.second << ")\n";
}

ostream &operator<<(ostream &os, vi &v) {
  for (auto &i : v)
    os << i << " ";
  os << endl;
}
ostream &operator<<(ostream &os, vector<char> &v) {
  for (auto &i : v)
    os << i << " ";
  os << endl;
}
#define INF 0x3f3f3f3f
vvii g;
vi dist, parent;

void dij(int s) {
  dist.clear();
  parent.clear();
  dist.assign((int)g.size(), INF);
  parent.assign((int)g.size(), -1);
  dist[s] = 0;
  set<ii> dv;
  dv.insert(ii(0, s));

  while (!dv.empty()) {
    ii t = *(dv.begin());
    dv.erase(dv.begin());
    int u = t.second;
    for (auto &i : g[u]) {
      int v = i.second;
      int w = i.first;
      if (dist[v] > dist[u] + w) {
        if (dist[v] != INF)
          dv.erase(dv.find(ii(dist[v], v)));

        dist[v] = dist[u] + w;
        dv.insert(ii(dist[v], v));
        parent[v] = u;
      }
    }
  }
}

void path(int i) {
  if (parent[i] == -1) {
    cout << i;
    return;
  }
  path(parent[i]);
  cout << " " << i;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, tc = 1;
  cin >> t;
  while (t--) {
    int n, e, max_dist, m;
    cin >> n >> e >> max_dist >> m;
    e--;
    g.clear();
    g.resize(n);
    for (auto &i : g)
      i.reserve(n);
    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      u--, v--;
      // going backwards
      swap(u, v);
      g[u].push_back(ii(w, v));
    }

    dij(e);
    int x = 0;
    for (int i = 0; i < n; i++) {
      if (dist[i] <= max_dist)
        x++;
    }

    if (tc > 1)
      cout << endl;
    tc++;
    cout << x << endl;
  }

  return 0;
}
