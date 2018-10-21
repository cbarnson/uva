// Problem #    : 270a
// Created on   : 2018-10-21 14:58:34
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int t, a;
   cin >> t;
   while (t--) {
      cin >> a;
      if (360 % (180 - a) == 0) {
	 cout << "YES" << endl;
      } else {
	 cout << "NO" << endl;
      }
   }
}
