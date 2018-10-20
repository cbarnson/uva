#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

ii dp[101][101][2][2][2];

int minimax(int r, int c, int x, int tl, int br, int t) {

   if (!r || !c) return x;

   auto y = dp[r][c][tl][br][t];
   if (y.first) return y.second + x;
   
   if (t) {      
      int mx;
      for (int i = 1; i <= c; i++) {
	 int z = minimax(r, c-i, ((r & 1) && (i & 1)) ? (tl ? 1 : -1) : 0, (i & 1 ? !tl : tl), br, !t);
	 mx = (i == 1) ? z : max(mx, z);
      }
      dp[r][c][tl][br][t] = ii(1, mx);
      return mx + x;
   }

   int mi;
   for (int i = 1; i <= r; i++) {
      int z = minimax(r-i, c, ((c & 1) && (i & 1)) ? (br ? -1 : 1) : 0, tl, (i & 1 ? !br : br), !t);
      mi = (i == 1) ? z : min(mi, z);
   }
   dp[r][c][tl][br][t] = ii(1, mi);
   return mi + x;

   
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   FR(i, 101) FR(j, 101) FR(tl, 2) FR(br, 2) FR(t, 2) dp[i][j][tl][br][t] = ii(0, 0);
   
   int n, m;
   cin >> n >> m;
   cout << minimax(n, m, 0, 1, ((n+m) & 1 ? 0 : 1), 1) << endl;

}
   
