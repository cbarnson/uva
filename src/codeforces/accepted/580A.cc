// Problem #    : 580A
// Created on   : 2018-10-14 11:31:45
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

   vi A(n);
   for (auto &x : A) cin >> x;

   int mx = 1, i = 0;
   for (int j = 1; j < n; j++) {
      if (A[j] < A[j-1]) 
	 i = j;      
      mx = max(mx, j - i + 1);
   }
   cout << mx << endl;
   


}
