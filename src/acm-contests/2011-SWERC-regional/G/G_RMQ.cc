#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;

const int MM = 1000001;

// smaller dimension 1st
int M[(31 - __builtin_clz(MM * 2) + 1)][MM * 2];
int P[MM * 2];

void init(int n) {

  REP(i, n) M[0][i] = i;

  for (int i = 1; (1 << i) <= n; i++) {
    for (int j = 0; (j + (1 << i)) <= n; j++) {
      M[i][j] = (P[M[i - 1][j]] < P[M[i - 1][j + (1 << (i - 1))]])
	? M[i - 1][j]
	: M[i - 1][j + (1 << (i - 1))];
    }
  }
}

int query(int L, int R) {
  int k = 31 - __builtin_clz(R - L + 1);
  return (P[M[k][L]] < P[M[k][R - (1 << k) + 1]])
    ? M[k][L]
    : M[k][R - (1 << k) + 1];
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
   
  int n;
  while (scanf(" %d", &n) == 1 && n) {

    // Don't need to keep originals, so doing some on the fly partial
    // sum calc for 2*n.
    REP(i, n) {
      scanf(" %d", &P[i]);
      P[i + n] = P[i];
      if (i) P[i] += P[i - 1];
    }

    // process other half of partial sum array
    REP(i, n) P[i + n] = P[i + n] + P[i + n - 1];
    init(2 * n);

    int cnt = 0;
    REP(i, n) {
      if ((P[query(i, i + n - 1)] - (i ? P[i - 1] : 0)) < 0) cnt++;
    }

    printf("%d\n", n - cnt);
  }
}
