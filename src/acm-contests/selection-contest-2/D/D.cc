#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

vi C;

vector<vi> g;

void dfs(int s, int e) {
   C[s] = 1;
   for (auto &v : g[s]) {
      if (v != e) {
	 dfs(v, s);
	 C[s] += C[v];
      }
   }
}


int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   cin >> n;

   g.assign(n, vi());
   C.assign(n, 0);
   for (int i = 0; i < (n - 1); i++) {
      int u, v;
      cin >> u >> v;
      u--; v--;
      g[u].push_back(v);
      g[v].push_back(u);
   }

   if (n & 1) {
      cout << -1 << endl;
      return 0;
   }

   dfs(0, 0);

   int cnt = 0;
   for (int i = 1; i < n; i++) {
      if (C[i] % 2 == 0) {
	 cnt++;
      }
   }

   cout << cnt << endl;
}
