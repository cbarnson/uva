// Problem #  : 363B
// Created on : 2018-Nov-01 12:27:40
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  vi h(n);
  FR (i, n)
    cin >> h[i];

  vi ps(n + 1, 0);
  partial_sum(begin(h), end(h), begin(ps) + 1);

  auto sum = [&](int l, int r) {
    assert(l >= 0 && l <= r);
    return ps[r] - ps[l];
  };

  int mi = ~(1 << 31), ans = -1;
  for (int i = k; i <= n; i++) {
    int p = sum(i - k, i);
    if (mi > p) {
      ans = i - k + 1;
      mi = p;
    }
  }
  cout << ans << endl;
}
