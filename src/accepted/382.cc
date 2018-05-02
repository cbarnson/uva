// UVA 382
// Accepted
#include <bits/stdc++.h>
using namespace std;

int main() {

   
   int n;
   cout << "PERFECTION OUTPUT" << endl;
   while (cin >> n) {

      if (n == 0) {
	 cout << "END OF OUTPUT" << endl;
	 return 0;
      }

      int res = 1;
      if (n > 1) {
	 for (int i = 2; i <= sqrt(n); i++) {
	    if (n % i == 0) {
	       if (i == (n / i)) {
		  res += i;
	       } else {
		  res += (i + n / i);
	       }
	    }
	 }
      } else {
	 cout << setw(5) << n << "  ";
	 cout << "DEFICIENT" << endl;
	 continue;
      }

      cout << setw(5) << n << "  ";
      if (res == n) {
	 cout << "PERFECT";
      } else if (res < n) {
	 cout << "DEFICIENT";
      } else {
	 cout << "ABUNDANT";
      }
      cout << endl;
   }


   return 0;
}
