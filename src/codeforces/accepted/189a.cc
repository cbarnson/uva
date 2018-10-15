// Problem #    : 189a
// Created on   : 2018-10-14 19:37:00
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

vector<vi> dp;
vi A(3);

int f(int x, int y) {
   if (x == 0) return y;
   if (all_of(begin(A), end(A), [&](int z) { return x < z; }))
      return 0;

   if (dp[x][y] != -1) return dp[x][y];

   int mx = 0;
   FR(i, 3) {
      if (x >= A[i]) {
	 mx = max(mx, f(x - A[i], y + 1));
      }
   }

   return (dp[x][y] = mx);
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   cin >> n;
   FR(i, 3) cin >> A[i];

   dp.assign(4010, vi(4010, -1));
   cout << f(n, 0) << endl;
   
   


}
