#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 400 * 400;
const int DISCONNECT = -1;


typedef pair<int, int> ii;
typedef vector<ii> vii;

int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };


/* assume that D and P have been allocated */
void dijkstra(int graph[MAX_NODES][MAX_NODES], int n, int src, int D[], 
	      int P[])
{
   char used[MAX_NODES];
   int fringe[MAX_NODES];
   int f_size;
   int v, w, j, wj;
   int best, best_init;

   f_size = 0;
   for (v = 0; v < n; v++) {
      if (graph[src][v] != DISCONNECT && src != v) {
	 D[v] = graph[src][v];
	 P[v] = src;
	 fringe[f_size++] = v;
	 used[v] = 1;
      } else {
	 D[v] = DISCONNECT;
	 P[v] = -1;
	 used[v] = 0;
      }
   }
   D[src] = 0;
   P[src] = -1;
   used[src] = 1;

   best_init = 1;
   while (best_init) {
      /* find unused vertex with smallest D */
      best_init = 0;
      for (j = 0; j < f_size; j++) {
	 v = fringe[j];
	 assert(D[v] != DISCONNECT);
	 if (!best_init || D[v] < best) {
	    best = D[v];
	    w = v;
	    wj = j;
	    best_init = 1;
	 }
      }

      if (best_init) {
	 assert(D[w] != DISCONNECT);
	 assert(fringe[wj] == w);

	 /* get rid of w from fringe */
	 f_size--;
	 for (j = wj; j < f_size; j++) {
	    fringe[j] = fringe[j+1];
	 }

	 /* update distances and add new vertices to fringe */
	 for (v = 0; v < n; v++) {
	    if (v != src && graph[w][v] != DISCONNECT) {
	       if (D[v] == DISCONNECT || D[w] + graph[w][v] < D[v]) {
		  D[v] = D[w] + graph[w][v];
		  P[v] = w;
	       } else if (D[w] + graph[w][v] == D[v]) {
		  /* put tie-breaker here */
	       }
	       if (!used[v]) {
		  used[v] = 1;
		  fringe[f_size++] = v;
	       }
	    }
	 }
      }
   }
   D[src] = 0;
}

int get_path(int v, int P[], int path[])
{
   int A[MAX_NODES];
   int i, k;

   k = 0;
   A[k++] = v;
   while (P[v] != -1) {
      v = P[v];
      A[k++] = v;
   }
   for (i = k-1; i >= 0; i--) {
      path[k-1-i] = A[i];
   }
   return k;
}



// map to base 400 integer
int toi(ii coord) {
   int x = coord.first;
   int tt = coord.second;
   tt *= 400;
   x += tt;
   return x;
}

ii top(int x) {

   ii val;
   

   val.first = x % 400;

   return val;
}

int main()
{
   cout << "start" << endl;
   
   int r = 2, c = 3;
   ii val;
   val.first = r;
   val.second = c;
   int x = toi(val);
   cout << "r: " << r << ", c: " << c << ", ii.first: " << val.first
	<< ", ii.second: " << val.second << endl;

   cout << "x: " << x << endl;
   
   return 0;
   
   int m, w, num;
   int graph[MAX_NODES][MAX_NODES];
   int P[MAX_NODES][MAX_NODES], D[MAX_NODES][MAX_NODES];
   int path[MAX_NODES];

   /* clear graph */
   for (int i = 0; i < MAX_NODES; i++) {
      for (int j = 0; j < MAX_NODES; j++) {
	 graph[i][j] = DISCONNECT;
      }
   }

   // read in board
   int rows, cols;
   cin >> rows >> cols;

   char board[400][400];
   for (int i = 0; i < 400; i++) {
      fill(board[i], board[i]+400, '#');
   }

   // vector of pairs (coordinates) for potential destinations (outer doors)
   vii dest;

   // read in char by char, mark outer doors as destinations by adding
   // pair to "dest"
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
	 char c;
	 cin >> c;
	 if (c == 'D' && (i == 0 || j == 0 || i == rows-1 || j == cols-1)) 
	    dest.push_back(ii(i, j));	 
	 board[i][j] = c;
      }
   }

   // get target car to move out
   int target_r, target_c;
   cin >> target_r >> target_c;

   // from target, add edges to graph
   queue<ii> q;
   q.push(ii(target_r, target_c));

   // loop through to build graph
   while (!q.empty()) {
      ii curr = q.front();
      q.pop();

      // check each adjacent square
      for (int i = 0; i < 4; i++) {
	 int r = curr.first + di[i];
	 int c = curr.second + dj[i];
	 if (board[r][c] == 'c') {

	    // add edge
	    // graph[curr.first][curr.second] = graph[
	    
	 } else if (board[r][c] == 'D') {
	    
	 }
      }
      
      
   }

   
   
   /* read graph */
   // cin >> i >> j >> w;
   // while (!(i == -1 && j == -1)) {
   //    assert(0 <= i && i < MAX_NODES && 0 <= j && j < MAX_NODES);
   //    graph[i][j] = graph[j][i] = w;
   //    cin >> i >> j >> w;
   // }

   // for (i = 0; i < MAX_NODES; i++) {
   //    dijkstra(graph, MAX_NODES, i, D[i], P[i]);
   // }

   /* do queries */
   // cin >> i >> j;
   // while (!(i == -1 && j == -1)) {
   //    assert(0 <= i && i < MAX_NODES && 0 <= j && j < MAX_NODES);
   //    cout << i << " " << j << ": " << D[i][j] << endl;
   //    for (m = j; m != -1; m = P[i][m]) {
   // 	 cout << " " << m;
   //    }
   //    cout << endl;
   //    num = get_path(j, P[i], path);
   //    for (m = 0; m < num; m++) {
   // 	 cout << " " << path[m];
   //    }
   //    cout << endl;
   //    cin >> i >> j;
   // }

   return 0;
}

