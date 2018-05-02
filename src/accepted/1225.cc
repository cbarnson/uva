// UVA 1225 Digit Counting
// Brute force math problem
// Accepted
#include <bits/stdc++.h>
using namespace std;

int main() {


   int n;
   cin >> n;

   for (int i = 0; i < n; i++) {

      int num;
      cin >> num;

      string s = "";      
      for (int j = 1; j <= num; j++) {
	 s += to_string(j);
      }

      for (int j = 0; j <= 9; j++) {
	 if (j)
	    cout << " ";
	 char c = '0' + j;
	 cout << count(s.begin(), s.end(), c);
      }
      cout << endl;
      



   }
   


   return 0;
}
