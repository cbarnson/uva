// Problem #  : 701A
// Created on : 2018-Nov-01 10:37:01
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
  vi a(n);
  FR (i, n)
    cin >> a[i];

  // value we need per player
  int x = accumulate(begin(a), end(a), 0) * 2 / (n);
  vi used(n, 0);
  FR (i, n / 2) {
    FR (k, n) {
      if (!used[k]) {
        for (int j = k + 1; j < n; j++) {
          if (!used[j] && a[k] + a[j] == x) {
            cout << k + 1 << " " << j + 1 << endl;
            used[k] = used[j] = 1;
            break;
          }
        }
      }
    }
  }
}
