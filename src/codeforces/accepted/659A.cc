// Problem #  : 659A
// Created on : 2018-Nov-09 10:53:18
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#if __has_include("default_cf.h")
#include "default_cf.h"
#endif

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int next(int i, int j, int k) { return ((i - 1) + j) % k + 1; }
int prev(int i, int j, int k) { return ((i - 1) + k - j) % k + 1; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, a, b;
  cin >> n >> a >> b;

  FR(i, abs(b)) { a = (b < 0 ? prev(a, 1, n) : next(a, 1, n)); }
  cout << a << endl;
}
