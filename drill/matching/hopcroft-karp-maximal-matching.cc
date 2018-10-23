// Problem #    : Hopcroft-Karp (maximal matching)
// Created on   : 2018-10-23 13:57:33
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

// https://en.wikipedia.org/wiki/Hopcroft–Karp_algorithm
// time complexity: O(E * sqrt(V))

class MaxMatching {
public:
   static tuple<int, vi> max_matching(const vector<vi> &g) {
      int m = 0, n = g.size();
    
      for (auto &gg : g) for (int u : gg) m = max(m, u + 1);
      vi A(m, -1), D(n), used(n);      

      for (int i = 0, f = 0;; i += f, f = 0) {
      	 vi vis(n); 
      	 bfs(g, used, A, D);
      	 FR(u, n) if (!used[u] && dfs(g, vis, used, A, D, u)) f++;
      	 if (!f) return make_tuple(i, A);
      }
   }

   static void bfs(const vector<vi> &g, vi &used, vi &A, vi &D) {
      int n = g.size(), q = 0;
      fill(begin(D), end(D), -1);
      vi Q(n);
      FR(u, n) if (!used[u]) Q[q++] = u, D[u] = 0;
      FR(i, q) {
	 int u = Q[i];
	 for (int v : g[u]) {
	    int w = A[v];
	    if (w >= 0 && D[w] < 0) D[w] = D[u] + 1, Q[q++] = w;
	 }
      }
   }

   static bool dfs(const vector<vi> &g,
		    vi &vis, vi &used,
		    vi &match, vi &D, int u) {
      vis[u] = 1;
      for (int v : g[u]) {
	 int w = match[v];
	 if (w < 0 || (!vis[w] && D[w] == D[u] + 1 &&
		       dfs(g, vis, used, match, D, w))) {
	    match[v] = u;
	    used[u] = true;
	    return true;
	 }
      }
      return false;
   }
};

int main() {


   // Example, Codeforces 489B
   int n;
   cin >> n;
   vi A(n);
   for (auto &x : A) cin >> x;

   int m;
   cin >> m;
   vi B(m);
   for (auto &x : B) cin >> x;

   vector<vi> g(101, vi());
   for (int i = 0; i < A.size(); i++) {
      for (int j = 0; j < B.size(); j++) {
	 if (abs(B[j] - A[i]) < 2) {
	    g[i].push_back(j + 100);
	 }
      }
   }

   int t;
   tie(t, ignore) = MaxMatching::max_matching(g);
   cout << t << endl;

   // Other sample...
   
   // vector<vi> g(3);
   // g[0].push_back(0);
   // g[0].push_back(1);
   // g[1].push_back(1);
   // g[2].push_back(1);

   // int max_matching_cardinality; vi mapping;
   // tie(max_matching_cardinality, mapping) = MaxMatching::max_matching(g);

   // cout << (2 == max_matching_cardinality) << endl;

   // copy(mapping.begin(), mapping.end(), ostream_iterator<int>(cout, " "));
   // cout << endl;
}

