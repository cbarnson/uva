#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int minimax(int r, int c, int x, int tl, int br, int t) {


   if (!r || !c) return x;
   
   if (t) {
      int mx;
      for (int i = 1; i <= c; i++) {
	 int z = minimax(r, c-i, ((r & 1) && (i & 1)) ? x + (tl ? 1 : -1) : x, (i & 1 ? !tl : tl), br, !t);	 
	 mx = (i == 1) ? z : max(mx, z);
      }
      return mx;
   }

   int mi;
   for (int i = 1; i <= r; i++) {
      int z = minimax(r-i, c, ((c & 1) && (i & 1)) ? x + (br ? -1 : 1) : x, tl, (i & 1 ? !br : br), !t);
      mi = (i == 1) ? z : min(mi, z);
   }
   return mi;

   
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, m;
   cin >> n >> m;
   cout << minimax(n, m, 0, 1, ((n+m) & 1 ? 0 : 1), 1) << endl;

}
   
