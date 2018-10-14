// Problem #    : 136A
// Created on   : 2018-10-14 12:04:01
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
   vi A(n+1), B(n+1);
   for (int i = 1; i <= n; i++) {
      cin >> A[i];
      B[A[i]] = i;
   }

   for (int i = 1; i <= n; i++) {
      cout << B[i];
      if (i == n) cout << endl;
      else cout << " ";
   }
   
   
   


}
