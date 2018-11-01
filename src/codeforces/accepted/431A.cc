// Problem #  : 431A
// Created on : 2018-Nov-01 10:58:20
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  vi a(5);
  FR (i, 4)
    cin >> a[i + 1];
  string s;
  cin >> s;

  cout << accumulate(begin(s), end(s), 0LL, [&](ll x, char c) {
    return x + a[(int)(c - '0')];
  }) << endl;
}
