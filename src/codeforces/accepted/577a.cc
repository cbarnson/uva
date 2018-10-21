// Problem #    : 577a
// Created on   : 2018-10-21 14:28:42
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, x;
   cin >> n >> x;

   int cnt = 0;
   for (int i = 1; i <= (int)sqrt(x); i++) {
      if (x % i == 0 && i <= n && x / i <= n) cnt += (i == x / i ? 1 : 2);
   }
   cout << cnt << endl;

}
