// Problem #    : 10449
// Created on   : 2018-08-01 01:28:46

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

typedef long long ll;
typedef pair<int, int> ii; // pair of ints
typedef vector<int> vi;    // 1d vector of ints
typedef vector<ii> vii;    // 1d vector of pairs
typedef vector<vi> vvi;    // 2d vector of ints
typedef vector<vii> vvii;  // 2d vector of pairs
typedef vector<bool> vb;   // 1d vector of bools

ostream &operator<<(ostream &os, vi &v) {
  for (auto &i : v)
    os << i << " ";
  os << endl;
}
// #define forab(i, a, b)        for (__typeof (b) i = (a) ; i <= b ; ++i)
// #define rep(i, n)                forab (i, 0, (n) - 1)
// #define For(i, n)                forab (i, 1, n)
// #define rofba(i, a, b)        for (__typeof (b)i = (b) ; i >= a ; --i)
// #define per(i, n)                rofba (i, 0, (n) - 1)
// #define rof(i, n)                rofba (i, 1, n)
// #define forstl(i, s)        for (__typeof ((s).end ()) i = (s).begin (); i !=
// (s).end (); ++i)
#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define FOR(i, c)                                                              \
  for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()

#define INF 0x3f3f3f3f

ll cube(ll x) { return x * x * x; }

void bellmanFord(int n) {
  vi busy(n);
  vi dist(n, INF);
  for (int i = 0; i < n; i++) {
    cin >> busy[i];
  }

  int m;
  cin >> m;

  vector<tuple<int, int, int>> edges(m);

  int u, v, w;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    w = cube(busy[--v] - busy[--u]);
    edges.push_back(make_tuple(u, v, w));
  }

  // handle case when n = 0 && r == 0 && q == 0 gracefully
  if (n > 0) {
    dist[0] = 0;
  }
  for (int k = 0; k < n; k++) {
    for (auto &t : edges) {
      tie(u, v, w) = t;
      if (dist[v] > dist[u] + w && dist[u] != INF) {
        dist[v] = dist[u] + w;
        if (k == n - 1) {
          dist[v] = -INF;
        }
      }
    }
  }

  int q;
  cin >> q;
  while (q--) {
    cin >> v;
    v--;

    if (dist[v] < 3 || dist[v] == INF) {
      cout << "?" << endl;
    } else {
      cout << dist[v] << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, tc = 1;
  while (cin >> n) {
    cout << "Set #" << tc++ << endl;
    bellmanFord(n);
  }

  return 0;
}
