// Problem #  : 514B
// Created on : 2018-Nov-09 14:20:52
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#if __has_include("default_cf.h")
#include "default_cf.h"
#endif

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  set<ii> S;
  int n, x, y, xx, yy;
  cin >> n >> x >> y;
  while (n--) {
    cin >> xx >> yy;
    int dx = xx - x, dy = yy - y;
    int g = __gcd(dy, dx);
    S.emplace(dy / g, dx / g);
  }

  cout << S.size() << endl;
}
