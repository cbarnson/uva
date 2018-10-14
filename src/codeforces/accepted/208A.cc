// Problem #    : 208A
// Created on   : 2018-10-14 12:30:04
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

   vector<string> ans;
   size_t i;
   while ((i = s.find("WUB")) != string::npos) {
      if (i > 0)
	 ans.push_back(s.substr(0, i));
      s.erase(0, i + 3);
   }

   if (!s.empty())
      ans.push_back(s);
   
   FR(j, (int)ans.size()) {
      if (j) cout << " ";
      cout << ans[j];
   }
   cout << endl;
}
