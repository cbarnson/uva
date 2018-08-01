// Problem #    : 371
// Created on   : 2018-07-31 22:13:06

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

const int MM = 1000000;
ll dp[MM] = {0};
// map<ll, ll> dp;

ll f(ll n) {
  // assert(n >= 1 && n <= 1000000);
  // if (n < 1 || n > MM) {
  //   cout << n << endl;
  // }

  // cout << "n: " << n << endl;
  if (n == 2) {
    // return (dp[n] = 1);
    return 1;
  }

  if (n < MM && dp[n] > 0) {
    return dp[n];
  }

  ll ans = (n & 1) ? f(3 * n + 1) + 1 : f(n / 2) + 1;
  if (n < MM) {
    dp[n] = ans;
  }
  return ans;

  // if (dp[n]) {
  //   return dp[n];
  // }

  // if (n & 1) {

  //   dp.insert(make_pair(n, f(3 * n + 1) + 1));
  //   // dp[n] = f(3 * n + 1) + 1;
  //   return dp[n];

  //   // return (dp[n] = f(3 * n + 1) + 1);
  // }

  // // dp[n] = f(n / 2) + 1;
  // dp.insert(make_pair(n, f(n / 2) + 1));
  // return dp[n];
  // return (dp[n] = f(n / 2) + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // for (int i = 1; i <= 10; i++) {
  //   printf("%d: %d\n", i, (int)f(i));
  // }
  // fill(dp, dp + MM, 0);

  ll n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) {
      break;
    }

    if (n > m) {
      swap(n, m);
    }

    ll ans = -1;
    ll k = -1;
    for (ll i = n; i <= m; i++) {
      ll j = f(i);
      if (j > ans) {
        ans = j;
        k = i;
      }
    }

    cout << "Between " << n << " and " << m << ", " << k
         << " generates the longest sequence of " << ans << " values." << endl;
  }

  return 0;
}
