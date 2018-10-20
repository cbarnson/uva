#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i) 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> ii;

vector< vector<ii> > g;
int n, m, k;

ll dijk(int s, int dest) {
   vector<ll> D(n, -1);
   priority_queue<ii, vector<ii>, greater<ii> > pq;
   pq.emplace(0, s);

   while (!pq.empty()) {
      ll u = pq.top().second, d = pq.top().first;
      pq.pop();
      if (D[u] != -1) continue;
      D[u] = d;
      for (auto &i : g[u]) {
	 ll v = i.second, w = i.first;
	 pq.emplace(d + w, v);
      }
   }
   return D[dest];
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> n >> m >> k;
   g.assign(n, vector<ii>());
   FR(i, m) {
      ll u, v, w;
      cin >> u >> v >> w;
      u--; v--;
      g[u].push_back(ii(w, v));
      g[v].push_back(ii(w, u));      
   }

   vi K(k);
   for (auto &x : K) cin >> x;
   
   
   ll s = 0, sum = 0;
   for (int i = 0; i < k; i++) {
      sum += dijk(s, K[i]-1);
      s = K[i]-1;
   }
   cout << k + sum << endl;
   

}
