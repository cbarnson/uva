#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   
   int n, k;
   set<int> s;

   cin >> n >> k;
   vi ans;

   for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (s.insert(x).second) {
	 ans.push_back(i+1);
      }
   }

   if (ans.size() >= k) {
      cout << "YES" << endl;
      for (int i = 0; i < min(k, (int)ans.size()); i++) {
	 cout << ans[i] << " ";	 
      }
      cout << endl;
   } else
      cout << "NO" << endl;


}


