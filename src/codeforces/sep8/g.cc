#include <bits/stdc++.h>
using namespace std;

int main() {

   int n;
   int A[11];
   while (cin >> n) {
      fill(A, A+11, 0);
      int t = 0;
      for (int i = 0; i < n; i++) {
	 cin >> A[i];
	 t += A[i];
      }

      if (n == 1) {
	 cout << -1 << endl;
	 continue;
      }

      for (int i = 1; i < (1 << n) - 1; i++) {
	 int s = 0, cnt = 0;
	 for (int j = 0; j < n; j++) {
	    if (i & (1 << j)) {
	       // if( (i >> j) & 1 )
	       s += A[j];
	       cnt++;
	    }
	 }
	 if ((t - s) != s) {
	    cout << cnt << endl;
	    for (int j = 0; j < n; j++) {
	       if (i & (1 << j)) {
		  cout << j + 1;
		  cnt--;
		  if (cnt)
		     cout << " ";
		  else
		     cout << endl;
	       }
	    }
	    break;
	 } else if (i == (1 << n) - 2) {
	    cout << -1 << endl;
	    break;
	 }
      }
   }


}
