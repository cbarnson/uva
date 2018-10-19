// Problem #    : 10389
// Created on   : 2018-10-19 09:14:15
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;

struct pt {
   double x, y;
};

double dist(pt a, pt b) {
   return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int t;
   cin >> t;

   while (t--) {

      pt p[210];
      double g[210][210] = {};
      
      int n = 2;
      cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y >> ws;
      string l;
      while (getline(cin, l) && l != "") {
   	 stringstream ss(l);
   	 ss >> p[n].x >> p[n].y, n++;
   	 while (ss >> p[n].x >> p[n].y) {
   	    if (p[n].x < 0) break;
   	    g[n][n - 1] = dist(p[n], p[n - 1]);
	    g[n - 1][n] = g[n][n - 1];
   	    n++;
   	 }
      }

      FR(i, n) {
   	 FR(j, n) {
   	    if (g[i][j] == 0) 
   	       g[i][j] = dist(p[i], p[j]) * 4; // 4 x as long for walk
   	 }
      }

      FR (k, n) FR(i, n) FR(j, n) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      cout << (int)(g[0][1] * 6 / 4000 + 0.5) << endl;
      
      if (t) cout << endl;
      
   }

}
