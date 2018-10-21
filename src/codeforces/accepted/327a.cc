// Problem #    : 327a
// Created on   : 2018-10-21 16:02:21
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

   vi A(n); for (auto &x : A) cin >> x;
   int mx = 0;
   for (int i = 0; i < n; i++) {
      for (int j = i + 1; j <= n; j++) {
	 int x = count(begin(A) + i, begin(A) + j, 0);
	 int y = count(begin(A) + i, begin(A) + j, 1);
	 mx = (i == 0 && j == 1 ? x - y : max(mx, x - y));
      }
   }
   cout << mx + count(begin(A), end(A), 1) << endl;
   

}
