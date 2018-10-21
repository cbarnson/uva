// Problem #    : 732a
// Created on   : 2018-10-21 09:30:47
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int k, r;
   cin >> k >> r;
   
   int mi = 0x3f3f3f3f;

   int x = k % 10;
   int y = x, cnt = 1;
   while (!(x == 0 || x == r)) {
      x = (x + y) % 10, cnt++;
   }

   cout << cnt << endl;
   

}
