//================================
//UVA problem#: 305
//CPSC 3200,	2017-01-15
//Cody Barnson,	ID#001172313
//================================
#include <bits/stdc++.h>
using namespace std;

// rather than storing information in an array, we can just keep track
// of a moving index around a 'circular' array concept, whose size
// is decremented by one each time.  
bool Solved(int k, int m) {
   int sz = 2*k;
   int i = 0;
   i = (i + m) % sz;
   // loop until one of the first kth 'guys' would be removed
   while (i >= k) {
      if (i == (sz-1)) 
	 i = 0;      
      sz--;
      i = (i + m) % sz;
   }
   // at this point, 'size' of the 'circular array' must be no greater
   // than k, or m is not a valid solution.
   return !(sz > k);
}

// given k, we know 0, 1, ... , (k-1) are good guys
// and k, k+1, ... , k+(k-1) are bad guys
// note: my calculations consider indices 0-based
int FindM(int k) {
   int m, x = 0;
   while (true) {
      for (int i = 0; i < k; i++) {
	 // optimization for m, we only check possible m values if that value
	 // is guaranteed to remove a 'bad' guy (i.e. val % size >= k)
	 m = k+i + 2*k*x;
	 if (Solved(k, m)) 
	    return m+1;	 
      }
      // incr size factor
      x++;   
   }
}

int main() {
   int k;
   while (cin >> k && k != 0) {
      int ans = FindM(k);
      cout << ans << endl;
   }
   return 0;
}
