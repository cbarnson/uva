// Problem #    : 455a
// Created on   : 2018-10-22 08:24:55
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    


vector<ll> A, dp;

ll f(ll n) {
   if (n == 0) return 0;
   if (n == 1) return A[n];

   if (dp[n] != -1) return dp[n];
   ll x = max(f(n - 1), f(n - 2) + A[n] * n);
   return (dp[n] = x);
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   cin >> n;

   A.assign(100010, 0); dp.assign(100010, -1);   
   FR(i, n) {
      int x; cin >> x;
      A[x]++;
   }

   cout << f(100000) << endl;


}
