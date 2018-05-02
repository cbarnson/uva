// UVA 10940 Throwing cards away II
// Accepted
#include <bits/stdc++.h>
using namespace std;

// where k = 2
int survivor(int n) {
   int p = 1;
   while (p <= n)
      p *= 2;
   int ans = (2*n) - p;
   return (ans == 0) ? n : (2*n) - p;
}

int main() {

   int n;
   while (cin >> n) {

      if (!n)
	 break;
      cout << survivor(n) << endl;
   }
      

   return 0;
}
