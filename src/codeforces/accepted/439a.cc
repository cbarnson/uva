// Problem #    : 439a
// Created on   : 2018-10-26 15:51:53
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, d;
   cin >> n >> d;

   vi A(n);
   for (auto &x : A)
      cin >> x;

   int mi = (n - 1) * 10 + accumulate(begin(A), end(A), 0);

   if (mi > d) {
      cout << -1 << endl;
      return 0;
   }

   int x = (d - mi) / 5 + (n - 1) * 2;
   cout << x << endl;
   


}
