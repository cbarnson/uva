// Problem #  : 822A
// Created on : 2018-Oct-31 17:23:35
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

ll fac(ll n) {
  if (n < 2) return 1LL;
  return n * fac(n - 1LL);
}

ll f[15] = {};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  FR (i, 13)
    f[i] = fac(i);

  ll lo, hi;
  cin >> lo >> hi;
  if (lo > hi) swap(lo, hi);
  hi = min(hi, 12LL);

  cout << __gcd(f[lo], f[hi]) << endl;
}
