// Rocky 2015 - Bundles of Joy
// not correct...
#include <bits/stdc++.h>
using namespace std;

const int N = 101;
int p[N];
int b[N];
int n, m;

int main() {

   int tc;
   cin >> tc;
   while (tc--) {

      fill(p, p+N, 10e7);
      fill(b, b+N, -1);
      
      cin >> n >> m;
      for (int i = 1; i <= m; i++) {
	 int pi, si, x;
	 cin >> pi >> si >> x;
	 if (pi < p[x]) {
	    // update
	    p[x] = pi;
	    b[x] = i;
	    for (int j = 1; j < si; j++) {
	       cin >> x;
	       p[x] = pi;
	       b[x] = i;
	    }
	 } else {
	    // don't update, must already exist
	    for (int j = 1; j < si; j++) {
	       cin >> x;
	    }	    
	 }	 
      }

      bool seen[N];
      fill(seen, seen+N, false);

      int sum = 0;
      for (int i = 1; i <= n; i++) {
	 if (!seen[i]) {
	    sum += p[i];
	    seen[i] = true;
	    // mark all items with that bundle number
	    int bund = b[i];
	    for (int j = i; j <= n; j++) {
	       if (b[j] == bund)
		  seen[j] = true;
	    }
	 }
      }

      cout << sum << endl;




   }



   return 0;
}
