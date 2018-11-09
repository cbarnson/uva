// Problem #  : 527A
// Created on : 2018-Nov-09 09:16:00
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

  ll a, b;
  cin >> a >> b;

  ll cnt = 0;
  do {
    if (a > b) swap(a, b);
    cnt += b / a;
    b %= a;
  } while (b != 0);

  cout << cnt << endl;
}
