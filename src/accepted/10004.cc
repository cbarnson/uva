#include <bits/stdc++.h>
using namespace std;

int main() {

   int n;
   while (cin >> n && n != 0) {

      int l;
      cin >> l;
      // graph, g[i][j] nonzero is a connection
      int g[200][200]; 
      // color, -1 not assigned, 0 red, 1 blue
      int c[200]; 
      for (int i = 0; i < 200; i++) {
	 c[i] = -1;
	 for (int j = 0; j < 200; j++) {
	    g[i][j] = 0;
	 }
      }

      // read in edges
      for (int i = 0; i < l; i++) {
	 int u, v;
	 cin >> u >> v;
	 g[u][v] = 1;
	 g[v][u] = 1;
      }

      // pick first color
      c[0] = 1;
      
      queue<int> q;      
      q.push(0);
      
      while (!q.empty()) {
	 int u = q.front();
	 q.pop();
	 for (int v = 0; v < n; v++) {
	    if (g[u][v] && (c[v] == -1)) {
	       // assign second color and add vertex to queue
	       c[v] = 1 - c[u];
	       q.push(v);	       
	    } else if (g[u][v] && (c[u] == c[v])) {
	       // matching colors, not bipartite
	       goto end;
	    }
	 }
      }

      cout << "BICOLORABLE." << endl;
      continue;
     end:
      cout << "NOT BICOLORABLE." << endl;
   }
 


   return 0;
}
