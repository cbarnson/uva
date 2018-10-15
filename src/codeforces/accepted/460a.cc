// Problem #    : 460a
// Created on   : 2018-10-14 16:44:30
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   
   int n, m, d = 1;
   cin >> n >> m;
   int s = n;
   while (s > 0) {
      s--;
      if (d % m == 0) s++;
      d++;
   }
   cout << d-1 << endl;


}
