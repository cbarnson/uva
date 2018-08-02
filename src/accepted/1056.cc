// Problem #    : 1056
// Created on   : 2018-08-02 01:26:28

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

#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define FOR(i, c)                                                              \
  for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()

template <typename T> void printList(initializer_list<T> l) {
  for (const auto &i : l)
    cout << i << ' ';
  cout << endl;
}

// variadic function
int sum() { return 0; }
template <typename T, typename... Args> T sum(T a, Args... args) {
  return a + sum(args...);
}

typedef long long ll;
typedef pair<int, int> ii; // pair of ints
typedef vector<int> vi;    // 1d vector of ints
typedef vector<ii> vii;    // 1d vector of pairs
typedef vector<vi> vvi;    // 2d vector of ints
typedef vector<vii> vvii;  // 2d vector of pairs
typedef vector<bool> vb;   // 1d vector of bools

#define INF 0x3f3f3f3f

// Warshall's O(V^3) algorithm, being used to find diameter of a graph,
// which is the maximum, shortest path between any two vertices
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, tc = 1;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) {
      break;
    }

    map<string, int> mp;
    vector<string> names;

    vvi g(n, vi(n, INF));
    REP(i, m) {
      string s[2];
      REP(j, 2) {
        cin >> s[j];
        if (mp.count(s[j]) == 0) {
          mp[s[j]] = (int)names.size();
          names.push_back(s[j]);
        }
      }
      g[mp[s[0]]][mp[s[1]]] = g[mp[s[1]]][mp[s[0]]] = 1;
    }

    REP(k, n) {
      REP(i, n) {
        REP(j, n) {
          if (g[i][j] > g[i][k] + g[k][j]) {
            g[i][j] = g[i][k] + g[k][j];
          }
        }
      }
    }

    int mx = 0;
    cout << "Network " << tc++ << ": ";
    REP(i, n) {
      REP(j, n) {
        if (i == j)
          continue;
        if (g[i][j] == INF) {
          cout << "DISCONNECTED" << endl;
          goto next;
        } else if (g[i][j] > mx) {
          mx = g[i][j];
        }
      }
    }
    cout << mx << endl;

  next:
    cout << endl;
  }

  return 0;
}
