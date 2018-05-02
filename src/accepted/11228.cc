// Cody Barnson
// uva 11228
#include <bits/stdc++.h>
using namespace std;

// Howard's mst.cc
class UnionFind
{
   struct UF { int p; int rank; };

public:
   UnionFind(int n) {          // constructor
      howMany = n;
      uf = new UF[howMany];
      for (int i = 0; i < howMany; i++) {
	 uf[i].p = i;
	 uf[i].rank = 0;
      }
   }

   ~UnionFind() {
      delete[] uf;
   }

   int find(int x) { return find(uf,x); }        // for client use
      
   bool merge(int x, int y) {
      int res1, res2;
      res1 = find(uf, x);
      res2 = find(uf, y);
      if (res1 != res2) {
	 if (uf[res1].rank > uf[res2].rank) {
	    uf[res2].p = res1;
	 }
	 else {
	    uf[res1].p = res2;
	    if (uf[res1].rank == uf[res2].rank) {
	       uf[res2].rank++;
	    }
	 }
	 return true;
      }
      return false;
   }
      
private:
   int howMany;
   UF* uf;

   int find(UF uf[], int x) {             // for internal use
      if (uf[x].p != x) {
	 uf[x].p = find(uf, uf[x].p);
      }
      return uf[x].p;
   }
};

class Edge {

public:
   Edge(int i=-1, int j=-1, double weight=0) {
      v1 = i;
      v2 = j;
      w = weight;
   }
   bool operator<(const Edge& e) const { return w < e.w; }

   int v1, v2;          /* two endpoints of edge                */
   double w;            /* weight, can be double instead of int */
};


void mst(int n, int m, Edge elist[], int index[], int& size, double& road,
	 double& rail, double r, int& states)
{
   UnionFind uf(n);

   sort(elist, elist+m);

   double w = 0.0;
   size = 0;
   for (int i = 0; i < m && size < n-1; i++) {
      int c1 = uf.find(elist[i].v1);
      int c2 = uf.find(elist[i].v2);
      if (c1 != c2) {
	 index[size++] = i;
	 // road or rail
	 if (elist[i].w > r) {
	    rail += elist[i].w;
	    states++;
	 } else
	    road += elist[i].w;
	 uf.merge(c1, c2);
      }
   }

}

int main() {

   int t, cn = 1;
   cin >> t;
   while (t--) {      
      cout << "Case #" << cn++ << ": ";      
      // n vertices, r is the greatest distance between two cities
      // for which they can be considered to be in the same state
      int n, r;
      cin >> n >> r;
      double x[1000];
      double y[1000];
      for (int i = 0; i < n; ++i) 
	 cin >> x[i] >> y[i];      
      // up to n(n-1)/2 edges for n vertices
      // for each edge, compute the euclidean distance between the
      // two vertices and use as the weight for the edge
      // This step is O(n^2)
      Edge elist[499500];
      int k = 0;
      for (int i = 0; i < n; ++i) 
	 for (int j = i+1; j < n; ++j) 
	    elist[k++] = Edge(i, j, hypot(x[i]-x[j], y[i]-y[j]));
      int index[1000];
      int size, states = 1;
      double road = 0.0, rail = 0.0;      
      // compute the minimum spanning tree, using Howard's implementation
      // code for Kruskal's MST, which is O(m log m) for m edges
      mst(n, k, elist, index, size, road, rail, (double)r, states);      
      // want output values for road and rail rounded to nearest integer
      road += 0.5;
      rail += 0.5;
      cout << states << " " << (int)road << " " << (int)rail << endl;
   }
   return 0;
}



