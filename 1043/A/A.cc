// Problem #    : t
// Created on   : 2018-10-28 09:37:39
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
   vi A(n);
   for (auto &x : A) cin >> x;

   int mx = *max_element(begin(A), end(A));

   int s = accumulate(begin(A), end(A), 0);
   int x = mx * n - s;

   int y = mx;
   while (x <= s) {
      y++;
      x += n;
   }

   cout << y << endl;
   


}
