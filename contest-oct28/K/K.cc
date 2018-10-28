#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

vector<vi> g;
vector<vi> g2;

void dfs(int s, vi &vis) {
   vis[s] = 1;
   for (auto &v : g[s]) {
      if (!vis[v]) {
	 dfs(v, vis);
      }
   }
}

void dfs2(int s, vi &vis) {
   vis[s] = 1;
   for (auto &v : g2[s]) {
      if (!vis[v]) {
	 dfs2(v, vis);
      }
   }
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(0);

   int n;
   cin >> n;

   int x, y;
   cin >> x >> y;

   g.assign(n, vi());

   // same as g, but add extra edge down one ways
   g2.assign(n, vi());
   
   // two way
   FR(i, x) {
      int u, v;
      cin >> u >> v; u--; v--;
      g[u].push_back(v);
      g[v].push_back(u);

      g2[u].push_back(v);
      g2[v].push_back(u);
   }

   // one way
   FR(i, y) {
      int u, v;
      cin >> u >> v; u--; v--;
      g[u].push_back(v);

      g2[u].push_back(v);
      g2[v].push_back(u);
   }

   vi vis1(n, 0);
   vi vis2(n, 0);

   int src = 0;

   dfs(src, vis1);
   dfs2(src, vis2);

   FR(i, n) {
      if (!vis2[i]) {
	 cout << "Impossible" << endl;
      } else if (!vis1[i]) {
	 cout << "Ticket" << endl;
      } else {
	 cout << "No Ticket" << endl;
      }
   }
}
