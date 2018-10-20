#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

ll dp[3][3005];
int n;
vector<ll> C, S;

const ll INF = 10e9;

ll f(int i, int t) {
   if (t == 3) return C[i];
   if (dp[t][i]) return dp[t][i];

   ll ans = INF;
   for (int j = i + 1; j < n; j++) {
      if (S[i] < S[j]) {
	 ll a = min(f(j, t), C[j] + f(j, t + 1));
	 ans = min(ans, a);
      }
   }

   return (dp[t][i] = ans);
}


// ll f(int i) {
//    if (!(i < (n-2))) return -1;

//    if (dp[i]) return dp[i];

//    ll ans = -1;
//    for (int j = i + 1; j < n-1; j++) {
//       if (S[i] < S[j]) {
// 	 for (int k = j + 1; k < n; k++) {
// 	    if (S[j] < S[k]) {
// 	       ll a = C[i] + C[j] + C[k];
// 	       ans = (ans == -1 ? a : min(ans, a));
// 	    }
// 	 }
//       }
//    }

//    return (dp[i] = ans);
// }

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> n;

   C.assign(n, 0LL);
   S.assign(n, 0LL);
   FR(i, n) {
      cin >> S[i];
   }

   FR(i, n) {
      cin >> C[i];
   }

   ll ans;
   for (int i = 0; i < n-2; i++) {
      cout << C[i] + f(i, 1) << endl;
      // ans = (i == 0 ? C[i] + f(i, 1) : min(ans, C[i] + f(i, 1)));
   }

   // if (ans >= INF)
   //    cout << -1 << endl;
   // else
   //    cout << ans << endl;

}
