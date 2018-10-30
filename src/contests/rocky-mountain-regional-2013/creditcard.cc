#include <bits/stdc++.h>
using namespace std;


int R(double num) {
   return num < 0 ? num - 0.5 : num + 0.5;
}

double Interest(double rate, double amt) {
   int cents = R(rate * amt);
   return (double)cents / 100.0;
}


const int NN = 1201;

int main() {
   
   int tc;
   double r, b, m;
   cin >> tc;
   while (tc--) {
      cin >> r >> b >> m;
      
      if (b == 0) {
	 cout << "0" << endl;
	 continue;
      }
      
      double B[NN];
      B[0] = b;

      int i;

      // double rate = r / 100.0;
      
      for (i = 1; i < NN; i++) {

	 

	 // B[i] = b * pow((1 + rate/12), i) -
	 //    m * 12 * ((pow(1 + rate/12, i) - 1) / rate);
	 // cout << "after " << i << " payments, owing: " << B[i] << endl;

	 B[i] = B[i-1] + Interest(r, B[i-1]) - m;
	 // cout << "after " << i << " payments, owing: " << BB[i] << endl;

	 if (B[i] <= 0.0) {
	    break;
	 }	 
      }

      // cout << "\n\n";
      
      if (i < NN) {
	 cout << i << endl;
      } else {
	 cout << "impossible" << endl;
      }



      
   }
   


   return 0;
}
