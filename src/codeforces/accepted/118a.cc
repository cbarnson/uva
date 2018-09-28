// Problem #    : 118a
// Created on   : 2018-09-27 22:55:09
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   string s = "";
   cin >> s;

   transform(begin(s), end(s), begin(s), ::tolower);
   string ans = "";
   for (auto c : s) {
      if (string("aoyeui").find(c) == string::npos)
	 ans += string(".") + c;
   }

   cout << ans << endl;
      


}
