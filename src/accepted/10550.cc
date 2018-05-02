#include <bits/stdc++.h>
using namespace std;

int main() {
   int s, x, y, z; cin >> s >> x >> y >> z;
   while (s || x || y || z) {

      int total = 0;
      total += 360 * 3;
      
      // 1st - cw
      int ticks = 0;

      // 1st - cw
      int diff = abs(s - x);
      if (s > x) 
	 ticks += diff;
       else
	 ticks += (40-diff);
      
      // 2nd - ccw
      diff = abs(x - y);
      if (x > y)
	 ticks += (40-diff);
      else
	 ticks += diff;

      // 3rd cw
      diff = abs(y - z);
      if (y > z)
	 ticks += diff;
      else
	 ticks += (40-diff);

      //cout << "total ticks: " << ticks << endl;
      total += (ticks*9);
      cout << total << endl;
      
      cin >> s >> x >> y >> z;
   }
}
