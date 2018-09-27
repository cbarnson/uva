#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

// bitset<10000010> p;
// ll sz;
// vi V;



// void sieve(ll P, ll Y) {
//   sz = min(1000000LL, Y + 1);
//   p.set(); p[0] = p[1] = 0;
//   for (ll i = 2; i <= P; i++) {
//     if (p[i]) {
//       for (ll j = i * i; j <= Y; j += i) {
// 	p[j] = 0;
//       }
//       V.push_back(i);
//     }
//   }
// }

// bool isP(ll x) {
//   if (x <= sz) return p[x];
//   for (int i = 0; i < V.size(); i++)
//     if (x % V[i] == 0)
//       return false;
//   return true;
// }


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll P, Y;
  cin >> P >> Y;
  for (ll k = Y; k > P; k--) {
    for (ll i = 2; i <= P && i * i <= Y; i++) {
      if (k % i == 0) {
	cout << k << endl;
	return 0;
      }
    }
  } 
  cout << -1 << endl;

   
}
	  


