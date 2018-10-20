#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;

vi S(3005, 0), C(3005, 0);

int main() {
  int n;
  cin >> n;
  FR(i, n) cin >> S[i];
  FR(i, n) cin >> C[i];

  ll bj = -1;
  for (int j = 1; j < n - 1; j++) {
    ll bi = -1, bk = -1;
    for (int i = 0; i < j; i++) {
      if (S[i] < S[j]) {
        bi = bi == -1 ? C[i] : min(bi, C[i]);
      }
    }
    if (bi == -1) continue;
    for (int k = j + 1; k < n; k++) {
      if (S[j] < S[k]) {
        bk = bk == -1 ? C[k] : min(bk, C[k]);
      }
    }
    if (bk == -1) continue;
    bj = bj == -1 ? bi + C[j] + bk : min(bj, bi + C[j] + bk);
  }

  cout << bj << endl;
}