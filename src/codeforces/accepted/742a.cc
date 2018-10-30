// Problem #    : 742a
// Created on   : 2018-10-29 14:47:39
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int modexp(int x, int n, int m) {
  if (n == 0) return 1;
  if (n & 1) return ((x % m) * modexp(x, n - 1, m)) % m;
  int y = modexp(x, n / 2, m);
  return (y * y) % m;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  cout << modexp(1378, n, 10) << endl;
}
