// Problem #    : 11463
// Created on   : 2018-08-06 06:55:22

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

#define INF 0x3f3f3f3f

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, t, tc = 1;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    int g[101][101];
    memset(g, INF, sizeof g);

    REP(i, m) {
      int u, v;
      cin >> u >> v;
      g[u][v] = g[v][u] = 1;
    }

    int s, d;
    cin >> s >> d;

    if (n < 2) {
      cout << "Case " << tc++ << ": " << 0 << endl;
      continue;
    }

    // Floyd-Warshall
    REP(k, 101) {
      REP(i, 101) {
        REP(j, 101) { g[i][j] = min(g[i][j], g[i][k] + g[k][j]); }
      }
    }

    int si = -1;
    REP(i, n) {
      if (i != s && i != d) {
        si = max(si, g[s][i] + g[i][d]);
      }
    }

    si = max(si, g[s][d]);
    cout << "Case " << tc++ << ": " << si << endl;
  }

  return 0;
}
