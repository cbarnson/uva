#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int dp[110];
int f(int n) {
  if (n < 2) return n;
  if (dp[n]) return dp[n];
  int x = n + f(n - 2);
  return (dp[n] = x);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  cout << f(n) << endl;
}
