// Problem #    : 412
// Created on   : 2018-07-30 18:05:19

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

// specific to 412
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

ii c(int n, int k, vi &v) {

  // trick for enumerating all combinations "n choose k" using next_permutation
  // note: if k > n, c(n, k) = 0
  vi b(k, 1);
  b.resize(n, 0);

  // specific to 412
  int cnt = 0;
  int total = 0;

  do {
    int x = -1, y = -1;
    for (int i = 0; i < n; i++) {
      // if b[i] is set, the ith index is "selected" for this loop
      if (b[i]) {
        // specific to 412, only considering k = 2
        if (x == -1) {
          x = v[i];
        } else {
          y = v[i];
          break;
        }
      }
    }

    // specific to 412
    if (x == 1 || y == 1 || gcd(x, y) == 1) {
      cnt++;
    }
    total++;

  } while (next_permutation(b.rbegin(), b.rend()));

  return ii(cnt, total);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  while (cin >> n && n > 0) {
    vi v;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v.push_back(x);
    }

    ii ans = c(n, 2, v);
    if (ans.first == 0) {
      cout << "No estimate for this data set." << endl;
    } else {
      double f = (double)6.0 * (double)ans.second / (double)ans.first;
      cout << setprecision(6) << fixed << sqrt(f) << endl;
    }
  }

  return 0;
}
