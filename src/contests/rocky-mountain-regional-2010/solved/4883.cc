// Cody Barnson
// 4883 - ropes
#include <bits/stdc++.h>
using namespace std;

int rope[3] = { 50, 60, 70 };

int main() {

   int n;
   while (cin >> n && n != 0) {

      // read in values, track sum and maximum seen
      int sum = 0;
      int hi = -1;
      for (int i = 0; i < n; i++) {
	 int val;
	 cin >> val;
	 sum += val;
	 hi = max(hi, val);
      }

      // output for each of the 3 rope lengths
      for (int i = 0; i < 3; i++) {
	 if (rope[i] < (sum * 2)) 
	    cout << 0;
	 else 
	    cout << (rope[i] / hi) + 1;	 
	 if (i != 2)
	    cout << " ";
      }
      cout << endl;
   }

   return 0;
}
