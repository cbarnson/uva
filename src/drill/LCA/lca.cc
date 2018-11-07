#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int maxlog;

vvi g;
vvi P;
vi parent, h;

void pre(int n) {
   for (int i = 0; i < n; i++)
      P[0][i] = parent[i];

   for (int i = 1; (1 << i) <= n; i++) {
      for (int j = 0; j < n; j++) {
	 if (P[i-1][j] != -1)
	    P[i][j] = P[i-1][P[i-1][j]];
      }
   }

   for (int i = 0; i < maxlog; i++) {
      for (int j = 0; j < n; j++) {
	 cout << setw(5) << P[i][j];
      }
      cout << endl << endl;
   }
} 


int lca(int u, int v) {
   if (h[u] < h[v]) swap(u, v); // u has greater height
   int d = h[u] - h[v];
   while (d > 0) {
      int r = 31 - __builtin_clz(d);
      assert(r >= 0);
      u = P[r][u];
      d -= (1 << r);
   }
   if (u == v) return u;
   for (int i = maxlog - 1; i >= 0; i--) 
      if (P[i][u] != -1 && P[i][v] != P[i][u])
	 u = P[i][u], v = P[i][v];
   return parent[u];
}

void dfs(int s, int height) {
   h[s] = height;
   for (auto &v : g[s]) 
      if (h[v] == -1)
	 dfs(v, height + 1);   
}

int main() {

   int n, m, u, v;
   cin >> n >> m;

   g.assign(n, vi());
   parent.assign(n, -1);
   h.assign(n, -1);

   maxlog = 31 - __builtin_clz(n) + 1;
   P.assign(maxlog, vi(n, -1));
   
   for (int i = 0; i < m; i++) {
      cin >> u >> v;
      g[u].push_back(v);
      parent[v] = u;
   }

   dfs(0, 0);

   cout << "height:" << endl;
   for (auto &i : h) 
      cout << setw(5) << i;
   cout << endl << endl;
   
   
   pre(n);

   for (int i = 0; i < n; i++) 
      for (int j = 0; j < n; j++) 
	 if (i != j)
	    cout << "lca(" << i << ", "
		 << j << ") : " << lca(i, j) << endl;
      
   
   
}
