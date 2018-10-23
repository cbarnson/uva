// Problem #    : 509a
// Created on   : 2018-10-23 09:48:22
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n; cin >> n;

   int mx = 1;
   vector<vi> A(n, vi(n, 1));
   for (int i = 1; i < n; i++) {
      for (int j = 1; j < n; j++) {
	 A[i][j] = A[i - 1][j] + A[i][j - 1];
	 mx = max(mx, A[i][j]);
      }
   }
   cout << mx << endl;
   


}
