// Problem #    : 231
// Created on   : 2018-10-19 13:23:54
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int lis(vi &A) {
   int n = A.size();
   reverse(begin(A), end(A));
   vi last(n + 1), pos(n + 1), pred(n);
   if (n == 0)
      return 0;
   int len = 1;
   last[1] = A[pos[1] = 0];
   for (int i  = 1; i < n; i++) {
      int j = upper_bound(last.begin() + 1, last.begin() + len + 1, A[i]) - last.begin();
      pred[i] = (j - 1 > 0) ? pos[j - 1] : -1;
      last[j] = A[pos[j] = i];
      len = max(len, j);
   }
   return len;
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int t = 1;
   while (1) {

      int x;
      cin >> x;
      if (x == -1) break;

      vi A(1, x);
      while (cin >> x && x != -1) {
	 A.push_back(x);
      }

      if (t > 1) cout << endl;
      cout << "Test #" << t++ << ":" << endl << "  maximum possible interceptions: " << lis(A) << endl;

      
      
      
   }

}
