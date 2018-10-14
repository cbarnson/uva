// Problem #    : 467A
// Created on   : 2018-10-14 10:58:54
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, p, q, c = 0;

   cin >> n;
   FR(i, n) {
      cin >> p >> q;
      if (q - p > 1) c++;
   }
   cout << c << endl;
   


}
