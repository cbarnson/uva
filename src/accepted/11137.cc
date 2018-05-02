#include <bits/stdc++.h>
using namespace std;

int main() {

   // coins, the values
   int c[21];
   for (int i = 0; i < 21; i++) {
      int v = i+1;
      c[i] = v*v*v;
   }

   uint64_t ways[21][10000];
   for (int i = 0; i < 21; i++) {
      ways[i][0] = 1;
   }
   for (int i = 0; i < 10000; i++) {
      ways[0][i] = 1;
   }

   for (int i = 1; i < 21; i++) {
      for (int j = 1; j < 10000; j++) {
	 uint64_t tempways = 0;
	 if ((j-c[i]) >= 0)
	    tempways = ways[i][j-c[i]];
	 ways[i][j] = tempways + ways[i-1][j];
      }
   }

   int n;
   while (cin >> n) {

      assert(n >= 0 && n < 10000);
      cout << ways[20][n] << endl;

   }

   
   


   return 0;
}
