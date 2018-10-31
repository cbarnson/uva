// Problem #    : 556
// Created on   : 2018-10-30 19:49:26
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m && (n && m)) {
     vector<vi> A(n+2, vi(m+2, 1));
     for (int i = 1; i <= n; i++) {
	for (int j = 1; j <= m; j++) {
	   char c; cin >> c;
	   if (c == '0') A[i][j] = 0;
	}
     }

     vector<vi> B(n+2, vi(m+2, 0));
     int sx = B.size() - 2, sy = 1;

     int dx[] = { 0, -1, 0, 1 }, dy[] = { 1, 0, -1, 0 };
     int dir = 0;
     int x = sx, y = sy;

     auto IB = [&](int i, int j) {
	return A[i][j] == 0;
     };
     
     auto WR = [&](int i, int j) {
	int dr = (dir + 4 - 1) % 4;
	int di = i + dx[dr], dj = j + dy[dr];
	return !IB(di, dj);
     };
     
     do {

	// if has wall on right;
	if (WR(x, y)) {
	   int di = x + dx[dir], dj = y + dy[dir];
	   if (IB(di, dj)) {
	      // -- if can move forward, move, incr B, continue
	      x = di, y = dj;
	      B[x][y]++;
	   } else {
	      // -- else if can not move forward, turn left, continue
	      dir = (dir + 1) % 4;
	   }
	   continue;
	}

	// if no wall on right, turn right, move forward, incr B, continue
	dir = (dir + 4 - 1) % 4;
	int di = x + dx[dir], dj = y + dy[dir];
	assert(IB(di, dj));
	x = di, y = dj;
	B[x][y]++;

     } while (!(x == sx && y == sy));

     int cnt[5] = {};
     FR(i, n+2) FR(j, m+2) if (A[i][j] == 0 && B[i][j] < 5) cnt[B[i][j]]++;

     FR(i, 5) {
	cout << setw(3) << cnt[i];
     }
     cout << endl;
	   
     
     // cout << "done" << endl;
  }

  
  
}
