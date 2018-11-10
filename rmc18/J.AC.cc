#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#if __has_include("default_cf.h")
#include "default_cf.h"
#define DEBUG 1
#endif

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int NN = 1050;
const int CC = 256;

string color_key = "ROYGBIV";
vvi color(NN, vi(NN, -1));  // vals [0..6]
vvii G;

void addEdge(ll u, ll v, ll w) {
  G[u].emplace_back(w, v);
  G[v].emplace_back(w, u);
}

void setColor(ll u, ll v, char c) {
  int i = (int)color_key.find(c);
  assert(i >= 0 && i < 7);
  color[u][v] = color[v][u] = i;
}

// {dist_accum, {color_bitmask, node_id}}
typedef pair<ll, ii> state;

vector<ll> dist(NN, -1);

void dijkstra_init() {
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  pq.emplace(0, 0);
  while (!pq.empty()) {
    ll d, u;
    tie(d, u) = pq.top();
    pq.pop();

    if (dist[u] != -1) continue;
    dist[u] = d;

    for (auto &p : G[u]) {
      ll w = p.first, v = p.second;
      pq.emplace(d + w, v);
    }
  }
}

ll dijkstra(int s = 0) {
  dijkstra_init();

  vvi D(NN, vi(CC, -1));
  priority_queue<state, vector<state>, greater<state>> pq;
  pq.emplace(0, ii(0, s));
  while (!pq.empty()) {
    auto t = pq.top();
    pq.pop();
    ll d = t.first, color_bm = t.second.first, u = t.second.second;

    if (D[u][color_bm] != -1) continue;
    D[u][color_bm] = d;

    for (auto &p : G[u]) {
      ll w = p.first, v = p.second;
      pq.emplace(d + w, ii((color_bm | (1 << color[u][v])), v));
    }
  }

  // look for best
  ll mi = -1;
  FR(i, NN) {
    if (D[i][((1 << 7) - 1)] != -1) {
      ll ans = D[i][((1 << 7) - 1)] + dist[i];
      mi = mi == -1 ? ans : min(mi, ans);
    }
  }
  return mi;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  G.assign(n, vii());
  FR(i, m) {
    ll u, v, w;
    char c;
    cin >> u >> v >> w >> c;
    u--, v--;
    addEdge(u, v, w);
    setColor(u, v, c);
  }

  ll ans = dijkstra(0);
  cout << ans << endl;
}
