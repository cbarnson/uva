#include <bits/stdc++.h>
using namespace std;

typedef map<char, int> Map;

int main() {

   int t; cin >> t;
   while (t--) {

      int k; cin >> k;
      Map m;
      while (k--) {
	 char c; int v;
	 cin.get(c);
	 cin.get(c);
	 cin >> v;
	 m[c] = v;
      }

      int l; cin >> l; // lines, '\n' characters we will see
      int total_cents = 0;

      cin.ignore();
      for (int i = 0; i < l; i++) {
	 string str;
	 getline(cin, str);
	 for (auto it = str.begin(); it != str.end(); ++it) {

	    char c = *it;
	    total_cents += m[c];
	 }
      }
      double ans = (double)total_cents / 100;
      cout << setprecision(2) << fixed << ans << "$" << endl;
      
   }

   return 0;
}
