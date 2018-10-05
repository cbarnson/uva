#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<ii> A(n);
  FR(i, n) {
    cin >> A[i].first;
    A[i].second = i;
  }

  sort(begin(A), end(A));
  int mi = A[0].first;
  int ans = -1;
  for (int i = 1; i < n; i++) {
    if (A[i].first == mi) {
      int x = A[i].second - A[i - 1].second;
      ans = ans == -1 ? x : min(ans, x);
    } else
      break;
  }
  cout << ans << endl;
}
