// Problem #    : 148A
// Created on   : 2018-10-14 11:58:05
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int k, l, m, n, d;
   cin >> k >> l >> m >> n >> d;
   
   vi A(d+1, 0);
   vi B = { k, l, m, n };
   for (auto &x : B) {
      int y = x;
      while (y <= d) {
	 A[y] = 1;
	 y += x;
      }
   }

   int s = count(begin(A) + 1, end(A), 1);
   cout << s << endl;
   


}
