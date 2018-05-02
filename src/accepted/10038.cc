#include <bits/stdc++.h>
using namespace std;

int main() {

   // n > 0, jolly
   // single int, jolly
   int n;
   int arr[3000];   
   int diff[3000];
   while (cin >> n) {
      if (n == 1) {
	 int temp; cin >> temp;
	 cout << "Jolly" << endl;
	 continue;
      }
      for (int i = 0; i < n; i++) {
	 cin >> arr[i];
      }
      adjacent_difference(arr, arr+n, diff,
			  [] (int x, int y) { return abs(x-y); });
      bool jolly = true;
      int x = n-1;
      for (int i = 1; i < n; i++) {
	 // cout << "diff i: " << diff[i] << endl;
	 // cout << "x: " << x << endl;
	 if (diff[i] != x--) {
	    jolly = false;
	    break;
	 }
      }
      if (jolly) {
	 cout << "Jolly" << endl;
      } else {
	 cout << "Not jolly" << endl;
      }
      
   }

   return 0;
}
