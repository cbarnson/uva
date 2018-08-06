// Problem #    : 315
// Created on   : 2018-08-05 19:41:50

#include <bits/stdc++.h>

#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
#define FOREACH(i, c)                                                          \
  for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define MP make_pair
#define L first
#define R second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii; // pair of ints
typedef vector<int> vi;    // 1d vector of ints
typedef vector<ii> vii;    // 1d vector of pairs

#define INF 0x3f3f3f3f

int depth, root, children;
vi lo, num, p;
vector<bool> artV;
vector<vi> g;

void Apb(int u) {
  lo[u] = num[u] = depth++; // lo[u] <= num[u]

  FOR(v, (int)g[u].size()) {
    if (!g[u][v])
      continue;

    if (num[v] == -1) {
      p[v] = u;
      if (u == root)
        children++;

      Apb(v);

      // point
      if (lo[v] >= num[u]) {
        artV[u] = true;
      }
      // bridge
      if (lo[v] > num[u]) {
        // bridge from u -> v
      }

      // update
      lo[u] = min(lo[u], lo[v]);
    } else if (v != p[u]) {
      // back edge and not direct cycle
      lo[u] = min(lo[u], num[v]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (cin >> n && (n)) {

    g.assign(n, vi(n, 0));
    int u, v;
    while (cin >> u && (u)) {
      u--;
      string l;
      getline(cin, l);
      stringstream ss(l);
      while (ss >> v) {
        v--;
        g[u][v] = g[v][u] = 1;
      }
    }

    depth = 0;
    num.assign(n, -1);
    lo.assign(n, 0);
    p.assign(n, -1);
    artV.assign(n, false);
    FOR(i, n) {
      if (num[i] == -1) {
        root = i, children = 0;
        Apb(i);
        artV[root] = (children > 1);
      }
    }

    int cnt_p = count(ALL(artV), true);
    cout << cnt_p << "\n";
  }

  return 0;
}
