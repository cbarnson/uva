#include <bits/stdc++.h>
using namespace std;
#define FR(i, n) for (int i = 0; (i) < (n); ++(i))

const double EPS = 1e-8;

struct pt {
   double x, y;
   bool operator<(const pt& p) const {
      return y < p.y || (y == p.y && x < p.x);
   }
};

pt pstart, pmax;

enum orient { CCW, CW, CNEITHER };

orient ccw(pt a, pt b, pt c) {
   double dx1 = b.x - a.x, dx2 = c.x - b.x,
      dy1 = b.y - a.y, dy2 = c.y - b.y,
      t1 = dy2 * dx1, t2 = dy1 * dx2;

   if (fabs(t1 - t2) < EPS) 
      if (dx1 * dx2 < 0 || dy1 * dy2 < 0) 
	 if (dx1 * dx1 + dy1 * dy1 >= dx2 * dx2 + dy2 * dy2 - EPS) 
	    return CNEITHER;
	 else 
	    return CW;	 
      else
	 return CCW;
   else if (t1 > t2)
      return CCW;
   else return CW;
}

bool ccwCmp(const pt &a, const pt &b) {
   return ccw(pstart, a, b) == CCW;
}

// note: incomplete... note much to be gained from changing the
// version in the code library, is long and ugly, no way around it

int convexHull(vector<pt> &P, vector<pt> &H) {
   sort(begin(P), end(P));

   int n = P.size();
   for (int i = n - 1; i >= 1; i--) {
      if (fabs(P[i].x - P[i - 1].x) < EPS &&
	  fabs(P[i].y - P[i - 1].y) < EPS) {
	 for (int j = i; j < n - 1; j++)
	    P[j] = P[j + 1];
	 n--;
      }
   }

   if (n == 1) {
      H[0] = P[0];
      return 1;
   }

   int bi = max_element(begin(P), begin(P) + n) - begin(P);
   swap(P[0], P[bi]);
   pstart = P[0];

   bi = 1;
   for (int i = 2; i < n; i++) {
      if (ccwCmp(P[bi], P[i]))
	 bi = i;
   }

   pmax = P[bi];

   sort(begin(P) + 1, begin(P) + n, sortCmp);

   // dummy
   return 0;
}

int main() {

}
