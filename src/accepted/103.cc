// Problem #    : 103
// Created on   : 2018-08-11 02:23:17

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
typedef vector<vii> vvii;  // 2d vector of pairs

int V, k;
vvi g;

// store parent information for each node, allows us to reconstruct the elements
// that compose the LIS
vi p;

// Returns false if ANY element of g[x][i], for i in 0..k-1, is less than or
// equal to the corresponding element of g[y][i].  In other words, true if 1st
// argument is strictly GREATER than 2nd argument
// (i.e. 'y' can 'fit' inside 'x')
bool cmp(int x, int y) {
  for (int i = 0; i < k; i++) {
    if (g[x][i] <= g[y][i])
      return false;
  }
  return true;
}

void path(int i) {
  if (i == p[i]) {
    cout << g[i].back() + 1;
    return;
  }
  path(p[i]);
  cout << " " << g[i].back() + 1;
}

void LIS() {
  vi b(V, 1);
  p.assign(V, 0);
  iota(ALL(p), 0);

  for (int i = 1; i < V; i++) {
    for (int j = 0; j < i; j++) {
      if (cmp(i, j) && b[i] < b[j] + 1) {
        b[i] = b[j] + 1, p[i] = j;
      }
    }
  }

  int mx = 0, idx;
  REP(i, V) {
    if (b[i] > mx) {
      mx = b[i], idx = i;
    }
  }

  cout << mx << "\n";
  path(idx);
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> V >> k) {
    g.assign(V, vi(k));
    REP(i, V) {
      REP(j, k) { cin >> g[i][j]; }
      sort(g[i].begin(), g[i].end());

      // push the identifier onto the back of this array "item", to allow us to
      // trace back through parents and get the correct representative item for
      // output.
      g[i].push_back(i);
    }

    sort(ALL(g), [](const vi &x, const vi &y) {
      return lexicographical_compare(ALL(x), ALL(y));
    });

    LIS();
  }

  return 0;
}
