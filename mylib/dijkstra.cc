#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

vector< vector<ii> > g;
vi D;
int n;

void dijkstra(int s) {
   D.assign(n, -1);

   priority_queue<ii, vector<ii>, greater<ii> > pq;
   pq.emplace(0, s);

   while (!pq.empty()) {
      int u = pq.top().second, d = pq.top().first; pq.pop();

      if (D[u] != -1) continue;
      D[u] = d;

      for (auto &i : g[u]) {
	 int v = i.second, w = i.first;
	 pq.emplace(d + w, v);
      }
   }
}

int main() {

   cin >> n;
   g.assign(n, vector<ii>());

   // for each edge
   int m = 5;
   FR(i, m) {
      int u, v, w;
      cin >> u >> v >> w;
      g[u].push_back(ii(w, v));
      g[v].push_back(ii(w, u));
   }

   // run dijkstra from some src
   dijkstra(0);

   // path? for every edge from u -> v, if D[v] == D[u] + weight(u, v),
   // then u -> v is an edge in "some" optimal path.
   
}
