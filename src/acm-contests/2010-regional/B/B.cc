#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   while (cin >> n && n) {

      vi P(n);
      for (auto &x : P) cin >> x;

      int s = 0, mx = -1;
      for (auto &x : P) s += x, mx = max(mx, x);

      for (auto &i : {50, 60, 70}) {
	 if (2*s > i) cout << 0;
	 else cout << (i / mx) + 1;	    	 
	 if (i == 70) cout << endl;
	 else cout << " ";
      }
   }

}
