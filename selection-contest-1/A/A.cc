#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> ii;

int lcm(int a, int b) {
   return a * (b / __gcd(a, b));
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   vector<ll> P = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
   
   int n;
   cin >> n;

   vector<ii> A(n);
   for (auto &x : A) cin >> x.first >> x.second;

   if (n == 1) {
      cout << A[0].first << endl;
      return 0;
   }

   vi cp(P.size(), 0);
   for (int i = 0; i < n; i++) {
      ll ab = A[i].first * A[i].second;      
      for (int j = 0; j < P.size(); j++) {
	 if (__gcd(ab, P[j]) == 1)
	    cp[j] = 1;
      }
   }

   for (int j = 0; j < P.size(); j++) {
      if (cp[j] == 0) {
	 cout << P[j] << endl;
	 return 0;
      }
   }

   cout << -1 << endl;

   
   

}
