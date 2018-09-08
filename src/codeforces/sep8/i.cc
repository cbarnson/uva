#include <bits/stdc++.h>
using namespace std;

int main() {

   int n, k;
   int A[101];
   while (cin >> n >> k) {
      fill(A, A+101, -1);
      for (int i = 0; i < n; i++) {
	 cin >> A[i];
      }

      int l = 0, r = n - 1;
      for (int i = 0; i < n; i++) {
	 if (A[i] > k)
	    break;
	 l++;
      }

      if (l < n) {	 
	 for (int j = n - 1; j >= l; j--) {
	    if (A[j] > k)
	       break;
	    r--;
	 }
	 cout << (l + (n - 1) - r) << endl;
      } else {
	 cout << n << endl;
      }
   }

}
