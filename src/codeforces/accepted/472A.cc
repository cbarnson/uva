// Problem #    : 472A
// Created on   : 2018-10-14 15:21:25
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

ll sz;
bitset<10000010> p;

void sieve(ll m) {
   sz = m + 1;
   p.set();
   // p[0] = p[1] = 0;
   for (ll i = 2; i <= sz; i++) {
      if (p[i])
	 for (ll j = i * i; j <= sz; j += i)
	    p[j] = 0;
   }
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   cin >> n;

   sieve(1000000);
   for (int i = 1; i < n; i++) {
      if (!p[i] && !p[n-i]) {
	 cout << i << " " << n - i << endl;
	 return 0;
      }
   }
   
}
