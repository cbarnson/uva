// UVA 10759 - Dice Throwing
// Accepted
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int num_dice = 24;
const int N = num_dice + 1;
const int M = 6 * num_dice + 1;
ull x;
ull dp[N][M];


ull gcd(ull a, ull b) {
   return (a == 0) ? b : gcd(b % a, a);
}

int main() {

   ull n;
   while (cin >> n >> x) {
      if (n == 0 && x == 0)
	 break;

      for (ull i = 0; i <= n; i++) {
	 for (ull j = n-i; j <= ((n-i)*6); j++) {
	    if (i == 0)
	       dp[i][j] = (j >= x) ? 1 : 0;
	    else {
	       ull sum = 0;
	       for (ull k = 1; k <= 6; k++) {
		  sum += dp[i-1][j+k];
	       }
	       dp[i][j] = sum;
	    }
	 }
      }

      ull ans = dp[n][0];
      ull denom = pow(6, n);
      ull div = gcd(ans, denom);
      ull ans_res = dp[n][0] / div;
      ull ans_denom = denom / div;

      cout << ans_res;
      if (ans_denom != 1)
      	 cout << "/" << ans_denom;
      cout << endl;
   }
   


   return 0;
}
