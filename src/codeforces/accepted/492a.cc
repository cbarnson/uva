// Problem #    : 492a
// Created on   : 2018-10-21 09:52:19
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   auto s = [&](int n) {
      return n * (n + 1) / 2;
   };

   int n;
   cin >> n;

   int h = 1;
   while (n > 0) {
      n -= s(h);
      if (n < 0) break;
      h++;
   }

   cout << h - 1 << endl;
   


}
