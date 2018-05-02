#include <bits/stdc++.h>
using namespace std;

int main() {
   int t; cin >> t;
   while (t--) {
      int n, m; cin >> n >> m;
      n -= 2; m -= 2;
      float row_wise = (float)n / 3; 
      float col_wise = (float)m / 3;
      int N = ceil(row_wise);
      int M = ceil(col_wise);
      cout << N*M << endl;
   }
}
