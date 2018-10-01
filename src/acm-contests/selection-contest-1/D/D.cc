#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

string s = "";

bool nice(int i) {
   vi A(26, 0);
   for (int j = i; j < i + 26; j++)
      if (s[j] != '?' && A[(int)(s[j] - 'A')]++ > 0)
	 return false;
   return true;
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> s;
   for (int i = 0; i <= (int)s.length() - 26; i++) {
      if (nice(i)) {

	 string rg = string(s.begin() + i, s.begin() + i + 26);
	 vector<char> C;
	 FR(k, 26)
	    if (rg.find(k + 'A') == string::npos) C.push_back(k + 'A');
	 
	 for (int j = i, k = 0; j < i + 26; j++)
	    if (s[j] == '?') s[j] = C[k++];

	 transform(s.begin(), s.end(), s.begin(), [](char c) { return (c == '?' ? 'A' : c); });
	 cout << s << endl;	 
	 return 0;
      }
   }

   cout << -1 << endl;
      
      

}
