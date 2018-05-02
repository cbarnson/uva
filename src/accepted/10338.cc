// Problem : UVa 10338 - Mischievous Children
// Author  : Cody Barnson
// Date    : Dec. 16, 2017
#include <bits/stdc++.h>
using namespace std;

// Gives us all the space we'll need to store large factorials and
// compute multinomial coefficient
typedef unsigned long long ull;

// each word will have at most 20 letters
const int NN = 21;

// compute and store factorials, lookup by index
ull ff[NN] = { 0 };
ull fac(ull n) {
   if (n < 2)
      return 1;
   return n * fac(n - 1);
}

int main() {

   // preprocessing   
   for (int i = 0; i < NN; i++) {
      ff[i] = fac(i);
   }
   
   int t, tcase = 1;
   cin >> t;
   while (t--) {
      string s;
      cin >> s;

      // Use a map to easily iterate over
      map<char, int> M;
      for (auto &i : s) {
	 M[i] += 1;
      }

      // solve using multinomial coefficient
      int len = s.length();
      ull n = ff[len];
      for (auto &i : M) {
	 ull mi = ff[i.second];
	 n /= mi;
      }
      cout << "Data set " << tcase++ << ": " << n << endl;      
   }
   return 0;
}
