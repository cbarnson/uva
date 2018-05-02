#include <bits/stdc++.h>

using namespace std;

int factor(int n) {
   int count = 0;
   int printed = 0;
   long long p;

   if (n == 0 || n == 1) {
      // cout << n << endl;
      return count;
   }
   if (n < 0) {
      n *= -1;
      assert(0);
      cout << "-1" << endl;
      printed = 1;
   }

   while (n % 2 == 0) {
      n/=2;
      count++;
      // cout << "2" << endl;
      printed = 1;
   }

   for (p = 3; p*p <= n; p += 2) {
      while (n % p == 0) {
   	 n /= p;
	 count++;
   	 // cout << p << endl;
   	 printed = 1;
      }
   }

   if(n>1 || !printed) {
      count++;
      // cout << n << endl;
   }
   return count;
}

const int NN = 1000001;

int main() {

   int x;

   bool seen[NN];
   int fac[NN] = {0};
   int sum[NN] = {0};

   fill(seen, seen+NN, false);
   // fill(fac, fac+NN, 0);
   // fill(sum, sum+NN, 0);

   return 0;
   
   while (cin >> x) {
      cout << "case x = " << x << ",  ";
      int total = 0;
      while (x > 1) {
	 // cout << "--- x=" << x << ", ";
	 int f = factor(x--);
	 // cout << f << endl;
	 total += f;
      }
      cout << "total: " << total << endl;
   }

   return 0;

}
