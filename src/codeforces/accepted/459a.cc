// Problem #    : 459a
// Created on   : 2018-10-27 10:57:02
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int x1, y1, x2, y2;
   cin >> x1 >> y1 >> x2 >> y2;

   auto p = [&]() {
      cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
   };
   
   if (x1 == x2) {
      int d = abs(y2 - y1);
      x1 += d, x2 += d;
      p();
   } else if (y1 == y2) {
      int d = abs(x2 - x1);
      y1 += d, y2 += d;
      p();
   } else if (abs(x2 - x1) == abs(y2 - y1)) {
      swap(y1, y2);
      p();
   } else {
      cout << -1 << endl;
   }
   


}
