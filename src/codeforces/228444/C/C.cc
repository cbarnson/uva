#include <bits/stdc++.h>
using namespace std;

int main() {

   string s;
   cin >>s;
   if (s.length() < 3) {
      cout << "No";
   } else {

      int a[101] = { 0 };
      for (int i = 0; i < s.length(); i++) {
	 if (s[i] == 'A')
	    a[i] = 1;
	 else if (s[i] == 'B')
	    a[i] = 2;
	 else if (s[i] == 'C')
	    a[i] = 4;
      }

      int f = false;
      for (int i = 1; i < s.length() - 1; i++) {
	 if (a[i-1] + a[i] + a[i+1] == 7) {
	    cout << "Yes";
	    f = true;
	    break;
	 }
      }
      if (!f)
	 cout << "No";
   }
   cout << endl;


}
