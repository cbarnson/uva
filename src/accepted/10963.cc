#include <bits/stdc++.h>
using namespace std;

int main() {


   int t; cin >> t;
   while (t--) {

      int w; cin >> w;
      bool valid = true;
      bool first = true;
      int diff;
      while (w--) {
	 int y1, y2; cin >> y1 >> y2;
	 if (first) {
	    diff = abs(y1-y2);
	    first = false;
	 } else {
	    if (abs(y1-y2) != diff) {
	       valid = false;
	       break;
	    }
	 }
      }

      if (valid) {
	 cout << "yes" << endl;
      } else {
	 cout << "no" << endl;
      }
      
   }


   return 0;
}
