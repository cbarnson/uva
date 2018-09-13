#include <bits/stdc++.h>
using namespace std;

int main() {

   int n, m;
   int keys[11] = { 0 };
   while (cin >> n >> m) {

      fill(keys, keys+11, 0);

      string s;
      getline(cin >> ws, s);
      stringstream ss(s);

      for (int i = 0; i < m; i++) {
	 int x; cin >> x;
	 keys[x] = 1;
      }

      int f = 0;
      for (int i = 0; i < n; i++) {
	 int x; ss >> x;
	 if (keys[x]) {
	    if (f) {
	       cout << " ";
	    }
	    f = 1;
	    cout << x;
	 }
      }
      cout << endl;
      
   }

}
