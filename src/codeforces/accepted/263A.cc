// Problem #    : 263A
// Created on   : 2018-10-01 14:08:50
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   vector<vi> g(5, vi(5, 0));
   int x, y;
   FR(i, 5) FR(j, 5) {
     cin >> g[i][j];
     if (g[i][j] == 1) {
       x = i, y = j;
     }
   }

   cout << abs(2 - x) + abs(2 - y) << endl;
   


}
