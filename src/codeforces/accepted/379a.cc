// Problem #    : 379a
// Created on   : 2018-10-14 17:28:31
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   
   int a, b;
   cin >> a >> b;

   int c = a;
   while (1) {
      c += a / b;
      a = a / b + a % b;
      if (a < b) break;
   }
   cout << c << endl;


}
