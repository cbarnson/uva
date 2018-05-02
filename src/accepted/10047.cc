// Cody Barnson
// uva 10047
#include <bits/stdc++.h>
using namespace std;

// max rows and cols, start i j, target i j
int m, n, si, sj, ti, tj;

// board
char b[25][25];

// # of choices for each property
// rowIndex, colIndex, direction, colorWheel
int p[4] = { 25, 25, 4, 5 };

// given direction d = 0, 1, 2, 3 (N, E, S, W)
// di and dj give the change in i, j for that
// direction
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

// map x onto array
void toa(int a[4], int x) {
   for (int i = 0; i < 4; ++i) {
      int divisor = 1;
      for (int j = 0; j < i; ++j) 
	 divisor *= p[j];      
      int quotient = x / divisor;
      a[i] = quotient % p[i];
   }
}

// given array representing state, map the elements onto a
// single integer and return it
int toi(int a[4]) {
   int x = a[0];
   for (int i = 1; i < 4; ++i) {
      int tt = a[i];
      for (int j = i-1; j >= 0; --j) 
	 tt *= p[j];      
      x += tt;
   }
   return x;
}

// true if x represents a state at the target coordinates
// and has the '0' face value (i.e. "green" as per problem details)
bool isSoln(int x) {
   int a[4];
   toa(a, x);
   return (a[0] == ti && a[1] == tj && a[3] == 0);
}

// True if given state may move 'forward' (relative to current direction)
// to an unblocked and in-bound square.  If true, x is modified to
// reflect the new state
bool move(int& x) {
   int a[4];
   toa(a, x);
   int i = a[0] + di[a[2]];
   int j = a[1] + dj[a[2]];
   // bound check
   if (j < 0 || i < 0 || j >= n || i >= m || b[i][j] == '#') return false;
   // inbound, update coordinates and color face
   a[0] = i;
   a[1] = j;
   a[3] = (a[3] + 1) % 5;
   x = toi(a);
   return true;
}

// modify the value of x to reflect the new state after the specified
// rotation direction
void rotate(bool right, int& x) {
   int a[4];
   toa(a, x);
   if (right) {
      a[2] = (a[2] + 1) % 4;
   } else {
      a[2]--;
      if (a[2] < 0) a[2] = 3;
   }
   x = toi(a);
}

int main() {

   // case number
   int cn = 0;
   
   while (cin >> m >> n && m != 0 && n != 0) {
      if (cn++) cout << endl;
      cout << "Case #" << cn << endl;
      // read in board
      for (int i = 0; i < m; ++i) {
	 for (int j = 0; j < n; ++j) {
	    char c;
	    cin >> c;
	    if (c == 'S') {
	       si = i; sj = j;
	    } else if (c == 'T') {
	       ti = i; tj = j;
	    }
	    b[i][j] = c;
	 }
      }

      int tt[] = { si, sj, 0, 0 };
      int c = toi(tt);
      
      // 25 * 25 * 4 * 5 = 12500 possible states,
      // represented by the index
      int time[12500];
      bool seen[12500];
      fill(seen, seen+12500, false);
      
      time[c] = 0;
      queue<int> q;
      q.push(c);

      // BFS
      // if front element has been seen, pop and continue to the next
      // element; else mark as seen, check if solution, then compute
      // and push child states (move forward, rotate left, rotate right)
      while (!q.empty()) {
	 c = q.front();
	 q.pop();
	 if (seen[c]) continue;
	 seen[c] = true;
	 if (isSoln(c)) goto solved;
	 int tt = c;
	 if (move(tt)) {
	    time[tt] = time[c] + 1;
	    q.push(tt);
	 }
	 // Turn 'left'
	 tt = c;
	 rotate(false, tt);
	 time[tt] = time[c] + 1;
	 q.push(tt);
	 // Turn 'right'
	 tt = c;
	 rotate(true, tt);
	 time[tt] = time[c] + 1;
	 q.push(tt);
      }

      // no solution
      cout << "destination not reachable" << endl;
      continue;
     solved:
      // solution exists, stored in c
      cout << "minimum time = " << time[c] << " sec" << endl;
   }


   return 0;
}
