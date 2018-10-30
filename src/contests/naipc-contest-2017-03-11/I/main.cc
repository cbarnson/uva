#include <bits/stdc++.h>
using namespace std;

int main() {

   double c;
   int n;
   cin >> c >> n;

   double total = 0.0;
   while (n--) {

      double l, w;
      cin >> w >> l;

      total += (w * l * c);

   }
   
   cout << setprecision(7) << fixed << total << endl;


   return 0;
}
