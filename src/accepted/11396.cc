// Problem #    : 11396
// Created on   : 2018-08-05 17:20:53

#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define FOR(i, c)                                                              \
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

vector<vi> g;
int V;

bool isBipartiteUtil(int s, vi &color) {
  queue<int> q;
  q.push(s);
  color[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto &v : g[u]) {

      // if self-edges are possible, and not allowed
      if (u == v)
        return false;
      if (color[v] == -1)
        color[v] = 1 - color[u], q.push(v);
      else if (color[v] == color[u])
        return false;
    }
  }
  return true;
}

// Works for graphs that may not be strongly connected
bool isBipartite() {
  vi color(V, -1);
  for (int i = 0; i < V; i++) {
    if (color[i] == -1 && !isBipartiteUtil(i, color))
      return false;
  }
  return true;
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  while (cin >> V && (V)) {
    g.assign(V, vi());
    int u, v;
    while (cin >> u >> v && (u || v)) {
      u -= 1, v -= 1;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    cout << (isBipartite() ? "YES\n" : "NO\n");
  }

  return 0;
}
