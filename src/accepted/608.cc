#include <bits/stdc++.h>
using namespace std;

// 0 1 2 3 4 5 6 7 8 9 10 11 12
// A B C D E F G H I J K  L  M

string letter = "ABCDEFGHIJKLM";


int main() {

   int t; cin >> t;
   while (t--) {

      string left[3];
      string right[3];
      string balance[3];

      for (int i = 0; i < 3; i++) {
	 cin >> left[i] >> right[i] >> balance[i];
      }

      bool l[12];
      bool h[12];
      for (int i = 0; i < 12; i++) {
	 l[i] = true;
	 h[i] = true;


	 // for each letter

	 // if even, not heavier or lighter
	 if (balance[i] == "even") {
	    l[i] = false;
	    h[i] = false;
	    continue;
	 } 

	 
      }

      
      


   }

   return 0;
}
