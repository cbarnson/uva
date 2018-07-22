// Problem #    : 11000
// Created on   : 2018-07-21 16:11:19

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

typedef vector<int> vi; // 1d vector of ints
typedef long long ll;
typedef pair<ll, ll> ii; // pair of ints

ostream &operator<<(ostream &os, vi &v) {
  for (auto &i : v)
    os << i << " ";
  os << endl;
}

// dynamic programming problem, use memoization
// to compute values and remember as necessary.
// Guaranteed result will fit into 2^32, use long long
// to be certain
ii dp[1000]{ii(0, 0)};

ii gen(int n) {
  if (n < 2) {
    return (dp[n] = ii((n == 0) ? 0 : 1, 1));
  }

  if (dp[n] != ii(0, 0)) {
    return dp[n];
  }

  ii ans = gen(n - 1);
  dp[n] = ii(ans.first + ans.second, ans.first + 1);

  return dp[n];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (cin >> n) {
    if (n < 0) {
      break;
    }
    ii ans = gen(n);
    ll total = ans.first + ans.second;
    cout << ans.first << " " << total << endl;
  }

  return 0;
}
