#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

vi C, K;
vector<vi> g;

void dfs(int u, int e) {
   C[u] = K[u];
   for (auto &v : g[u])
      if (v != e) 
	 dfs(v, u), C[u] += C[v];      
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, k, u, v;
   cin >> n >> k;

   g.assign(n, vi());
   C.assign(n, 0);
   K.assign(n, 0);

   FR(i, 2*k) { cin >> u; u--, K[u] = 1; }
   FR(i, n-1) {
     cin >> u >> v; u--, v--;
     g[u].push_back(v); g[v].push_back(u);
   }

   // get subtree sizes
   dfs(0, 0);

   // edge counted as many times as there are connections
   // betw node in subtree and some node not in subtree
   ll s = 0;
   FR(i, n) {
     s += min(C[i], 2*k - C[i]);
   }
   cout << s << endl;
}


