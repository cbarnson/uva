#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(0);

   string s;
   cin >> s;

   reverse(begin(s), end(s));
   string ans = "";
   FR(i, s.size()) {
      ans += string(3, s[i]);
   }

   if (ans == "")
      ans = "LLLL";
   cout << ans << endl;

   
   // int i = 0;

   // string ans = "";
   // int n = s.size();
   // for (int i = 0; i < n; i++) {
      
   //    // int j = upper_bound(s.begin() + i, s.end(), s[i]) - s.begin();
   //    int j = i;
   //    for (j = i; j < n; j++) {
   // 	 if (s[j] != s[i])
   // 	    break;
   //    }      
      
   //    if (i == j) break;
      
   //    int x = 4 - ((j - i) % 4);
   //    ans += string(x, s[i]);            
   // }
     

  

   

}
