// Problem #    : 368b
// Created on   : 2018-10-29 15:07:35
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int vis[100050] = {};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vi A(n), B(m), C(n, 0);
  FR(i, n) cin >> A[i];
  FR(i, m) cin >> B[i];

  for (int i = n - 1; i >= 0; i--) {
    int x = A[i];
    C[i] = !vis[x] + (i == n - 1 ? 0 : C[i + 1]);
    vis[x] = 1;
  }

  FR(i, m) {
    int x = B[i];
    x--;
    cout << C[x] << endl;
  }
}
