#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); i++)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

vi D, P;
vector< vector<ii> > g;
int n, m;

set<ii> ban;
void dijk(int s) {
   D.assign(n, -1);
   P.assign(n, -1);

   priority_queue<ii, vector<ii>, greater<ii> > pq;
   D[s] = 0;
   pq.emplace(D[s], s);

   while (!pq.empty()) {
      auto t = pq.top(); pq.pop();
      int u = t.second;
      for (auto &i : g[u]) {
	 int v = i.second, w = i.first;
	 if (ban.count(ii(u, v)) != 0) continue;
	 if (D[v] == -1 || D[v] > D[u] + w) {
	    D[v] = D[u] + w;
	    P[v] = u;
	    pq.emplace(D[v], v);
	 }
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
   FR(i, n) {
      if (P[i] != -1) {
	 ban.insert(ii(i, P[i]));
      }
   }

   vi pt;
   dijk(0);
   getPath(1, pt);

   if (pt.front() == 0 && pt.back() == 1) {
      cout << pt.size();
      for (auto &i : pt) {
	 cout << " " << i;
      }
      cout << endl;
      return 0;
   }

   cout << "impossible" << endl; 
}
   
