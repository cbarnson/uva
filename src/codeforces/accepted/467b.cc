// Problem #    : 467b
// Created on   : 2018-10-24 12:48:45
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, m, k;
   cin >> n >> m >> k;

   vi a(m);
   for (auto &x : a) cin >> x;

   cin >> m;
   int cnt = 0;
   for (auto &x : a) {
      if (__builtin_popcount(x ^ m) <= k) cnt++;
   }
   cout << cnt << endl;
   


}
