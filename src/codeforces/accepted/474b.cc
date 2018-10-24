// Problem #    : 474b
// Created on   : 2018-10-24 11:11:19
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
   vi A(1000050);

   int j = 0;
   FR(i, n) {
      int x; cin >> x;
      FR(k, x) {
	 A[j + k] = i + 1;
      }
      j += x;
   }

   int m; cin >> m;
   FR(i, m) {
      int x; cin >> x;
      cout << A[x - 1] << endl;
   }
   


}
