// Problem #    : 558
// Created on   : 2018-08-01 00:57:09

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
#define INF 0x3f3f3f3f

bool BF(int n, int m) {
  vvii g(n);
  vi dist(n, INF);

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back(ii(w, v));
  }

  int s = 0;
  dist[s] = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int u = 0; u < n; u++) {
      for (auto &t : g[u]) {
        int v = t.second, w = t.first;
        dist[v] = min(dist[v], dist[u] + w);
      }
    }
  }

  for (int u = 0; u < n; u++) {
    for (auto &t : g[u]) {
      int v = t.second, w = t.first;
      if (dist[v] > dist[u] + w) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    if (BF(n, m)) {
      cout << "not possible";
    } else {
      cout << "possible";
    }
    cout << endl;
  }

  return 0;
}
