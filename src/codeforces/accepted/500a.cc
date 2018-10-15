// Problem #    : 500a
// Created on   : 2018-10-14 17:02:55
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

   vi A(n-1);
   for (auto &x : A) cin >> x;
   A.push_back(1);

   t--;

   for (int i = 0; i < n;) {
      if (i == t) {
	 cout << "YES" << endl;
	 return 0;
      }
      i += A[i];
   }

   cout << "NO" << endl;
   
   


}
