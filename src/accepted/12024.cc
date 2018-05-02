// UVA 12024 - Hats
// Derangement problem
// Accepted
#include <bits/stdc++.h>
using namespace std;

int der(int n) {
   if (n == 0 || n == 2)
      return 1;
   if (n == 1)
      return 0;

   return ((n-1) * (der(n-1) + der(n-2)));
}

int fac(int n) {
   if (n == 0 || n == 1)
      return 1;
   return n * fac(n-1);
}

int main() {

   int tc;
   cin >> tc;
   while (tc--) {
      int n;
      cin >> n;
      cout << der(n) << "/" << fac(n) << endl;
   }


   return 0;
}
