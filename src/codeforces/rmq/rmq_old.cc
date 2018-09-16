#include <bits/stdc++.h>
using namespace std;

class RMQ {
public:
   vector<int> A;
   vector<vector<int>> M;
   RMQ(const vector<int> &_A) {
      A = _A;
      int n = A.size();
      
      M.assign(n + 1, vector<int>(n + 1, 0));
      for (int i = 0; i < n; i++) M[i][0] = i;

      for (int j = 1; (1 << j) <= n; j++) {
	 for (int i = 0; (i + (1 << j) - 1) < n; i++) {
	    M[i][j] = (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
	       ? M[i][j - 1]
	       : M[i + (1 << (j - 1))][j - 1];
	 }
      }
   }

   int query(int L, int R) {
      int k = (int)log2(R - L + 1);
      return (A[M[L][k]] <= A[M[R - (1 << k) + 1][k]])
	 ? M[L][k]
	 : M[R - (1 << k) + 1][k - 1];
   }

};

int main() {

   int n;
   cin >> n;

   vector<int> A(n);
   for (auto &i : A) cin >> i;

   RMQ X(A);   

   vector<int> ans(n);
   for (int L = 0; L < n; L++) {
      int skip = 1;
      if (n > 10000) skip = (rand() & 15) + 1;
      for (int R = L; R < n; R += skip) {
	 ans[L] += (ans[L] >> 5) ^ (ans[L] << 4) ^ X.query(L, R);
      }
   }
   for (int i = 0; i < n; i++) {
      cout << (i ? " " : "") << ans[i];
   }
   cout << endl;

}
