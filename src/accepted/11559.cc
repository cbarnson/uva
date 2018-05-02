// Cody Barnson
// UVA - C++ Competitive Programming
// 11559 - Event planning
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


int main() {


   int n, b, h, w;
   while (cin >> n >> b >> h >> w) {

      // minimum cost of te stay for your group
      uint mcost = numeric_limits<uint>::max();
      
      // do for each of the 'h' hotels
      for (int i = 0; i < h; i++) {
	 // price per person for this hotel
	 int p; cin >> p;
	 // do for each of the 'w' weeks, the jth item is the number of
	 // available beds for each week
	 for (int j = 0; j < w; j++) {
	    int a; cin >> a;
	    if (a < n) continue; // not enough beds
	    else {
	       uint total = p * n;
	       mcost = min(mcost, total);
	    }
	 }
      }

      // check with budget 'b'
      uint budget = b;
      if (mcost > budget) {
	 cout << "stay home" << endl;
      } else {
	 cout << mcost << endl;
      }

      
      
   }
   


   return 0;
}
