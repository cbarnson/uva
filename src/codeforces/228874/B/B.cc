#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int di[] = { -1, 0, 1, 0 }, dj[] = { 0, 1, 0, -1 };

bool s(vector<vector<char> > &g, int R, int C) {
   FR(i, R) {
      FR(j, C) {
	 if (g[i][j] == 'S') {
	    FR(k, 4) {
	       int x = i + di[k], y = j + dj[k];
	       if (x >= 0 && x < R && y >= 0 && y < C) {
		  if (g[x][y] == 'W')
		     return false;
		  else if (g[x][y] == '.')
		     g[x][y] = 'D';
	       }
	    }
	 }
      }	  
   }
   return true;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int R, C;
   cin >> R >> C;
   vector<vector<char> > g(R, vector<char>(C));
   FR(i, R) {
      FR(j, C) {
	 cin >> g[i][j];
      }
   }

   if (s(g, R, C)) {
      cout << "Yes" << endl;
      FR(i, R) {
	 FR(j, C) {
	    cout << g[i][j];
	 }
	 cout << endl;
      }
      return 0;
   }

   cout << "No" << endl;

}


