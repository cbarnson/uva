// Problem #    : 318
// Created on   : 2018-08-10 22:22:01

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

#define INF 0x3f3f3f3f

// First, use dijkstra to find the times for the key dominos, as per the problem
// statement, then we will use these values to find out when each edge's last
// domino fell, and take the maximum time between edges and nodes.
int V, E;
vvii g;
vi D;
void dijkstra(int s) {
  D.assign(V, INF);
  D[s] = 0;
  priority_queue<ii> pq; // (weight, node)
  pq.push(ii(D[s], s));

  while (!pq.empty()) {
    auto time = pq.top();
    pq.pop();
    int u = time.second;
    for (auto &i : g[u]) {
      int v = i.second, w = i.first;
      if (D[v] > D[u] + w) {
        D[v] = D[u] + w;
        pq.push(ii(D[v], v));
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tc = 1;
  while (cin >> V >> E && (V || E)) {

    vector<pair<int, ii>> edgelist;
    g.assign(V, vii());
    int u, v, w;
    REP(i, E) {
      cin >> u >> v >> w;
      u--, v--;
      g[u].push_back(ii(w, v));
      g[v].push_back(ii(w, u));
      edgelist.push_back(make_pair(w, ii(u, v)));
    }

    dijkstra(0);
    double latest = 0;
    int x = -1, y = -1;
    REP(i, V) {
      if (D[i] > latest)
        latest = D[i], x = i;
    }

    for (auto &e : edgelist) {
      int w = e.first, u = e.second.first, v = e.second.second;
      int hi = max(D[u], D[v]);
      double time = (double)hi + (double)(w - abs(D[u] - D[v])) / 2;
      if (time > latest)
        latest = time, x = u, y = v;
    }

    cout << "System #" << tc++ << "\nThe last domino falls after "
         << setprecision(1) << fixed << latest << " seconds,";
    if (y == -1) {
      cout << " at key domino " << (x == -1 ? 1 : x + 1) << ".\n\n";
    } else {

      cout << " between key dominoes " << min(x, y) + 1 << " and "
           << max(x, y) + 1 << ".\n\n";
    }
  }

  return 0;
}
