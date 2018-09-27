#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int NN = 200001;

int C[NN], D[NN], K[NN];
vector<vi> g;

int centroid(int s, int k) {
   int u = s, e = s;
   while (1) {
      int x = k - C[u], y = -1, yv = -1;
      for (auto &v : g[u])
	 if (v != e && C[v] >= y)
	    y = C[v], yv = v;
      if (max(x, y) <= k/2) break;
      e = u, u = yv;
   }
   return u;
}

void dfs(int u, int e) {
   C[u] = K[u];
   D[u] = D[e] + (u != e);
   for (auto &v : g[u])
      if (v != e) 
	 dfs(v, u), C[u] += C[v];      
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, k, u, v;
   cin >> n >> k;

   FR(i, 2*k) {
      int x; cin >> x; K[x-1] = 1;
   }

   g.assign(n, vi());
   FR(i, n-1) {
      cin >> u >> v; u--, v--;
      g[u].push_back(v); g[v].push_back(u);
   }

   dfs(0, 0);
   int c = centroid(0, 2*k);
   cout << "c " << c << endl;
   
   fill_n(C, n, 0);
   fill_n(D, n, 0);
   dfs(c, c);

   FR(i, n) {
      cout << D[i] << "-";
   }
   cout << endl;

   FR(i, n) {
      cout << C[i] << "-";
   }
   cout << endl;

   int s = 0;
   FR(i, n) s += (K[i] ? D[i] : 0);
   cout << s << endl;    
}

