// Problem #    : 131A
// Created on   : 2018-10-14 10:04:26
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   string s;
   cin >> s;
   if ((islower(s[0]) && all_of(s.begin() + 1, s.end(), [] (char c) { return isupper(c); })) || (
	  all_of(s.begin(), s.end(), [] (char c) { return isupper(c); }))) {

      for (auto &x : s) {
	 x = (islower(x) ? toupper(x) : tolower(x));
      }
      cout << s << endl;
      return 0;
      
   }

   cout << s << endl;
   


}
