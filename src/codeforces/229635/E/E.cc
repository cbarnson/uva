#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int t, n, k;
  cin >> t;
  FR(T, t) {
    cin >> n >> k;
    vi A(k);
    FR(i, k) {
      cin >> A[i];
      A[i]--;
    }
    int ans = max(A.front() + 1, n - A.back());
    for (int i = 1; i < k; i++) {
      int s = A[i] - A[i - 1] - 1;
      int x = (s + 1) / 2;
      ans = max(ans, x + 1);
    }
    cout << ans << endl;
  }
}
