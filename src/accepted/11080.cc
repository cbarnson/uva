// Problem #    : 11080
// Created on   : 2018-08-05 16:24:57

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int V, E;
    cin >> V >> E;

    // adj list representation of graph
    vector<vi> g(V, vi());

    // 'E' is number of lines representing edges for this case
    REP(i, E) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    vi color(V, -1);
    queue<int> q;

    int ans = 0;

    // not explicitly guaranteed the graph will be connected, so
    // iterate over all vertices, and run BFS for each component (you will know
    // since color[i] will be -1, i.e. not visited).  Each BFS, where the
    // component is bipartite, we need to accumulate the min "number of guards"
    // for printing result later
    REP(i, V) {

      if (color[i] == -1) {
        int cnt_total = 0, cnt_zero = 0;
        q.push(i);
        color[i] = 0;
        bool is_bipartite = true;

        // BFS
        while (!q.empty() && is_bipartite) {
          int u = q.front();
          q.pop();
          cnt_total++;
          if (color[u] == 1)
            cnt_zero++;

          for (auto v : g[u]) {
            if (color[v] == -1) {
              color[v] = 1 - color[u];
              q.push(v);
            } else if (color[v] == color[u]) {
              is_bipartite = false;
              break;
            }
          }
        }

        if (is_bipartite) {
          // ATTN: make sure to handle edge case for there being 1 vertex,
          // since without that conditional, when V = 1, E = 0, min(1 - 1, 1)
          // ==> 0 (wrong)
          ans += (cnt_total == 1) ? 1 : min(cnt_total - cnt_zero, cnt_zero);
        } else {
          cout << -1 << endl;
          goto next;
        }
      }
    }

    cout << ans << endl;

  next:;
  }

  return 0;
}
