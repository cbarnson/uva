#include <bits/stdc++.h>
using namespace std;

int main() {

   int n;
   string s;
   cin >> n >> s;


   string x[] = { "C?C", "Y?Y", "M?M", "??" };
   string y[] = { "CC", "YY", "MM" };
   s = "?" + s + "?";

   for (auto &i : y) {
      if (s.find(i) != string::npos) {
	 cout << "No" << endl;
	 return 0;
      }
   }

   for (auto &i : x) {
      if (s.find(i) != string::npos) {
	 cout << "Yes" << endl;
	 return 0;
      }
   }

   cout << "No" << endl;


}
