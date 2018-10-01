#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   // ios_base::sync_with_stdio(false);
   // cin.tie(NULL);

   int t, n, k;
   cin >> t;
   while (t--) {

      cin >> n >> k;
      string s, t;
      s = string(n, '0');
      FR(i, k) {
	 int x; cin >> x;
	 s[x-1] = '1';
      }

      regex r("([0])([1])");

      while (1) {
	 t = regex_replace(s, r, "$2");
	 cout << t << endl;
	 if ((int)t.length() < 1) break;
	 s = t;
      }
   }

}


