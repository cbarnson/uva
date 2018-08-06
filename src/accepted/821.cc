// Problem #    : 821
// Created on   : 2018-08-06 04:01:08

#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define FOR(i, c)                                                              \
  for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())

using namespace std;

typedef long long ll;
typedef pair<int, int> ii; // pair of ints
typedef vector<int> vi;    // 1d vector of ints
typedef vector<ii> vii;    // 1d vector of pairs
typedef vector<vi> vvi;    // 2d vector of ints

#define INF 0x3f3f3f3f
int g[105][105];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int u, v, tc = 1;
  while (cin >> u >> v && (u || v)) {

    REP(i, 101) {
      REP(j, 101) { g[i][j] = INF; }
    }

    do {
      g[u][v] = 1;
    } while (cin >> u >> v && (u || v));

    // Floyd-warshall's APSP, initially g[i][j] is weight of path from i -> j
    // for direct connections given; otherwise INF (0x3f3f3f3f ~ 1 bil).
    // 'g' is represented as an adjacency matrix.  This algorithm is generally
    // useable as long as number of vertices, V <= 400 (approx.)
    REP(k, 101) {
      REP(i, 101) {
        REP(j, 101) { g[i][j] = min(g[i][j], g[i][k] + g[k][j]); }
      }
    }

    int tot = 0, den = 0;
    REP(i, 101) {
      REP(j, 101) {
        if (i != j && g[i][j] != INF)
          tot += g[i][j], den++;
      }
    }

    // don't worry about div by 0, never happen according to problem
    double ans = (double)tot / (double)den;
    cout << "Case " << tc++ << ": ";
    cout << "average length between pages = " << setprecision(3) << fixed << ans
         << " clicks" << endl;
  }

  return 0;
}
