// https://open.kattis.com/problems/password
// Solved 20171031
#include <bits/stdc++.h>
using namespace std;

int main() {

   vector<double> p;
   int n;
   while (cin >> n) {

      string s;
      double x, res = 0.0;
      for (int i = 1; i <= n; i++) {
	 cin >> s >> x;
	 p.push_back(x);
      }

      // descending order
      // NOTE: this was the trick of the problem, you
      // are not guaranteed descending order as you read
      // input, must do the sort
      sort(p.rbegin(), p.rend());
      for (int i = 1; i <= n; i++) {
	 res += p[i-1] * i;
      }
      cout << setprecision(4) << fixed << res << endl;
      

   }


   


   return 0;
}
