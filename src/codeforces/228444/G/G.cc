#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int a[101];

int main() {
   
   int n;
   cin >> n;

   vi e, o, eo, ee; // even, odd, empty odd, empty even

   
   for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[x-1] = true;
   }

   for (int i = 0; i < n; i++) {
      if (i & 1) {
	 if (a[i])
	    o.push_back(i);
	 else
	    eo.push_back(i);
      } else {
	 if (a[i])
	    e.push_back(i);
	 else
	    ee.push_back(i);
      }
   }


   int x = 0, y = 0;
   for (int i = 0; i < o.size(); i++) {
      x += abs(o[i] - ee[i]);
   }

   for (int j = 0; j < e.size(); j++) {
      y += abs(e[j] - eo[j]);
   }
   
   cout << min(x, y) << endl;

}


