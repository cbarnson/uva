// Problem #  : 913A
// Created on : 2018-Nov-08 14:56:43
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

  ll n, m, k;
  cin >> n >> m;

  for (k = 1; k <= m && n; k *= 2) {
    n--;
  }

  if (n) {
    cout << m << endl;
    return 0;
  }

  cout << m % k << endl;
}
