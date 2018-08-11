// Problem #    : 11747
// Created on   : 2018-08-10 23:17:35

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

class UF {

public:
  // parent 'p', rank 'r'
  vi p, r;
  UF(int n) {
    p.assign(n, 0);
    iota(p.begin(), p.end(), 0);
    r.assign(n, 0);
  }

  int find(int i) { return (p[i] == i) ? i : (p[i] = find(p[i])); }

  bool same(int i, int j) { return find(i) == find(j); }

  void merge(int i, int j) {
    if (!same(i, j)) {
      int x = find(i), y = find(j);
      if (r[x] > r[y]) {
        p[y] = x;
      } else {
        p[x] = y;
        if (r[x] == r[y])
          r[y]++;
      }
    }
  }
};

// Kruskal's MST algorithm using UnionFind
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int V, E;
  while (cin >> V >> E && (V || E)) {

    // Create Edgelist
    vector<pair<ll, ii>> el;
    REP(i, E) {
      int u, v;

      // weight can be large, so use long long
      ll w;
      cin >> u >> v >> w;
      el.push_back(make_pair(w, ii(u, v)));
    }

    // important step to sort here..
    sort(ALL(el));

    UF uf(V);
    ll cost = 0;

    // Every edge that is in the MST, is not in our output, and vice versa; keep
    // a count of the weights printed in 'c'.
    int c = 0;

    // Kruskal's MST
    for (int i = 0; i < E; i++) {
      int u = el[i].second.first, v = el[i].second.second;
      ll w = el[i].first;
      if (!uf.same(u, v))
        uf.merge(u, v), cost += w;
      else
        cout << (c++ ? " " : "") << w;
    }

    // Output 'forest' if no edges are not in the MST.
    cout << (c ? "\n" : "forest\n");
  }

  return 0;
}
