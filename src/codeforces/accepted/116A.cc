// Problem #    : 116A
// Created on   : 2018-10-14 09:23:50
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

   int c = 0, mx = 0;
   FR(i, n) {

      int a, b;
      cin >> a >> b;
      c -= a; c += b;

      mx = max(mx, c);
   }

   cout << mx << endl;
   


}
