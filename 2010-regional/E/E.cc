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
      vi A(n+1, 0);

      string l;
      getline(cin >> ws, l);

      stringstream ss(l);

      string s;
      while (getline(ss, s, ',')) {
	 stringstream ss2(s);
	 int x, y; char c;
	 ss2 >> x;
	 if (s.find("-") != string::npos) {
	    ss2 >> c >> y;
	    if (x > y) continue;
	    for (int i = x; i <= y; i++) {
	       if (i < n+1)
		  A[i] = 1;
	    }
	 } else {
	    if (x < n+1)
	       A[x] = 1;
	 }
      }

      cout << count(begin(A), end(A), 1) << endl;
   }

}
