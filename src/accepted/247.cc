// Problem #    : 247
// Created on   : 2018-08-02 00:21:06

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

    vvi mat(n, vi(n, 0));
    string s[2];
    REP(i, m) {
      REP(j, 2) {
        cin >> s[j];
        if (mp.count(s[j]) == 0) {
          mp.insert(make_pair(s[j], (int)names.size()));
          names.push_back(s[j]);
        }
      }
      int u = mp[s[0]], v = mp[s[1]];
      mat[u][v] = 1;
    }

    // Warshall's transitive closure, O(V^3)
    REP(k, n) {
      REP(i, n) {
        REP(j, n) { mat[i][j] |= (mat[i][k] & mat[k][j]); }
      }
    }

    if (tc > 1) {
      cout << endl;
    }
    cout << "Calling circles for data set " << tc++ << ":" << endl;

    if (m == 0) {
      continue;
    }
    vb seen(n, false);
    REP(i, n) {
      if (!seen[i]) {
        seen[i] = true;
        cout << names[i];
        REP(j, n) {
          // SCC check
          if (i != j && mat[i][j] && mat[j][i] && !seen[j]) {
            cout << ", " << names[j];
            seen[j] = true;
          }
        }
        cout << endl;
      }
    }
  }
  return 0;
}
