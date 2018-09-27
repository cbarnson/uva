#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int minFac(int n) {
   int mf, f = 0;
   if (!n || n == 1) return n;
   while (!(n & 1)) {
      n /= 2;
      mf = (f ? min(mf, 2) : 2), f = 1;
   }

   for (ll i = 3; i * i <= n; i += 2) {
      while (n % i == 0) {
	 n /= i;
	 mf = (f ? min(mf, (int)i) : i), f = 1;
      }
   }

   if (n > 1 || !f)
      mf = (f ? min(mf, n) : n);

   return mf;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll P, Y;
  cin >> P >> Y;
  for (ll k = Y; k > P; k--) {
     int mf = minFac(k);
     if (mf > P) {
	cout << k << endl;
	return 0;
     }
  } 
  cout << -1 << endl;

   
}
	  


