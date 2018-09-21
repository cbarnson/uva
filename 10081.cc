#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

double dp[10][101];
int k, N;

double f(int l, int n) {
   if (n == 0 || l < 0 || l > k)
      return 0;
   if (n == 1)
      return (dp[l][n] = 1 / (pow(k+1, N)));
   
   if (dp[l][n])
      return dp[l][n];

   double ans = f(l, n - 1) + f(l + 1, n - 1) + f(l - 1, n - 1);

   return (dp[l][n] = ans);
}

int main() {

   int n;
   while (cin >> k >> n) {

      N = n;
      for (int i = 0; i < 10; i++) {
	 for (int j = 0; j < 101; j++) {
	    dp[i][j] = 0;
	 }
      }


      double s = 0;
      
      for (int i = 0; i <= k; i++) {
	 double x = f(i, n);
	 // cout << i << " : " << x << endl;
	 s += x;
      }

      // for (int i = 0; i < 10; i++) {
      // 	 for (int j = 0; j < 10; j++) {
      // 	    cout << setprecision(3) << fixed << dp[i][j] * pow(k+1, n) << " ";
      // 	 }
      // 	 cout << endl;
      // }

      cout << setprecision(5) << fixed << s * 100 << endl;
      
      
   }

}
