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
   vector< vector<char> > g(n, vector<char>(m, '.'));

   FR(i, n) FR(j, m) cin >> g[i][j];
   FR(i, n) {
      FR(j, m) {
	 if (g[i][j] == 'X') continue;
	 for (int dx = -1; dx <= 1; dx++) {
	    for (int dy = -1; dy <= 1; dy++) {
	       if ((!dy && !dx) || i + dx < 0 || i + dx >= n || j + dy < 0 || j + dy >= m) continue;
	       if (g[i + dx][j + dy] == 'X')
		  g[i][j] = 'R';
	    }
	 }
      }
   }

   FR(i, n) {
      FR(j, m) {
	 cout << g[i][j];
      }
      cout << endl;
   }

   

}
