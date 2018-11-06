// Problem #  : 118B
// Created on : 2018-Nov-05 20:31:29
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
#define FF(i, begin, end)                             \
  for (__typeof(end) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  int w = 2 * n + 1;
  int sp = 2 * n;

  for (int i = 0, di = 1; i <= n && i >= 0; i += di) {
    int sz = 2 * i + 1;
    cout << string(((w + sp) - (2 * sz - 1)) / 2, ' ');
    for (int j = 0, dj = 1; j <= i && j >= 0; j += dj) {
      cout << (j == 0 && dj == 1 ? "" : " ") << j;
      if (j == i) dj = -1;
    }
    cout << endl;
    if (i == n) di = -1;
  }
}
