#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;

int main() {

   // ios_base::sync_with_stdio(false);
   // cin.tie(NULL);

   string s = "";
   cin >> s;

   if (s.length() < 26) {
      cout << -1 << endl;
      return 0;
   }

   vi C(26, 0);
   FR(i, 26) {
      if (s[i] != '?')
	 C[(int)(s[i] - 'A')]++;
   }


   int j = 26;
   for (j = 26; j < s.length(); j++) {
      if (count(begin(C), end(C), 1) + count(begin(s) + j - 26, begin(s) + j, '?') == 26)
	 break;

      if (s[j] != '?')
	 C[(int)(s[j] - 'A')]++;

      int k = j - 26;
      if (s[k] != '?')
	 C[(int)(s[k] - 'A')]--;
   }
   
   if ((count(begin(C), end(C), 1) + count(begin(s) + j - 26, begin(s) + j, '?')) == 26 &&
       !(count_if(begin(C), end(C), [](int x) { return x > 1; }) > 0)) {
      
      string ans = s.substr(j - 26, 26);
      
      for (int i = 0; i < ans.length(); i++) {
	 if (ans[i] == '?') {
	    for (char l : string("ABCDEFGHIJKLMNOPQRSTUVWXYZ")) {
	       if (ans.find(l) == string::npos) {
		  ans[i] = l;
		  break;
	       }
	    }
	 }
      }
      if (ans.length() == 26 && ans.find("?") == string::npos) {
	 cout << ans << endl;
	 return 0;
      }
   }

   cout << -1 << endl;
   return 0;
      
      

   
}
