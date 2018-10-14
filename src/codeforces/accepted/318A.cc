// Problem #    : 318A
// Created on   : 2018-10-14 13:17:14
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   ll n, k;
   cin >> n >> k;

   ll no = (n + 1) / 2, ne = n / 2;
   
   // in odds?
   if (k <= no) {
      cout << 2 * (k - 1) + 1 << endl;
      return 0;
   }

   // evens?
   cout << 2 * (k - no) << endl;
   


}
