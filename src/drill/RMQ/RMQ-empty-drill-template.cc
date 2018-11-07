#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef vector<int> vi;

class RMQ {
public:
   vector<int> A;
   vector<vector<int>> M;
   RMQ(const vector<int> &_A) {

   }

   int query(int L, int R) {

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
