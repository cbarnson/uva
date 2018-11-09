// Problem #  : 598A
// Created on : 2018-Nov-09 09:23:03
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#if __has_include("default_cf.h")
#include "default_cf.h"
#endif

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll t, n;
  cin >> t;
  while (t--) {
    cin >> n;

    ll sum = (n * (n + 1)) / 2;
    for (int i = 0; (1 << i) <= n; i++) {
      if (int j = (1 << i); j <= n) sum = sum - j - j;
    }
    cout << sum << endl;
  }
}
