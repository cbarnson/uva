// Problem #  : 451B
// Created on : 2018-Nov-01 09:49:13
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

void ans(int y, int l, int r) {
  cout << (y ? "yes" : "no") << endl;
  if (y) cout << l << " " << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vi a(n);
  for (auto &x : a) cin >> x;

  if (n == 1 || is_sorted(begin(a), end(a))) {
    ans(1, 1, 1);
    return 0;
  }

  auto it = is_sorted_until(begin(a), end(a), less<int>{});
  auto jt = is_sorted_until(it, end(a), greater<int>{});
  int i = it - begin(a), j = jt - begin(a);

  reverse(--it, jt);
  ans(is_sorted(begin(a), end(a)), i, j);
}
