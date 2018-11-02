// Problem #    : n_choose_k
// Created on   : 2018-11-01 23:08:55
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
#define PR(a, n)         \
  {                      \
    cout << #a << " = "; \
    FR(i, n)             \
    cout << a[i] << ' '; \
    cout << endl;        \
  }
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

ll choose(ll n, ll k) {
  if (k > n - k) k = n - k;
  ll ans = 1;
  FR(i, k) ans = ans * (n - i) / (i + 1);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // Output:
  // 0 : 1
  // 1 : 1 1
  // 2 : 1 2 1
  // 3 : 1 3 3 1
  // 4 : 1 4 6 4 1
  // 5 : 1 5 10 10 5 1
  // 6 : 1 6 15 20 15 6 1
  // 7 : 1 7 21 35 35 21 7 1
  const int NN = 8;
  for (ll n = 0; n < NN; n++) {
    cout << n << " :";
    for (ll k = 0; k <= n; k++) {
      cout << " " << choose(n, k);
    }
    cout << endl;
  }
}
