// Problem #    : 11504
// Created on   : 2018-08-05 23:41:47

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

int num_scc, depth;
vi num, lo, stk, vis;
vvi g;
vi S;

// Tarjan's SCC
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
    for (;;) {
      int v = stk.back();
      stk.pop_back();
      vis[v] = 0;
      if (u == v)
        break;
    }
    // Store each root node, representative of an SCC; collectively form a DAG,
    // whose topological sort is reflected by the REVERSE order of 'S'.
    S.push_back(u);
  }
}

void dfs(int s, vi &visited) {
  visited[s] = 1;
  for (auto &v : g[s]) {
    if (!visited[v])
      dfs(v, visited);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int V, m;
    cin >> V >> m;
    g.assign(V, vi());

    REP(i, m) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].push_back(v);
    }

    depth = num_scc = 0;
    S.clear();
    num.assign(V, -1);
    lo.assign(V, 0);
    vis.assign(V, 0);
    REP(i, V) {
      if (num[i] == -1) {
        scc(i);
      }
    }

    // Once SCC's have been computed, we need to call DFS on each 'root' stored
    // in S.  Note: 'S' is the topological ordering of the SCC root nodes, which
    // together form a DAG.
    int ans = 0;
    vi visited(V, 0);
    reverse(ALL(S));
    for (auto &i : S) {
      // each item of 'S' that we do not need to DFS on, is one less from
      // num_scc, originally computed by our SCC algorithm
      if (!visited[i]) {
        dfs(i, visited);
        ans++;
      }
    }
    cout << ans << endl;
  }

  return 0;
}
