// Problem #    : 588a
// Created on   : 2018-10-24 12:20:35
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

class rmq {
public:
   
   vi a;
   vector<vi> m;
   rmq(const vi &b) {
      a = b;
      int n = a.size();
      int nn = 31 - __builtin_clz(n) + 1;

      m.assign(nn, vi(n, -1));
      FR(j, n) m[0][j] = j;

      for (int i = 1; (1 << i) <= n; i++) {
	 for (int j = 0; (j + (1 << i)) <= n; j++) {
	    m[i][j] = a[m[i - 1][j]] <= a[m[i - 1][j + (1 << (i - 1))]]
	       ? m[i - 1][j]
	       : m[i - 1][j + (1 << (i - 1))];
	 }
      }
   }

   int query(int L, int R) {
      int k = 31 - __builtin_clz(R - L + 1);
      return a[m[k][L]] <= a[m[k][R - (1 << k) + 1]]
	 ? m[k][L]
	 : m[k][R - (1 << k) + 1];
   }

};

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   cin >> n;

   vi a(n), p(n);
   FR(i, n) {
      cin >> a[i] >> p[i];
   }

   rmq r(p);
   ll s = 0;
   for (int i = 0; i < n; i++) {
      int j = r.query(0, i);
      s += p[j] * a[i];
   }
   cout << s << endl;
      
   


}
