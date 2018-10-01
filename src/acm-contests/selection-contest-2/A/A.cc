#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, m;
   cin >> n >> m;

   vector< vector<char> > g(n+1, vector<char>(m+1, '.'));

   int k = 0;
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
	 if (i & 1) {
	    cout << "#";
	    continue;
	 }

	 if ((k == 0 && j == m) || (k == 1 && j == 1)) {
	    cout << "#";
	 } else {
	    cout << ".";
	 }
      }
      if (i % 2 == 0) k = !k;
      cout << endl;
   }



}
