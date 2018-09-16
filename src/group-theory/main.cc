#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
using namespace std;


int main() {

   int A[] = { 4, 8, 12, 16 };

   int C[4][4] = {};
   for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
	 C[i][j] = (A[i] * A[j]) % 20;
      }
   }

   REP(i, 4) {
      REP(j, 4) {
	 cout << setw(4) << C[i][j];
      }
      cout << endl;
   }
   cout << endl;

}
