// Problem #    : 796
// Created on   : 2018-08-05 21:18:56

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

int d, r, c;
vi num, lo, p;
vector<vi> g;
vii B; // bridges

// Just for bridges, removed stuff specific to finding points
void apb(int u) {
  lo[u] = num[u] = d++;
  for (auto &v : g[u]) {
    if (num[v] == -1) {
      p[v] = u;
      apb(v);

      if (lo[v] > num[u])
        B.push_back(ii(min(u, v), max(u, v)));

      lo[u] = min(lo[u], lo[v]);
    } else if (v != p[u]) {
      lo[u] = min(lo[u], num[v]);
    }
  }
}

// Articulation points and bridges problem, want to find # of bridges and print
// what the are.
int main() {

  int V;
  while (scanf(" %d", &V) == 1) {
    if (V == 0) {
      printf("0 critical links\n\n");
      continue;
    }

    g.assign(V, vi());

    int u, v, e;
    for (int i = 0; i < V; i++) {
      scanf("%d (%d)", &u, &e);
      FOR(i, e) {
        scanf(" %d", &v);
        g[u].push_back(v);
      }
    }

    // init
    d = 0;
    num.assign(V, -1);
    lo.assign(V, 0);
    p.assign(V, -1);
    B.clear();

    // NOTE: we are skipping some steps here related to gathering the
    // articulation points because we only care about bridges for this problem.
    FOR(i, V) {
      if (num[i] == -1) {
        apb(i);
      }
    }

    printf("%d critical links\n", (int)B.size());
    sort(ALL(B));
    for (auto &i : B)
      printf("%d - %d\n", i.first, i.second);
    printf("\n");
  }

  return 0;
}
