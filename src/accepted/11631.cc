// Problem #    : 11631
// Created on   : 2018-08-06 17:47:00

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

// priority_queue is a max-heap by default, but often we want the smallest item
// at the top, rather than the largest.  If so, note the following syntax to
// define our priority_queue.
priority_queue<ii, vector<ii>, greater<ii>> pq;
vi vis;
vector<vii> g;

// Helper function for processing a node 'u', marking it as visited, then taking
// all direct neighbors of 'u', which have not been visited, and pushing them
// into the priority_queue.  When doing Prim's, we would need this logic in two
// places (note: pqUtil(0) for first, then each after mst += ...), so it makes
// sense to put this logic into its own function
void pqUtil(int u) {
  vis[u] = 1;
  for (auto &t : g[u]) {
    int v = t.second, w = t.first;
    if (!vis[v]) {
      pq.push(t);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int V, E;
  while (cin >> V >> E && (V || E)) {

    g.assign(V, vii());

    int u, v, w, tot = 0;
    REP(i, E) {
      cin >> u >> v >> w;
      g[u].push_back(ii(w, v));
      g[v].push_back(ii(w, u));
      tot += w;
    }

    // Prim's MST, O(V log E)
    pq.empty();
    vis.assign(V, 0);
    int mst = 0;
    pqUtil(0);

    while (!pq.empty()) {
      auto t = pq.top();
      pq.pop();
      if (!vis[t.second])
        mst += t.first, pqUtil(t.second);
    }
    cout << tot - mst << endl;
  }

  return 0;
}
