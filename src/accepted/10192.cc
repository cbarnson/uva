// Cody Barnson
// 10192
#include <bits/stdc++.h>
using namespace std;

// Howard's longest common subsequence code
const int MAX_LEN = 100;

int LCS(int A[], int n, int B[], int m, int s[])
{
   int L[MAX_LEN+1][MAX_LEN+1];
   int i, j, k;
  
   for (i = n; i >= 0; i--) {
      for (j = m; j >= 0; j--) {
	 if (i == n || j == m) {
	    L[i][j] = 0;
	 } else if (A[i] == B[j]) {
	    L[i][j] = 1 + L[i+1][j+1];
	 } else {
	    L[i][j] = max(L[i+1][j], L[i][j+1]);
	 }
      }
   }
  
   /* the following is not needed if you are not interested in the sequence */
   k = 0;
   i = j = 0;
   while (i < n && j < m) {
      if (A[i] == B[j]) {
	 s[k++] = A[i];
	 i++;
	 j++;
      } else if (L[i+1][j] > L[i][j+1]) {
	 i++;
      } else if (L[i+1][j] < L[i][j+1]) {
	 j++;
      } else {
	 /* put tie-breaking conditions here */

	 /* eg. pick the one that starts at the first one the earliest */
	 j++;
      }
   }
   return L[0][0];
}

int main(void) {

   string s1, s2;
   int cn = 1;
   while (getline(cin, s1) && getline(cin, s2)) {
      int A[MAX_LEN], B[MAX_LEN], s[MAX_LEN];
      int n = s1.length();
      int m = s2.length();
      
      for (int i = 0; i < n; i++) {
	 A[i] = (int)s1[i];
      }
      
      for (int i = 0; i < m; i++) {
	 B[i] = (int)s2[i];
      }

      int l = LCS(A, n, B, m, s);
      cout << "Case #" << cn++ << ": you can visit at most " << l << " cities." << endl;
   }

   return 0;
}
