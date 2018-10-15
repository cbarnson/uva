// Problem #    : 677A
// Created on   : 2018-10-14 15:43:46
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, h;
   cin >> n >> h;

   vi A(n);
   int cnt = 0;
   for (auto &x : A) {
      cin >> x;
      if (x > h) cnt++;
      cnt++;
   }

   cout << cnt << endl;
   


}
