// Problem    : UVa 482 - Permutation Arrays
// Time limit : 3.000 seconds
// Difficulty : 2
// Author     : Cody Barnson
// Date       : Jan. 13, 2018
#include <bits/stdc++.h>
using namespace std;

int main() {

   int tc, x;
   cin >> tc;
   while (tc--) {

      vector<int> a;

      // remember that std::geline(cin, value) does not skip leading whitespace;
      // use std::ws when you need to switch between formatted and unformatted
      // input (i.e. whenever you use std::getline after std::cin
      string l;
      getline(cin >> std::ws, l);
      stringstream ss(l);
      while (ss >> x) {
	 a.push_back(x);
      }

      // to reset your stringstream, must do both the following steps:      
      ss.str(string()); // (1) reset underlying sequence to empty string      
      ss.clear();       // (2) clear fail and eof flags

      // get the 'permuted' values, store as strings to avoid bothering
      // with precision later
      getline(cin >> std::ws, l);      
      ss << l;      
      
      int sz = a.size();
      vector<string> b (sz, "");
      for (int i = 0; i < sz; i++) {
	 string s;
	 ss >> s;
	 b[a[i]-1] = s;
      }

      // output
      for (auto &i : b) {
	 cout << i << endl;
      }

      // newline between consecutive test cases
      if (tc) {
	 cout << endl;
      }
      

   }

   return 0;
}
