// Problem : UVa 900 - Brick Wall Patterns
// Author  : Cody Barnson
// Date    : Dec. 16, 2017
#include <bits/stdc++.h>
using namespace std;


int fib(int n) {
   if (n < 2)
      return (n == 0) ? 0 : 1;
   return fib(n-1) + fib(n-2);
}

typedef long long ll;
const int N = 50;
ll ff[N + 2] = { 0 };

int main() {

   ff[0] = 0;
   ff[1] = 1;
   for (int i = 2; i < N + 2; i++) {
      ff[i] = ff[i - 1] + ff[i - 2];
   }
   
   int n;
   while (cin >> n && n != 0) {
      cout << ff[n + 1] << endl;
   }
   return 0;
}
