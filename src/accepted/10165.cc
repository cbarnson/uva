// Problem : UVa 10165 - Stone Game, Difficulty: Lev 3
// Author  : Cody Barnson
// Date    : Dec. 20, 2017
#include <bits/stdc++.h>
using namespace std;

int main() {

   int n;
   while (cin >> n && n != 0) {
      unsigned int ans = 0;      
      while (n--) {
	 unsigned int p;
	 cin >> p;
	 ans ^= p;
      }
      cout << (ans ? "Yes" : "No") << endl;
   }


   return 0;
}
