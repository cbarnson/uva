// Problem #    : dijkstra-empty
// Created on   : 2018-10-19 08:10:59
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

// u -> w, v
vector< vector<ii> > g;

// distance
vi D;

// nodes, edges
int n, m;

void dijkstra(int s) {
   
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> n >> m;

   g.assign(n, vector<ii>(n));
   FR(i, m) {
      int u, v, w;
      cin >> u >> v >> w;
      g[u].emplace_back(w, v);
      g[v].emplace_back(w, u);
   }

   // source, usually 0
   int src = 0;
   dijkstra(src);


}
