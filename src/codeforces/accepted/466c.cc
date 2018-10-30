// Problem #    : 466c
// Created on   : 2018-10-28 19:41:27
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<ll> A(n), C(n, 0);
  for (auto &x : A) cin >> x;

  ll s = accumulate(begin(A), end(A), 0LL), t = s / 3, x = 0, ans = 0;
  if (s % 3LL) {
    cout << 0 << endl;
    return 0;
  }

  for (int i = n - 1; i >= 0; i--) {
    x += A[i];
    if (x == t) C[i] = 1;
  }

  for (int i = n - 2; i >= 0; i--) {
    C[i] += C[i + 1];
  }

  x = 0;
  for (int i = 0; i < n - 2; i++) {
    x += A[i];
    if (x == t) ans += C[i + 2];
  }
  cout << ans << endl;
}
