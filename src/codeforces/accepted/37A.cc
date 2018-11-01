// Problem #  : 37A
// Created on : 2018-Nov-01 14:21:23
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

  int a[1010] = {};
  int cnt = 0, mx = 0;
  FR (i, n) {
    int x;
    cin >> x;
    if (a[x]++ == 0) cnt++;
    mx = max(mx, a[x]);
  }
  cout << mx << " " << cnt;
}
