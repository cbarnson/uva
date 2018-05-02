#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cassert>
#include <algorithm>
using namespace std;

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


double mst(int n, int m, Edge elist[], int index[], int& size)
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
	 w += elist[i].w;
	 uf.merge(c1, c2);
      }
   }

   return w;
}

int main(void)
{






   // cout << fixed << setprecision(2);




   int n, m;
   cin >> n >> m;


   // read m triples
   Edge* elist = new Edge[n*n];
   for (int i = 0; i < m; i++) {
   	int x, y;
   	double w;
   	cin >> x >> y >> w;
   	elist[i] = Edge(x, y, w);
   }


   // for (int i = 0; i < m; i++)  cin >> x[i] >> y[i];
   
   
  //  int k = 0;
  //  for (int i = 0; i < n; i++) 
  //     for (int j = i+1; j < n; j++) 
	 // elist[k++] = Edge(i,j,hypot(x[i]-x[j], y[i]-y[j]) );
   int* index = new int[n];
   
   int t;  // number of edges in the mst
   	cout << mst(n, m, elist, index, t) << endl;

   	cout << "t is " << t << endl;

   	int sum = 0;
	for (int i = 0; i < m; i++) {
		sum += elist[index[i]].w;
	}
	cout << sum << endl;

   return 0;
}
