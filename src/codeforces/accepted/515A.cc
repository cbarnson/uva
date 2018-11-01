// Problem #  : 515A
// Created on : 2018-Nov-01 10:47:04
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll a, b, s;
  cin >> a >> b >> s;

  auto ans = [](bool p) { cout << (p ? "Yes" : "No") << endl; };

  ll x = abs(a) + abs(b);
  if (x > s) {
    ans(false);
  } else {
    ans((s - x) % 2 == 0);
  }
}
