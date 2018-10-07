#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

string decode(string &s) {
   string ans = "";
   for (int i = 1; i < (int)s.length(); i++) {
      int len = (int)(s[i] - '0');
      for (int j = 0; j < len; j++) {
	 ans += s[i-1];
      }
      i += 1;
   }
   return ans;
}

string encode(string &s) {
   string ans = "";
   for (int i = 0; i < (int)s.length(); i++) {
      int cnt = 1;
      for (int j = i + 1; j < (int)s.length(); j++) {
	 if (s[j] == s[i]) cnt++;
	 else break;
      }
      i += (cnt - 1);
      
      ans += s[i];
      ans += (char)(cnt + '0');
   }
   return ans;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   char ed;
   string s;

   cin >> ed >> s;
   if (ed == 'E') {
      cout << encode(s) << endl;
   } else {
      cout << decode(s) << endl;
   }
   

}
