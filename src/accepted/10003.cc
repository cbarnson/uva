// Problem #    : 10003
// Created on   : 2018-10-31 21:27:25
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int dp[55][55];
int cuts[55];

int cost(int i, int j) { return cuts[j] - cuts[i]; }

// f(i, j) is the min cut cost for length from cuts[i] to cuts[j]
int f(int i, int j) {
  if (j - i <= 1) return 0;
  int &x = dp[i][j];
  if (x != -1) return x;

  for (int k = i + 1; k < j; k++) {
    int y = f(i, k) + f(k, j) + cost(i, j);
    x = x == -1 ? y : min(x, y);
  }
  return x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int l;
  while (cin >> l && l) {
    FR (i, 55)
      FR (j, 55)
        dp[i][j] = -1;

    int n;
    cin >> n;

    cuts[0] = 0, cuts[n + 1] = l;
    FR (i, n)
      cin >> cuts[i + 1];

    int ans = f(0, n + 1);
    cout << "The minimum cutting is " << ans << "." << endl;
  }
}
