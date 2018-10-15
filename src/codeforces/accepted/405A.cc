// Problem #    : 405A
// Created on   : 2018-10-14 14:37:25
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
   sort(begin(A), end(A));

   FR(i, n) {
      if (i) cout << " ";
      cout << A[i];
   }
   cout << endl;
   


}
