// Problem #    : f
// Created on   : 2018-10-20 14:59:32
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   
   // cout << setw(3) << setfill('.') << 10 << endl;
   int n, m;
   cin >> n >> m;
   vector<string> A;
   FR(i, n) { string s; cin >> s; A.push_back(s); }

   vector<vi> B(n, vi(m, 0));

   int mx = 0;
   FR(l, 100) {
      FR(i, n) {
	 FR(j, m) {

	    if (A[i][j] != 'T') continue;

	    // bound
	    if (i == 0 || i == n-1 || j == 0 || j == m-1) {
	       B[i][j] = 1;
	       mx = max(mx, 1);
	    } else {

	       int dx[] = { -1, 0, 1, 0 };
	       int dy[] = { 0, -1, 0, 1 };

	       int mi = 0x3f3f3f3f;
	       FR(k, 4) {
		  int x = i + dx[k], y = j + dy[k];
		  mi = min(mi, B[x][y]);
	       }
	    
	       // assert(mi != 0x3f3f3f3f);

	       B[i][j] = mi + 1;
	       mx = max(mx, mi + 1);
	    }
	 
	 }
      }
   }

   int fl = (mx < 10 ? 2 : 3);
   FR(i, n) {
      FR(j, m) {

	 if (B[i][j] == 0) {
	    cout << setw(fl) << setfill('.') << ".";
	 } else {
	    cout << setw(fl) << setfill('.') << B[i][j];
	 }
      }
      cout << endl;
   }
   

}
