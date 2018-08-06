// Problem #    : 10765
// Created on   : 2018-08-05 22:15:24

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

// doesn't matter the value, just different
#define UNVISITED -1

int depth, root, children;
vi lo, num, parent;
vi art_points;
vector<vi> g;

void APB(int u) {
  lo[u] = num[u] = depth++; // lo[u] <= num[u]
  for (auto &v : g[u]) {
    if (num[v] == UNVISITED) {
      parent[v] = u;
      if (u == root)
        children++;
      APB(v);

      if (lo[v] >= num[u]) {
        // NOTE: since we want to rank our articulation points, for this
        // problem, by the resulting number of components (relative to original
        // graph) that each articulation point's removal causes, INCREMENT
        // rather than just setting true.  Everything else is the same
        art_points[u]++;
      }

      lo[u] = min(lo[u], lo[v]);

    } else if (v != parent[u]) {
      lo[u] = min(lo[u], num[v]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int V, m;
  while (cin >> V >> m && (V || m)) {

    g.assign(V, vi());
    int u, v;
    while (cin >> u >> v) {
      if (u == -1 && v == -1)
        break;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    depth = 0;
    num.assign(V, UNVISITED);
    lo.assign(V, 0);
    parent.assign(V, -1);
    art_points.assign(V, 0);
    REP(i, V) {
      if (num[i] == UNVISITED) {
        root = i, children = 0;
        APB(i);
        art_points[root] = (children > 1);
      }
    }

    // From this point, the work of our APB algorithm is over, now we just need
    // to implement the custom sort, and take the top 'm' results.
    // Note: the 'score' for each articulation point is 1 + the value stored in
    // art_points
    vii ans;
    REP(i, V) { ans.push_back(ii(i, art_points[i] + 1)); }

    // Given pairs of the form pair<int, int>, wish to sort by descending second
    // item, ascending first item
    sort(ALL(ans), [](const ii &x, const ii &y) {
      return (x.second > y.second ||
              (x.second == y.second && x.first < y.first));
    });

    REP(i, m) { cout << ans[i].first << " " << ans[i].second << endl; }
    cout << endl;
  }

  return 0;
}
