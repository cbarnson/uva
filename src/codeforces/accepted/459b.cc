// Problem #    : 459b
// Created on   : 2018-10-25 20:13:28
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   ll n;
   cin >> n;
   vector<ll> A(n); for (auto &x : A) cin >> x;

   sort(begin(A), end(A));
   ll i = upper_bound(begin(A), end(A), *begin(A)) - begin(A);
   ll j = lower_bound(begin(A), end(A), *A.rbegin()) - begin(A);

   
   if (A[i - 1] == A[j]) {
      cout << 0 << " " << (n * (n - 1)) / 2LL << endl;
      return 0;
   }

   cout << A[j] - A[i - 1] << " " << (n - j) * i << endl;


}
