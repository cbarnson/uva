#include <bits/stdc++.h>
using namespace std;

int main() {
  
   int n;
   cin >> n;
  
   while (n--) {
      bool arr[101][25001];
      int val[100];
      int m;
      cin >> m;
      for (int i = 0; i < m; i++) {
	 cin >> val[i];
      }
      int full = accumulate(val, val+m, 0);
      bool even = full % 2 == 0;
      int half = full / 2;

      // base case values
      for (int i = 0; i <= m; i++) {
	 arr[i][0] = true;
      }
      for (int i = 1; i <= half; i++) {
	 arr[0][i] = false;
      }

      // fill table
      for (int i = 1; i <= m; i++) {
	 for (int j = 1; j <= half; j++) {

	    // f(a,k) = f(a - val[k-1], k-1) || f(a, k-1)
	    bool second = arr[i-1][j];

	    int v = j - val[i-1];
	    bool first;
	    if (v < 0) {
	       first = false;
	    } else {
	       first = arr[i-1][v];
	    }
	    arr[i][j] = first || second;
	    
	 }
      }
  

      int diff = 1;
      if (even) diff = 0;

      for (int i = half; i >= 0; i--) {
	 if (arr[m][i]) break;
	 diff += 2;
      }

      cout << diff << endl;
   }


}
