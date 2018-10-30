// Cody Barnson
// 5738 - Robot navigation
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int NN = 1000;
const int MM = 1000;
const string direction = "NESW";
const int CC = 3;
const int choices[CC] = { 1000, 1000, 4 }; // row, col, direction
const int di[4] = { -1, 0, 1, 0 };
const int dj[4] = { 0, 1, 0, -1 };

void toa(int arr[CC], int x) {
   for (int i = 0; i < CC; i++) {
      int div = 1;
      for (int j = 0; j < i; j++)
	 div *= choices[j];
      int quot = x / div;
      arr[i] = quot % choices[i];
   }
}

int toi(int arr[CC]) {
   int x = arr[0];
   for (int i = 1; i < CC; i++) {
      int temp = arr[i];
      for (int j = i-1; j >= 0; j--) 
	 temp *= choices[j];
      x += temp;
   }
   return x;
}

bool solution(int x, int target_r, int target_c) {
   int temp[CC];
   toa(temp, x);
   return (temp[0] == target_r && temp[1] == target_c);
}

// conditional add if either (1) the potential child state has not been seen,
// or (2) the potential child state has been seen AND the depth of the potential
// child state is equal to the depth of the parent state + 1
void add_state(queue<int>& q, int parent, int child, int *depth, int *seen) {
   if (seen[child] == 0 || (seen[child] > 0 && (depth[child] == (depth[parent] + 1)))) {
      q.push(child);
      depth[child] = depth[parent] + 1;
   }
}

void expand(queue<int>& q, int x, int grid_r, int grid_c,
	    char grid[NN][MM], int *depth, int *seen) {
   int temp[CC];
   toa(temp, x);
   int tt[CC];
   // int val;
   tt[0] = temp[0] + di[temp[2]];
   tt[1] = temp[1] + dj[temp[2]];
   tt[2] = temp[2];
   if (tt[0] >= 0 && tt[0] < grid_r &&  // in row bounds
       tt[1] >= 0 && tt[1] < grid_c &&  // in col bounds
       grid[tt[0]][tt[1]] != '*') {     // space not blocked
      add_state(q, x, toi(tt), depth, seen);
   }
   copy(temp, temp+CC, tt);
   tt[2] = (temp[2] + 1) % 4;     // turn "right"
   add_state(q, x, toi(tt), depth, seen);

   tt[2] = (temp[2] + 4 - 1) % 4; // turn "left"
   add_state(q, x, toi(tt), depth, seen);
}


int main() {

   int cn = 1;
   int n, m, mod;  
   while (cin >> n >> m >> mod && !(n == 0 && m == 0 && mod == 0)) {
      cout << "Case " << cn++ << ": ";
      char grid[NN][MM];
      for (int i = 0; i < n; i++) {
	 for (int j = 0; j < m; j++) {
	    cin >> grid[i][j];
	 }
      }

      int sr, sc, sd; // source row, col, direction
      int dr, dc;     // destination row, col
      char sdir;
      cin >> sr >> sc >> dr >> dc >> sdir;
      size_t dir = direction.find(sdir);
      if (dir != string::npos)
	 sd = dir;

      // dynamic because stack
      int *depth = new int[4000000];
      int *seen = new int[4000000];
      fill(seen, seen+4000000, 0);

      int temp[CC] = { sr, sc, sd };
      int curr = toi(temp);
      
      depth[curr] = 0;
      queue<int> q;
      q.push(curr);

      ll soln_count = 0;
      ll soln_depth = numeric_limits<ll>::max();

      // BFS
      while (!q.empty()) {
	 curr = q.front();
	 q.pop();

	 // mark as seen
	 seen[curr]++;

	 // if this state is a solution, and its depth is less than or equal
	 // to the last solution, increment our solution counter, update
	 // the last solution depth
	 if (solution(curr, dr, dc)) {	    
	    if (depth[curr] <= soln_depth) {
	       soln_count++;
	       soln_depth = depth[curr];
	    }
	 }
	 // add moves
	 expand(q, curr, n, m, grid, depth, seen);	 
      }

      cout << mod << " ";
      if (soln_count == 0)
	 cout << -1 << endl;
      else
	 cout << soln_count % mod << endl;

      delete[] depth;
      delete[] seen;
   }
   


   return 0;
}
