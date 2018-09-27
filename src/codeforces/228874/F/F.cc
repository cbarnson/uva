#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int C[501];
int N, K;

int dp[501][501];

int f(int n, int k, vi &A) {

   if (k == 0) {
      // output
      for (auto &x : A) cout << x << " ";
      cout << endl;
      return 1;
   }
   if (k < 0 || n >= N)
      return 0;

   // if (dp[n][k] != -1)
   //    return dp[n][k];

   int x = f(n + 1, k, A);
   A.push_back(C[n]);
   int y = f(n + 1, k - C[n], A);
   A.pop_back();
   
   // int x = f(n + 1, k) + f(n + 1, k - C[n]);
   return x + y;
   // return (dp[n][k] = x + y);  
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> N >> K;
   FR(i, N) cin >> C[i];
   sort(C, C+N, greater<int>());

   FR(i, 501) FR(j, 501) dp[i][j] = -1;

   vi A;
   int ans = f(0, K, A);
   cout << ans << endl;

   // idea... recover the sets, all poss subsets on each set (too large?), take
   // distinct sums, output in sorted order
   
   // debug
   for (int i = 0; i <= N; i++) {

      if (i == 0) {
	 cout << setw(11) << "";
	 for (int j = 0; j <= K; j++) {
	    cout << setw(4) << j;
	 }
	 cout << endl << setw(11) << "" << string(4 * (K + 1), '-') << endl;
      }
      
      cout << "C[" << setw(2) << i << "]=" << setw(2) << C[i] << " : ";
      for (int j = 0; j <= K; j++) {
	 if (dp[i][j] == -1)
	    cout << setw(4) << "";
	 else
	    cout << setw(4) << dp[i][j];
      }
      cout << endl;
   }
}


