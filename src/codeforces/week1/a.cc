#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

   int n;
   while (cin >> n) {


      set<int> s;
      for (int i = 0; i < n; i++) {
	 int x;
	 cin >> x;
	 if (s.count(x) == 0 && x) {
	    s.insert(x);
	 }
      }

      int ans = s.size();
      cout << ans << endl;

   }

}
