#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

bool good(int hi, int mid, int lo, vi &fmsa) {
  int A[3] = {hi, mid, lo};
  if (2 * fmsa[3] >= mid || 2 * fmsa[3] >= hi) return false;
  FR(i, 3) {
    if (A[i] >= fmsa[i] && A[i] <= 2 * fmsa[i] && A[i] >= fmsa[3] &&
        A[2] <= 2 * fmsa[3])
      continue;
    return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vi A(4);
  for (auto &x : A) cin >> x;

  const int MM = 200;
  for (int lo = 1; lo < MM; lo++) {
    for (int mid = lo + 1; mid < MM; mid++) {
      for (int hi = mid + 1; hi < MM; hi++) {
        if (good(hi, mid, lo, A)) {
          cout << hi << endl << mid << endl << lo << endl;
          return 0;
        }
      }
    }
  }
  cout << -1 << endl;
}
