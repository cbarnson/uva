#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

vector<int> v[401];
ll dp[401];        // dp[i] is number of ways to get favourable from i

ll rec(int k) {
   
   if (dp[k] != -1) 
      return dp[k];
   
   ll total = 0;
   for (int i = 0; i < v[k].size(); i++) {
      total += rec(v[k][i]);
   }
   // update
   dp[k] = total;
   // cout << "dp[" << k << "]: " << dp[k] << endl;
   return dp[k];
   
}

int main() {


   int cn;
   cin >> cn;
   while (cn--) {

      for (int i = 0; i < 401; i++) {
	 v[i].clear();
      }
      fill(dp, dp+401, -1);
      // fill(soln, soln+401, false);
      
      int n;
      cin >> n >> ws;

      // queue<int> q;
      
      for (int i = 0; i < n; i++) {
	 int pg;
	 cin >> pg >> ws;
	 char c = cin.peek();
	 if (isdigit(c)) {
	    int a, b, c;
	    cin >> a >> b >> c;
	    // v[a].push_back(pg);
	    // v[b].push_back(pg);
	    // v[c].push_back(pg);
	    v[pg].push_back(a);
	    v[pg].push_back(b);
	    v[pg].push_back(c);
	 } else {
	    string s;
	    cin >> s;
	    if (s == "favourably") {
	       dp[pg] = 1;
	    } else {
	       dp[pg] = 0;
	    }
	 }
      }

      cout << rec(1) << endl;
   }
   


   return 0;
}
