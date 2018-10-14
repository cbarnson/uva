// Problem #    : 59A
// Created on   : 2018-10-14 13:27:29
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

   int hi = count_if(begin(s), end(s), [](char c) { return isupper(c); });
   if (hi <= ((int)s.length() - hi)) {
      // all lower
      transform(begin(s), end(s), begin(s), ::tolower);
      cout << s << endl;
      return 0;
   }

   transform(begin(s), end(s), begin(s), ::toupper);
   cout << s << endl;
   


}
