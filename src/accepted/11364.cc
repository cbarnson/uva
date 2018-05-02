#include <bits/stdc++.h>
using namespace std;

int main() {
   int t; cin >> t;
   while (t--) {
      int n; cin >> n;
      int p[20];
      for (int i = 0; i < n; i++) {
	 cin >> p[i];
      }

      int min=99, max=0;
      for (int i = 0; i < n; i++) {
	 if (p[i] > max) max = p[i];
	 if (p[i] < min) min = p[i];
      }

      //cout << "max: " << max << " ---- min: " << min << endl;
      cout << 2*(max-min) << endl;
   }


   return 0;
}
