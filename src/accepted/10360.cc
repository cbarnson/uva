// Problem #    : 10360
// Created on   : 2018-08-10 20:25:58

#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, c)                                                              \
  for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define SZ(x) ((int)((x).size()))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii; // pair of ints
typedef vector<int> vi;    // 1d vector of ints
typedef vector<ii> vii;    // 1d vector of pairs
typedef vector<vi> vvi;    // 2d vector of ints

int k[1030][1030];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, d, n;
  cin >> t;
  while (t--) {
    cin >> d >> n;
    memset(k, 0, sizeof k);
    while (n--) {
      int x, y, p;
      cin >> x >> y >> p;

      // Optimization here (rather than i = 0..1024, j = 0..1024) allows our
      // solution to be fast enough, otherwise is time limit!
      for (int i = max(0, x - d); i < min(1025, x + d + 1); i++) {
        for (int j = max(0, y - d); j < min(1025, y + d + 1); j++) {
          k[i][j] += p;
        }
      }
    }

    int x = 0, y = 0;
    REP(i, 1025) {
      REP(j, 1025) {
        if (k[i][j] > k[x][y]) {
          x = i, y = j;
        }
      }
    }

    cout << x << " " << y << " " << k[x][y] << "\n";
  }

  return 0;
}
