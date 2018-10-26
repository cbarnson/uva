// Problem #    : 513a
// Created on   : 2018-10-25 19:32:51
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int n1, n2, k1, k2;

int dp[55][55][2];

int f(int a, int b, int t) {

   if (a <= 0 && t) return 0;
   if (b <= 0 && !t) return 1;

   int &x = dp[a][b][t];
   if (x != -1) return x;
   
   if (t) {
      for (int i = 1; i <= k1; i++) {
	 if (a - i >= 0)
	    x = max(x, f(a - i, b, !t));
      }

      return x;
   }

   for (int i = 1; i <= k2; i++) {
      if (b - i >= 0) {
	 int y = f(a, b - i, !t);
	 if (x == -1)
	    x = y;
	 else
	    x = min(x, y);
      }
   }

   return x;
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   FR(i, 55) FR(j, 55) FR(k, 2) dp[i][j][k] = -1;
   
   cin >> n1 >> n2 >> k1 >> k2;
   cout << (f(n1, n2, 1) ? "First" : "Second") << endl;


}
