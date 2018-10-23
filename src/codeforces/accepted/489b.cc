// Problem #    : 489b
// Created on   : 2018-10-23 10:23:47
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

class MaxMatching {
public:
   static tuple<int, vector<int>> max_matching(
      const vector<vector<int>> &graph) {
      int n2 = 0;
      for (auto &u1 : graph)
	 for (int u2 : u1) n2 = max(n2, u2 + 1);
      vector<int> mapping(n2, -1);
      size_t n1 = graph.size();
      vector<int> dist(n1);
      vector<bool> used(n1);
      for (int res = 0;;) {
	 bfs(graph, used, mapping, dist);
	 vector<bool> vis(n1);
	 int f = 0;
	 for (int u = 0; u < n1; ++u)
	    if (!used[u] && dfs(graph, vis, used, mapping, dist, u)) ++f;
	 if (f == 0) return make_tuple(res, mapping);
	 res += f;
      }
   }

private:
   static void bfs(const vector<vector<int>> &graph, vector<bool> &used,
		   vector<int> &mapping, vector<int> &dist) {
      fill(dist.begin(), dist.end(), -1);
      size_t n1 = graph.size();
      vector<int> Q(n1);
      int sizeQ = 0;
      for (int u = 0; u < n1; ++u) {
	 if (!used[u]) {
	    Q[sizeQ++] = u;
	    dist[u] = 0;
	 }
      }
      for (int i = 0; i < sizeQ; i++) {
	 int u1 = Q[i];
	 for (int v : graph[u1]) {
	    int u2 = mapping[v];
	    if (u2 >= 0 && dist[u2] < 0) {
	       dist[u2] = dist[u1] + 1;
	       Q[sizeQ++] = u2;
	    }
	 }
      }
   }

   static bool dfs(const vector<vector<int>> &graph, vector<bool> &vis,
		   vector<bool> &used, vector<int> &matching, vector<int> &dist,
		   int u1) {
      vis[u1] = true;
      for (int v : graph[u1]) {
	 int u2 = matching[v];
	 if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 &&
	     dfs(graph, vis, used, matching, dist, u2)) {
	    matching[v] = u1;
	    used[u1] = true;
	    return true;
	 }
      }
      return false;
   }
};

int main() {


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

   // Note: if don't want the mapping, just do tie(mx, ignore) = ... (ignore is keyword)

   // int max_matching_cardinality; vi mapping;
   // tie(max_matching_cardinality, mapping) = MaxMatching::max_matching(g);
   // cout << (2 == max_matching_cardinality) << endl;
   // copy(mapping.begin(), mapping.end(), ostream_iterator<int>(cout, " "));
   // cout << endl;
}
