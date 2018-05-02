// Cody Barnson
// 674 - coin change
#include <bits/stdc++.h>
using namespace std;

// array of coin values
const int a[] = { 50, 25, 10, 5, 1 };

int main() {

   int n;
   while (cin >> n) {

      // DP table
      int x[7500][5];
      // base case for p=0
      for (int i = 0; i < 5; i++)
	 x[0][i] = 1;
      // base case for p=4 (i.e. 1 cent)
      for (int i = 0; i <= n; i++) 
	 x[i][4] = 1;
      
      // solve table
      for (int i = 0; i <= n; i++) {
	 for (int j = 3; j >= 0; j--) {
	    x[i][j] = x[i][j+1];
	    if (i-a[j] < 0) continue;
	    if (i-a[j] == 0) {
	       x[i][j]++;
	    } else {
	       assert(i-a[j] >= 0);
	       x[i][j] += x[i-a[j]][j];
	    }
	 }
      }

      cout << x[n][0] << endl;
      
   }



   return 0;
}
