// Problem #    : 339b
// Created on   : 2018-10-14 17:08:21
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   ll n, m;
   cin >> n >> m;

   ll j = 0, cnt = 0;
   FR(i, m) {
      ll x; cin >> x; x--;
      if (j != x) {

	 if (j < x) cnt += (x - j);	 
	 else cnt += n - j + x;
	 
	 j = x;
      }
      // while (j != x) {
      // 	 j = (j + 1) % n;
      // 	 cnt++;
      // }      
   }

   cout << cnt << endl;

   
   


}
