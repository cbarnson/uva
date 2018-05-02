// Cody Barnson
// 10656 - maximum sum (II)
#include <bits/stdc++.h>
using namespace std;

int main() {
   // n values included in each test case, n of 0 ends the input
   int n;
   bool first = true;
   while (cin >> n && n > 0) {
      if (!first) cout << endl;
      // all values are non-negative, so everything that is not 0
      // is included in the output, UNLESS input is made up of
      // entirely 0's, in which case we print a single 0
      int count = 0;
      for (int i = 0; i < n; i++) {
	 int val;
	 cin >> val;
	 if (val > 0) {
	    if (count++)
	       cout << " ";
	    cout << val;
	 }
      }
      // special case: all values were 0
      if (count == 0)
	 cout << "0";
      // newlines as per output specifications
      first = false;      
   }
   cout << endl;

   return 0;
}
