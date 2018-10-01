#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> ii;

vector<ll> fac(ll n) {
   if (n < 2) return vector<ll>();

   vector<ll> ans;
   if (n % 2 == 0) {
      ans.push_back(2);
      while (n % 2 == 0) n /= 2;
   }

   for (ll i = 3; i * i <= n; i += 2) {
      if (n % i == 0) {
	 ans.push_back(i);
	 while (n % i == 0) n /= i;
      }
   }

   if (n > 1)
      ans.push_back(n);

   return ans;
   
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   cin >> n;

   
   
   vector<ii> A(n, ii(0, 0));
   for (auto &x : A) cin >> x.first >> x.second;
   vector<ll> f = fac(A[0].first * A[0].second);

   // try each factor, until find ans or run out of factors
   for (int i = 0; i < (int)f.size(); i++) {
      ll x = f[i];
      int good = 1;
      for (auto &y : A) {
	 if (__gcd(x, y.first) == 1 && __gcd(x, y.second) == 1) {
	    good = 0; break;
	 }
      }

      if (good) {
	 cout << x << endl;
	 return 0;
      }
   }

   cout << -1 << endl;
   
}
