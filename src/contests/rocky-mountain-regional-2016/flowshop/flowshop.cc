// https://open.kattis.com/problems/flowshop
// Solved 20171031
#include <bits/stdc++.h>
using namespace std;

const int NN = 1000;
int P[NN][NN];
int C[NN][NN];

int main() {
   
   int n, m;
   cin >> n >> m;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
	 cin >> P[i][j];
      }
   }

   // compute C for all i, where j = 0
   C[0][0] = P[0][0];
   for (int i = 1; i < n; i++) {
      C[i][0] = C[i-1][0] + P[i][0];      
   }

   // compute C for all j, where i = 0
   for (int j = 1; j < m; j++) {
      C[0][j] = C[0][j-1] + P[0][j];
   }

   // do rest
   for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
	 C[i][j] = max(C[i-1][j], C[i][j-1]) + P[i][j];
      }
   }

   // output
   for (int i = 0; i < n; i++) {
      int j = m - 1;
      if (i) cout << " ";
      cout << C[i][j];      
   }
   cout << endl;
   

   return 0;
}
