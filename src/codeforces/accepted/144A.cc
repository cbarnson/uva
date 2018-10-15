// Problem #    : 144A
// Created on   : 2018-10-14 14:51:29
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

   int mx = max_element(A.begin(), A.end()) - A.begin();
   int cnt = 0;
   while (mx > 0) swap (A[mx], A[mx-1]), cnt++, mx--;
   

   int mi = min_element(A.rbegin(), A.rend()) - A.rbegin();
   mi = n - mi - 1;
   while (mi < n - 1) swap (A[mi], A[mi+1]), cnt++, mi++;

   cout << cnt << endl;
}
