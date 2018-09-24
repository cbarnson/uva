#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); i++)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

vi D, P;
vector< vector<ii> > g;
int n, m;

void dijk(int s) {
   D.assign(n, -1);

   priority_queue<ii, vector<ii>, greater<ii> > pq;
   pq.emplace(0, s);

   while (!pq.empty()) {
      auto t = pq.top(); pq.pop();
      int u = t.second, d = t.first;
      assert(u >= 0 && u < n);
      if (D[u] != -1) continue;
      D[u] = d;
      for (auto &i : g[u]) {
	 int v = i.second, w = i.first;
	 pq.emplace(d + w, v);
      }
   }
}

void getPath(int i, vi &path) {
   if (P[i] == -1) {
      path.push_back(i);
      return;
   }
   getPath(P[i], path);
   path.push_back(i);
}

void dfs(int u, vi &vis) {
   vis[u] = 1;
   if (u == 0) return;
   for (auto &i : g[u]) {
      int v = i.second, w = i.first;
      if (!vis[v]) {
	 if (D[v] == D[u] + w) continue;
	 dfs(v, vis);
	 P[v] = u;
      }
   }
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> n >> m;
   g.assign(n, vector<ii>());

   int u, v, w;
   FR(i, m) {
      cin >> u >> v >> w;
      g[u].push_back(ii(w, v));
      g[v].push_back(ii(w, u));
   }

   dijk(1);

   P.assign(n, -1);
   vi vis(n, 0);
   dfs(1, vis);
   
   vi pt;
   getPath(0, pt);
   
   if (pt.front() == 1 && pt.back() == 0) {
      cout << pt.size();
      for (int i = pt.size() - 1; i >= 0; i--) cout << " " << pt[i];
      cout << endl;
      return 0;
   }

   cout << "impossible" << endl; 
}
