// Problem #    : t
// Created on   : 2018-10-28 09:37:39
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
   vi A(n + 1, 0);
   for (int i = 1; i <= n; i++) {
      cin >> A[i];
   }

   vi B(n + 1, 0);
   adjacent_difference(begin(A), end(A), begin(B));

   B.erase(B.begin());
   vi ans;
   for (int k = 1; k <= n; k++) {
      for (int i = 0; i < n; i++) {
	 if (B[i] != B[i % k]) {
	    break;
	 }

	 if (i == n-1)
	    ans.push_back(k);
      }
   }

   cout << ans.size() << endl;
   FR(i, ans.size()) {
      cout << (i ? " " : "") << ans[i];
   }
   cout << endl;


}
