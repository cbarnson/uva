// Cody Barnson
// 116 - unidirectional tsp
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pp;

const int MAX = 2000000000;

int main() {

   int m, n;
   while (cin >> m >> n) {

      pp x[10][100];
      int a[10][100];

      for (int i = 0; i < m; i++) {
	 for (int j = 0; j < n; j++) {
	    cin >> a[i][j];
	 }
      }

      // setup, working backwards
      int j = n-1;
      for (int i = 0; i < m; i++) {
	 x[i][j] = make_pair(a[i][j], -1);
      }

      for (j = n-2; j >= 0; j--) {
	 for (int i = 0; i < m; i++) {
	    int p, q, r; // row indexes of moves
	    p = q = r = i;
	    p--; if (p < 0) p = m-1;
	    r = (r+1) % m;
	    int mini = p;
	    int minval = x[p][j+1].first;
	    // want min (index and the value)
	    if (x[q][j+1].first < minval) {
	       mini = q;
	       minval = x[q][j+1].first;
	    } else if (x[q][j+1].first == minval) {
               // tiebreaking condition
	       if (q < mini) {
		  mini = q;
		  minval = x[q][j+1].first;
	       }
	    }
	    // do same for r
	    if (x[r][j+1].first < minval) {
	       mini = r;
	       minval = x[r][j+1].first;
	    } else if (x[r][j+1].first == minval) {
               // tiebreaking condition
	       if (r < mini) {
		  mini = r;
		  minval = x[r][j+1].first;
	       }
	    }
	    // mini and minval hold what we wanted
	    x[i][j] = make_pair(minval + a[i][j], mini);	    
	 }
      }

      // print solution
      int mini;
      int min = MAX; // start high
      for (int i = 0; i < m; i++) {
	 // don't worry about tiebreaker because we move
	 // from 0 to m-1
	 if (x[i][0].first < min) {
	    min = x[i][0].first;
	    mini = i;
	 }
      }

      int i = mini;
      for (int j = 0; j < n; j++) {
	 cout << i+1;
	 i = x[i][j].second;
	 if (i >= 0) cout << " ";
      }
      cout << endl << min << endl;


   }

   return 0;
}
