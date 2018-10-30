// Cody Barnson
// 5733 - Iterated Difference
#include <bits/stdc++.h>
using namespace std;

// for each entry i, set to abs of i minus i+1
// last entry should loop around
void diff(int a[20], int n) {
   int temp = a[0];
   for (int i = 0; i < n-1; i++) {
      a[i] = abs(a[i] - a[i+1]);
   }
   a[n-1] = abs(a[n-1] - temp);
}

int main() {
   int n;
   int cn = 1;
   while (cin >> n && n != 0) {
      // read in values
      int arr[20];
      for (int i = 0; i < n; i++) {
	 cin >> arr[i];
      }
      int count = 0;
      // loop while either all entries do NOT match, or have completed
      // less than 1000 iterations
      while (!all_of(arr, arr+n, [&](int x) { return x == arr[0]; })
	     && count < 1000) {
	 count++;
	 diff(arr, n);
      }

      cout << "Case " << cn++ << ": ";      
      if (count == 1000)
	 cout << "not attained" << endl;
      else
	 cout << count << " iterations" << endl;        
   }

   

   return 0;
}
