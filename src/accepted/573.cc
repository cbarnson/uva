// Cody Barnson
// UVA - C++ Competitive Programming
// 573 - The Snail
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



// bottom of 6 foot well
// sun up: +3
// sun down: -1

// climbs 0.3 less each day

// day is sun followed by dark

int main() {

   int h, u, d, f;   
   while (cin >> h >> u >> d >> f && h != 0) {
      
      double fatigue = ((double)f / 100.0) * (double)u;
      double curr = 0.0;

      bool night = false;
      int day = 0;
      while (!(curr < 0 || curr > h)) {
	 // cout << "day " << day << ", curr " << curr << endl;
	 if (night) {
	    curr -= d;
	 } else {
	    double climb = ((double)u - ((double)day * fatigue));
	    climb = max(0.0, climb);
	    curr += climb;
	    day++;
	 }
	 night = !night;	 	 
      }
      if (curr < 0.0) {
	 cout << "failure on day " << day << endl;
      } else if (curr > h) {
	 cout << "success on day " << day << endl;
      } else {
	 assert(0);
      }
      
   }


   return 0;
}
