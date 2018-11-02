// Problem #    : 530
// Created on   : 2018-06-10 14:33:28

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll C(int n, int k) {
  if (k == 0 || k == n) return 1;
  double ans = 1;
  k = min(k, n - k);
  for (ll i = 1; i <= k; i++) {
    ans = ans * (n - k + i) / i;
  }
  return (ll)(ans + 0.01);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  while (cin >> n >> k && (n || k)) {
    cout << C(n, k) << endl;
  }

  return 0;
}
