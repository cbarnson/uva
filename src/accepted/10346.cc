// UVA 10346 Peter's Smokes
// Accepted
#include <bits/stdc++.h>
using namespace std;

int main() {


   int n, k;
   while (cin >> n >> k) {

      int num = n;

      int count = 0;
      while (k <= num) {
	 num = num - k + 1;
	 count++;
      }

      cout << n + count << endl;
      

      
   }


   
   return 0;
}
