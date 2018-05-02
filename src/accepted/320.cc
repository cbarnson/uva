#include <iostream>
using namespace std;

char grid[32][32];

void init() {
   for (int i = 0; i < 32; i++) {
      for (int j = 0; j < 32; j++) {
	 grid[i][j] = '.';
      }
   }
}

void move (int& x, int& y, char c) {
   if (c == 'N') {
      //grid[x+1][y+1] = 'X';
      grid[x][y] = 'X';
      y += 1;
   } else if (c == 'E') {
      grid[x][y-1] = 'X';
      //grid[x+1][y] = 'X';
      x += 1;
   } else if (c == 'S') {
      grid[x-1][y-1] = 'X';
      //grid[x][y] = 'X';
      y -= 1;
   } else if (c == 'W') {
      grid[x-1][y] = 'X';
      //grid[x][y+1] = 'X';
      x -= 1;
   }
}

void solve () {

   int x, y;
   cin >> x >> y;

   char c;
   cin >> c;
   while (c != '.') {

      move(x, y, c);

      cin >> c;
   }

}

void printGrid() {
   for (int i = 31; i >= 0; i--) {
      for (int j = 0; j < 32; j++) {
	 cout << grid[j][i];
      }
      cout << endl;
   }
   cout << endl;
}

int main () {

   int N; cin >> N;
   int num = 1;

   while (N--) {
      init();
      printf("Bitmap #%d\n", num++);
      solve();
      printGrid();
      //if (N != 0) { cout << endl; }
   }

}
