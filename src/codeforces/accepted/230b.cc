// Problem #    : 230b
// Created on   : 2018-10-21 09:56:53
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   cin >> n;

   bitset<10000010> p;
   ll sz;
   auto s = [&](int m) {
      sz = m + 1;
      p.set(); p[0] = p[1] = 0;
      for (ll i = 2; i <= sz; i++) {
	 if (p[i]) {
	    for (ll j = i * i; j <= sz; j += i) {
	       p[j] = 0;
	    }
	 }
      }
   };
   s(1000100);
   
   FR(i, n) {
      ll x;
      cin >> x;

      ll y = sqrt(x);
      if (x > 3 && y * y == x && p[y]) 
	 cout << "YES" << endl;
      else
	 cout << "NO" << endl;
      
      
   }


}
