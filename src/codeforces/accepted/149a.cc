// Problem #    : 149a
// Created on   : 2018-10-23 14:15:40
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int k; cin >> k;

   vi A(12); for (auto &x : A) cin >> x;
   sort(A.rbegin(), A.rend());

   int m = 0, i = 0;
   while (1) {

      if (m >= k) {
	 cout << i << endl;
	 return 0;
      }

      if (i == 12) break;
      m += A[i++];      
   }
   cout << -1 << endl;
}
