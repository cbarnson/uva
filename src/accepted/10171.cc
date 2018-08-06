// Problem #    : 10171
// Created on   : 2018-08-06 05:29:17

#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (n); ++i)
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (cin >> n && (n)) {
    char ym, ub, x, y;
    int c;

    // Represent each grid location g[i][j], as the pair of costs to move from
    // location 'i' to location 'j', where the first item of the pair is the
    // cost for YOUNG, second is cost for OLD
    int g[26][26][2];
    memset(g, INF, sizeof g);

    REP(i, n) {
      cin >> ym >> ub >> x >> y >> c;
      int u = (int)(x - 'A'), v = (int)(y - 'A');
      g[u][v][ym == 'M'] = c;
      if (ub == 'B')
        g[v][u][ym == 'M'] = c;
    }

    cin >> x >> y;
    int u = (int)(x - 'A'), v = (int)(y - 'A');
    g[u][u][0] = g[v][v][1] = 0;

    // Floyd-Warshall's APSP
    REP(k, 26) {
      REP(i, 26) {
        REP(j, 26) {
          REP(l, 2) { g[i][j][l] = min(g[i][j][l], g[i][k][l] + g[k][j][l]); }
        }
      }
    }

    int best = INF;
    REP(i, 26) { best = min(best, g[u][i][0] + g[v][i][1]); }

    if (best == INF) {
      cout << "You will never meet." << endl;
    } else {

      cout << best;
      REP(i, 26) {
        if (best == g[u][i][0] + g[v][i][1])
          cout << " " << (char)(i + 'A');
      }
      cout << endl;
    }
  }

  return 0;
}
