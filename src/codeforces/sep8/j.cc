#include <bits/stdc++.h>
using namespace std;

int main() {

   int a, b, c, n;
   while (cin >> a >> b >> c >> n) {

      int r = c + (a - c) + (b - c);
      if (a > n || b > n || c > n || c > a || c > b ||
	  n == 0 || r >= n) {
	 cout << -1 << endl;
	 continue;
      }

      int f = n - r;
      cout << f << endl;
   }

}
