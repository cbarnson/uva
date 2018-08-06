// Problem #    : 11838
// Created on   : 2018-08-06 03:31:02

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

// Normal SCC (Tarjan's) to determine if the input graph is a single, strongly
// connected component.
vi lo, num, stk, vis;
int depth, num_scc;
vvi g;
void scc(int u) {
  lo[u] = num[u] = depth++;
  vis[u] = 1;
  stk.push_back(u);
  for (auto &v : g[u]) {
    if (num[v] == -1)
      scc(v);
    if (vis[v])
      lo[u] = min(lo[u], lo[v]);
  }

  if (lo[u] == num[u]) {
    num_scc++;
    for (;;) {
      int v = stk.back();
      stk.pop_back();
      vis[v] = 0;
      if (u == v)
        break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  while (cin >> n >> m && (n || m)) {
    g.assign(n, vi());
    REP(i, m) {
      int u, v, p;
      cin >> u >> v >> p;
      u--, v--;
      g[u].push_back(v);
      if (p == 2)
        g[v].push_back(u);
    }

    depth = num_scc = 0;
    num.assign(n, -1);
    lo.assign(n, 0);
    stk.clear();
    vis.assign(n, 0);
    REP(i, n) {
      if (num[i] == -1) {
        scc(i);
      }
    }

    // If there is only 1 SCC, correct -> print 1; 0 otherwise
    cout << (num_scc == 1 ? 1 : 0) << endl;
  }

  return 0;
}
