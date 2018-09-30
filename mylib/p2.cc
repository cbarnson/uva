#include <bits/stdc++.h>
using namespace std;

// FLOODFILL
int M, N;
int X, Y;
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };

vector< vector<char> > mat;
int floodfill(int r, int c, char c1, char c2) {

   c = (c < 0) ? N - 1 : c;
   c = (c >= N) ? 0 : c;
   
   // bound check
   if (r < 0 || r >= M)
      return 0;


   // takes care of ignoring the water regions

   if (mat[r][c] != c1)

      return 0;



   int ans = 1;

   mat[r][c] = c2;

   for (int i = 0; i < 4; i++) {

      ans += floodfill(r + dr[i], c + dc[i], c1, c2);

   }

   return ans;

}

int main() {

}