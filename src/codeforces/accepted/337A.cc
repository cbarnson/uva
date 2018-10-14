// Problem #    : 337A
// Created on   : 2018-10-14 11:22:00
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, m;
   cin >> n >> m;

   vi A(m);
   for (auto &x : A) cin >> x;

   sort(begin(A), end(A));

   int mi = 0x3f3f3f3f;
   for (int i = 0; i <= m - n; i++) {
      mi = min(mi, A[i + n - 1] - A[i]);
   }
   cout << mi << endl;
   


}
