// Problem #    : 540a
// Created on   : 2018-10-21 15:49:31
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

   string a, b;
   cin >> a >> b;

   int tot = 0;
   FR(i, n) {
      int x = (int)(a[i] - '0');
      int y = (int)(b[i] - '0');
      int c = 0, d = 0, z = x;
      while (z != y) z = (z + 1) % 10, c++;
      z = x;
      while (z != y) z = (z + 10 - 1) % 10, d++;
      tot += min(c, d);
   }
   cout << tot << endl;
   


}
