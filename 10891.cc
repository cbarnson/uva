#include <bits/stdc++.h>
using namespace std;
#define FR(i, n) for (int i = 0; i < (n); ++i)

typedef vector<int> vi;
typedef pair<int, int> ii;

vi A;
int vis[101][101];
int dp[101][101];

int f(int l, int r) {

  if (r < l) return 0;
  if (vis[l][r]) return dp[l][r];

  vis[l][r] = 1;
  dp[l][r] = -0x3f3f3f3f;

  int s = 0;
  for (int i = l; i <= r; i++) {
    s += A[i];
    dp[l][r] = max(dp[l][r], s - f(i + 1, r));
  }

  s = 0;
  for (int i = r; i >= l; i--) {
    s += A[i];
    dp[l][r] = max(dp[l][r], s - f(l, i - 1));
  }

  return dp[l][r];
}


int main() {


  int n;
  while (cin >> n && n) {
    A.assign(n, 0);
    for (auto &x : A) cin >> x;

    FR(i, 101) FR(j, 101) dp[i][j] = 0, vis[i][j] = 0;
    
    int x = f(0, A.size() - 1);
    cout << x << endl;
  }
}
