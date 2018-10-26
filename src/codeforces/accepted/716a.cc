// Problem #    : 716a
// Created on   : 2018-10-26 15:44:45
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   ll n, c;
   cin >> n >> c;

   ll x;
   cin >> x;

   int ans = 1;
   for (int i = 1; i < n; i++) {
      ll y;
      cin >> y;
      ll d = y - x; x = y;
      if (d > c) ans = 1;
      else ans++;
   }
   cout << ans << endl;
 
     
   


}
