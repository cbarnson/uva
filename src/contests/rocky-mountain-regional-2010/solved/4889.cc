// Cody Barnson
// 4889 - post office
#include <bits/stdc++.h>
using namespace std;

int main() {

   float a, b, c;
   while (cin >> a >> b >> c && !(a == 0 && b == 0 && c == 0)) {

      // NOTE: better way (simpler), put in array and call sort, or
      // if you have largest and smallest, the middle is
      // (a + b + c) - (l + t)
      float l, h, t; // largest, middle, smallest respectively
      l = max(a, max(b, c));
      t = min(a, min(b, c));
      h = max(min(a, b), min(max(a, b), c));
      
      if (l < 125 || h < 90 || t < 0.25 || ((l + 2*t + 2*h) > 2100)) {
	 cout << "not mailable" << endl;
      } else {
	 if (l > 380 || h > 300 || t > 50) {
	    cout << "parcel" << endl;
	 } else if (l > 290 || h > 155 || t > 7) {
	    cout << "packet" << endl;
	 } else {
	    cout << "letter" << endl;
	 }
      }
   }


   return 0;
}
