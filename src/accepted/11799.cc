// Cody Barnson
// UVA - C++ Competitive Programming
// 11799 - Horror Dash
#include <bits/stdc++.h>
using namespace std;

// typedefs for common data types in contest problems
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

// return the next item index for circular array (or ring buffer)
int nextRing(int i, int size) {
   return ((i + 1) % size);
}
// return the previous item index for circular array (or ring buffer)
int prevRing(int i, int size) {
   return ((i + size - 1) % size);
}
// rounds a floating point value to the nearest integer
int roundNearest(double val) {
   int answer = (int)((double)val + 0.5);
   return answer;
}
// // shortcut for min/max
// ans = min(ans, new_computation);
// // get mid of 3 values
// int x, y, z;
// ans = max(min(x, y), min(max(x, y), z));
// common memset setttings
//memset(memo, -1, sizeof memo); // init DP memorization table with -1
//memset(arr, 0, sizeof arr); // clear array of integers


// find min speed that the clown must maintain so as not to get caught
// even if they keep on running forever

int main() {

   int cn = 1;
   int t; // <= 50
   cin >> t;
   while (t--) {

      cout << "Case " << cn++ << ": ";
      int n;
      cin >> n; // number of creatures

      uint maxspd = 0;      
      for (int i = 0; i < n; i++) {
	 uint val; cin >> val;
	 maxspd = max(maxspd, val);
      }
      cout << maxspd << endl;
      

   }
   

   return 0;
}
