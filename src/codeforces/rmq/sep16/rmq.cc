#include <bits/stdc++.h>
using namespace std;

class RMQ {
public:
   
   vector<int> A;
   vector< vector<int> > M;
   RMQ(const vector<int> &B) {
      A = B;
      int n = A.size();
      int m = 31 - __builtin_clz(n) + 1;

      M.assign(m, vector<int>(n));
      for (int j = 0; j < n; j++) M[0][j] = j;

      for (int i = 1; (1 << i) <= n; i++) {
	 for (int j = 0; (j + (1 << i)) <= n; j++) {
	    M[i][j] = (A[M[i - 1][j]] <= A[M[i - 1][j + (1 << (i - 1))]])
	       ? M[i - 1][j]
	       : M[i - 1][j + (1 << (i - 1))];
	 }
      }
   }
   
   int query(int L, int R) {
      int k = 31 - __builtin_clz(R - L + 1);
      return (A[M[k][L]] <= A[M[k][R - (1 << k) + 1]])
	 ? M[k][L]
	 : M[k][R - (1 << k) + 1];
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
