#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);

int main() {

   double a, b, v, A, s;
   
   while (cin >> a >> b >> v >> A >> s &&
	  !(a == 0 && b == 0 && v == 0 && A == 0 && s == 0)) {

      double rad = A * (pi/180.0);

      //acceleration
      double accel = v / s;
      // cout << "accel: " << accel << endl;
      double totald = 0.5*-accel*s*s + v*s;
      // cout << "total dist: " << totald << endl;

      // distance horizontal and vertical
      double dh = totald * cos(rad);
      double dv = totald * sin(rad);
      
      // how many times touch horizontal walls (vertical dist)
      int countv = dv / b;
      double leftoverv = fmod(dv, b);
      if (leftoverv > (b/2))
	 countv++;
      
      // how many times touch vertical walls (horizontal dist)
      int counth = dh / a;
      double leftoverh = fmod(dh, a);
      if (leftoverh > (a/2))
	 counth++;

      // output, vertical then horizontal
      cout << counth << " " << countv << endl;
      
   }
   
   


   return 0;
}
