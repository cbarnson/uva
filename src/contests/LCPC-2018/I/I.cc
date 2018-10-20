#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i) 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> ii;

int dp[1005];
vector<ii> PH;

ll f(int h) {
   if (h <= 0) return 0;
   if (dp[h]) return dp[h];
   ll ans = -1;
   for (int i = 0; i < PH.size(); i++) {
      ll j = f(h - PH[i].second) + PH[i].first;
      ans = (ans == -1)
	 ? j
	 : min(ans, j);
   }
   return (dp[h] = ans);
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, k;
   cin >> n >> k;

   FR(i, k) {
      ll h, p; cin >> h >> p;
      PH.emplace_back(p, h);
   }

   auto ans = f(n);
   cout << ans << endl;
   

   

}
