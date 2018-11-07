// Problem #    : next_permutation
// Created on   : 2018-11-01 22:58:03
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
#define PR(a, n)         \
  {                      \
    cout << #a << " = "; \
    FR(i, n)             \
    cout << a[i] << ' '; \
    cout << endl;        \
  }
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

// Finds next lexicographically greater perm of binary digits of x, that is:
// next_perm(x) simply returns the smallest integer greater than x which has the
// same nubmer of 1 bits (i.e. same popcount) as x.
// e.g.
// next_perm(10101 base 2) =  10110
// next_perm(11100 base 2) = 100011
//
// Can use to generate combinations by letting k = popcount(x), then use this to
// generate all possible bitmasks to choose k items from the n total items
// (represented by first n bits of x).
ll next_perm(ll x) {
  ll s = x & -x, r = x + s;
  return r | (((x ^ r) >> 2) / s);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n = 5, k = 2;
  vi a(k, 1);
  a.resize(n);
  sort(begin(a), end(a));
  do {
    PR(a, n);
  } while (next_permutation(begin(a), end(a)));
  return 0;

  // ll x = (1 << 3) - 1;
  // ll y = x;
  // int m = 10;
  // FR(i, m) {
  //   cout << bitset<8>(y) << endl;
  //   y = next_perm(y);
  // }

  return 0;
}
