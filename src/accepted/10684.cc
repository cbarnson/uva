// Cody Barnson
// 10684 - the jackpot
#include <bits/stdc++.h>
using namespace std;

int main() {

   int n;
   while (cin >> n && n != 0) {

      int a[10000];
      for (int i = 0; i < n; i++) {
	 cin >> a[i];
      }

      // m stores the value of the largest consecutive subarray
      int m = a[0];
      int c = m;

      for (int i = 1; i < n; i++) {
	 c = max(a[i], c+a[i]); // update temporary
	 m = max(m, c);         // update max
      }
      
      // print solution
      if (m > 0)
	 cout << "The maximum winning streak is " << m << "." << endl;
      else
	 cout << "Losing streak." << endl;
      
   }



   return 0;
}
