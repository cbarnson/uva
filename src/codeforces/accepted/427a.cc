// Problem #    : 427a
// Created on   : 2018-10-21 13:51:43
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

   vi A(n); for (auto &x : A) cin >> x;

   int x = 0, cnt = 0;
   FR(i, n) {
      if (A[i] == -1 && !x) {
	 cnt++;
	 continue;
      }
      x += A[i];
   }
   cout << cnt << endl;
   

}
