// Problem #    : 749a
// Created on   : 2018-10-26 20:24:16
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   cin >> n;

   if (n & 1) {
      int y = n / 2 - 1;
      cout << y + 1 << endl;
      FR(i, y) cout << (i ? " " : "") << 2;
      cout << " " << 3 << endl;
   } else {
      int y = n / 2;
      cout << y << endl;
      FR(i, y) cout << (i ? " " : "") << 2;
      cout << endl;
   }   
   


}
