// Problem #    : 160A
// Created on   : 2018-10-14 10:30:46
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

   sort(A.rbegin(), A.rend());
   int s = accumulate(begin(A), end(A), 0);
   int k = 0;
   FR(i, n) {
      k += A[i];
      if (k > (s - k)) {
	 cout << i + 1 << endl;
	 return 0;
      }
   }
   
}
