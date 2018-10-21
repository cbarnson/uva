// Problem #    : 584a
// Created on   : 2018-10-21 13:23:26
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, t;
   cin >> n >> t;

   if (t == 10) {
      if (n < 2)
	 cout << -1 << endl;
      else {
	 cout << 1 << string(n - 1, '0') << endl;
      }
   } else {
      cout << string(n, (char)(t + '0')) << endl;
   }
   
}
