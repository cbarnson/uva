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

   vector<ii> B;
   vector< vector<char> > g(n, vector<char>(m, ' '));
   FR(i, n) FR(j, m) {
      cin >> g[i][j];
      if (g[i][j] == '*')
	 B.push_back(ii(i, j));
   }

   vector<vi> A(n, vi(m, 0));
   for (auto &b : B) {
      int x = b.first, y = b.second;
      for (int i = -1; i <= 1; i++) {
	 for (int j = -1; j <= 1; j++) {
	    int dx = x + i, dy = y + j;
	    if (dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
	    A[dx][dy]++;
	 }	       
      }
   }

   FR(i, n) {
      FR(j, m) {
	 if (g[i][j] == '*') continue;
	 int p;
	 if (g[i][j] == '.') p = 0;
	 else p = (int)(g[i][j] - '0');

	 int q = A[i][j];
	 if (p != q) {
	    cout << "NO" << endl;
	    return 0;
	 }
      }
   }

   cout << "YES" << endl;
   


}
