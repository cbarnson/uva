// Problem #    : A
// Created on   : 2018-10-01 14:16:41
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

// Prime factorization, n >= 0
// Complexity: O(log(n))
vi factor(int n) {
  vi f;
  if (n < 2) return vi();  // vi(1, n), if want 'n' for n < 2
  while (~n & 1) n >>= 1, f.push_back(2);
  for (ll p = 3; p * p <= n; p += 2)
    while (n % p == 0) n /= p, f.push_back((int)p);
  if (n > 1) f.push_back(n);
  return f;
}

int main() {
  int n;

  while (cin >> n && n) {
    int m = n * (n < 0 ? -1 : 1);
    vi f = factor(m);
    cout << n << " =";
    if (n < 0) cout << " -1";

    FR(i, f.size()) {
      if (i == 0 && n < 0)
        cout << " x " << f[i];
      else if (i == 0)
        cout << " " << f[i];
      else
        cout << " x " << f[i];
    }
    cout << endl;
  }
}
