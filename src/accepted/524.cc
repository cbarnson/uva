// Problem #    : 524
// Created on   : 2018-07-21 14:54:12

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
  for (int i = 0; i < v.size(); i++) {
    if (i) {
      cout << " ";
    }
    cout << v[i];
  }
  os << endl;
}

ll sz;
vi primes;
bitset<10000010> p;

void sieve(ll m) {
  sz = m + 1;
  p.set();
  p[0] = p[1] = 0;
  for (ll i = 2; i <= sz; i++) {
    if (p[i]) {
      for (ll j = i * i; j <= sz; j += i) {
        p[j] = 0;
      }
      primes.push_back(i);
    }
  }
}

bool isPrime(ll x) {
  if (x <= sz)
    return p[x];
  for (int i = 0; i < primes.size(); i++) {
    if (x % primes[i] == 0)
      return false;
  }
  return true;
}

// recursive backtracking
void bt(vi &ans, vb &used, int i, int n) {
  // base
  if (i == n && isPrime(ans[i - 1] + ans[0])) {
    // print soln
    cout << ans;
    return;
  }

  for (int j = 2; j <= n; j++) {
    if (!used[j] && isPrime(ans.back() + j)) {
      // modify state
      used[j] = true;
      ans.push_back(j);
      // backtrack
      bt(ans, used, i + 1, n);
      // undo
      used[j] = false;
      ans.pop_back();
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve(1000000);

  int n, tc = 1;
  while (cin >> n) {

    if (tc > 1)
      cout << endl;

    vb used(n + 1, false);
    used[1] = true;
    vi ans;
    ans.push_back(1);

    cout << "Case " << tc++ << ":" << endl;
    bt(ans, used, 1, n);
  }

  return 0;
}
