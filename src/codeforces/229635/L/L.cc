#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  vi A(n);
  for (auto &x : A)
    cin >> x;

  int ans = -1;
  for (auto &x : A) {
    if (k % x == 0) {
      int s = k / x;
      ans = (ans == -1 ? s : min(ans, s));
    }
  }
  cout << ans << endl;
}
