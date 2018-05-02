#include <bits/stdc++.h>
using namespace std;

int main() {

   int k;
   while (cin >> k) {

      int deltaX, deltaY;
      cin >> deltaX >> deltaY;

      while (k--) {
	 int x, y; cin >> x >> y;
	 x -= deltaX; y -= deltaY;
	 if (x > 0 && y > 0) 
	    cout << "NE" << endl;
	 else if (x > 0 && y < 0)
	    cout << "SE" << endl;
	 else if (x < 0 && y > 0)
	    cout << "NO" << endl;
	 else if (x < 0 && y < 0)
	    cout << "SO" << endl;
	 else
	    cout << "divisa" << endl;
	    
      }
      
   }
  
   


   return 0;
}
