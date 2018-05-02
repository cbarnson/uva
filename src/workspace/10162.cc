#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;

typedef pair<ULL, ULL> ii;

ULL Z = 1;
ULL I = 0;
ULL M = 10;

ULL f(ULL x) {
   ULL res = (Z * x) % M;
   return res;
}

ii cycleFind(ULL x0) {
   ULL t = f(x0);
   ULL h = f(f(x0));
   while (t != h) {
      t = f(t);
      h = f(f(h));
   }
   ULL mu = 0;
   h = x0;
   while (t != h) {
      t = f(t);
      h = f(h);
      mu++;
   }
   ULL l = 1;
   h = f(t);
   while (t != h) {
      h = f(h);
      l++;
   }
   return ii(mu, l);   
}

ULL lastDigit(ULL n) {
   Z = n;
   ii res = cycleFind(1);
   ULL mu = res.first, lambda = res.second;
   ULL k = (n - mu) / lambda;
   ULL rem = n - (mu + k * lambda);
   ULL small = pow(Z, mu);
   ULL large = small;
   for (ULL i = 0; i < rem; i++) {
      large = f(large);
   }
   return large;
}

int main() {

   ULL n;

   while (cin >> n) {
      if (!n)
	 break;
      I = 0;
      for (ULL i = 1; i <= n; i++) {
	 I = (I + lastDigit(i)) % M;
      }
      cout << I << endl;
   }

   
   return 0;
}
