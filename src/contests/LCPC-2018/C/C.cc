#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i) 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

vector<vi> g;
vi vis;

void dfs(int u) {
   vis[u] = 1;
   for (auto &v : g[u])
      if (!vis[v]) dfs(v);
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, m;
   cin >> n >> m;

   g.assign(n, vi());
   vis.assign(n, 0);
   FR(i, m) {
      int u, v;
      cin >> u >> v;
      u--; v--;
      g[u].push_back(v);
      g[v].push_back(u);
   }

   int cnt = -1;
   FR(i, n) {
      if (!vis[i]) {
	 cnt++;
	 dfs(i);
      }
   }

   cout << cnt << endl;
   

   

}
