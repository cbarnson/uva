#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); i++)
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int src, dest;
int N, M, T, K;

vvii G;            // u --> (w, v)
vi Spiders;        // i to K, ith is node idx of spider
vi NearestSpider;  // i to N, ith is dist to nearest spider

void add_edge(ll u, ll v, ll d) {
  G[u].emplace_back(d, v);
  G[v].emplace_back(d, u);
}

bool dijkstra_path(ll minSpiderDist) {
  vi D(N, -1LL);
  priority_queue<ii, vii, greater<ii>> pq;
  pq.emplace(0LL, src);

  ll u, v, d, w;
  while (!pq.empty()) {
    tie(d, u) = pq.top();
    pq.pop();
    if (D[u] != -1LL) continue;

    // do not update D[u], we can't be here
    ll nearest = NearestSpider[u];
    if (minSpiderDist > nearest) continue;

    D[u] = d;
    for (auto &p : G[u]) {
      tie(w, v) = p;
      pq.emplace(d + w, v);
    }
  }

  // can I get from src --> dest in under T
  return (D[dest] != -1 && D[dest] <= T);
}

void dijkstra_spider() {
  vi D(N, -1LL);
  priority_queue<ii, vii, greater<ii>> pq;
  FR (i, K) { pq.emplace(0LL, Spiders[i]); }

  ll u, v, d, w;
  while (!pq.empty()) {
    tie(d, u) = pq.top();
    pq.pop();
    if (D[u] != -1LL) continue;
    D[u] = d;
    for (auto &p : G[u]) {
      tie(w, v) = p;
      pq.emplace(d + w, v);
    }
  }

  NearestSpider = D;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M >> T;
  G.assign(N, vii());

  // read edges u --> (d, v)
  ll u, v, d;
  FR (i, M) {
    cin >> u >> v >> d;
    add_edge(u, v, d);
  }

  // source, destination, K # of spiders
  cin >> src >> dest >> K;
  FR (i, K) {
    cin >> u;
    Spiders.emplace_back(u);
  }

  // computes, for each node, nearest dist to spider
  dijkstra_spider();

  // binary search on the allowed-distance-to-spider
  // hi : NO I CANNOT DO IT
  // lo : YES I CAN DO IT
  ll lo = 0LL, hi = 1LL;
  while (dijkstra_path(hi)) hi *= 2LL;
  while (hi - lo > 10LL) {
    ll mid = lo + (hi - lo) / 2LL;
    (dijkstra_path(mid) ? lo : hi) = mid;
  }
  while (!dijkstra_path(hi)) hi--;
  cout << hi << endl;
}
