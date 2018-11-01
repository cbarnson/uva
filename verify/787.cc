// Problem #    : 787
// Created on   : 2018-11-01 01:13:55
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  while (getline(cin, s)) {
    stringstream ss(s);
    vi a;
    int x;
    while (ss >> x && x != -999999) a.emplace_back(x);
    int n = a.size();
    int mx = a[0];
    FR (i, n) {
      int s;
      for (int j = i; j < n; j++) {
        s = j == i ? a[j] : s * a[j];
      }
      mx = max(mx, s);
    }
    cout << mx << endl;
  }
}
