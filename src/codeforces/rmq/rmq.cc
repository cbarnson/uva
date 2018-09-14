#include <bits/stdc++.h>
using namespace std;

class RMQ {
public:
   vector<int> A;
   vector<vector<int>> M;
   RMQ(const vector<int> &_A) {
      A.assign(_A.begin(), _A.end());

      int n = A.size();
      M.assign(n, vector<int>(log2(n + 1), -1));
      for (int i = 0; i < n; i++) M[i][0] = i;

      for (int j = 1; (1 << j) <= n; j++)
	 for (int i = 0; i + (1 << j) - 1 < n; i++)
	    M[i][j] = (A[M[i][j-1]] < A[M[i + (1 << (j - 1))][j - 1]])
	       ? M[i][j - 1] : M[i + (1 << (j - 1))][j - 1];

      for (int i = 0; i < n; i++) {
	 for (int j = 0; j < log2(n + 1); j++) {
	    cout << M[i][j] << " ";
	 }
	 cout << endl;
      }
   }

   int query(int i, int j) {
      // k is length of the range (e.g. i = 0, j = 4 for { 0, 2, 1, 5, 3 }, k = 5)
      int k = log2(j - i + 1);
      return (A[M[i][k]] <= A[M[j - (1 << k) + 1][k]]) ? M[i][k] : M[j - (1 << k) + 1][k];
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
	 int q = X.query(L, R);
	 ans[L] += (ans[L] >> 5) ^ (ans[L] << 4) ^ X.query(L, R);
      }
   }

   for (int i = 0; i < n; i++) {
      cout << (i ? " " : "") << ans[i];
   }
   cout << endl;

}
