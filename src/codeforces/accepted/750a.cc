// Problem #    : 750a
// Created on   : 2018-10-20 20:53:39
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, k;
   cin >> n >> k;

   int m = 240 - k;
   int i = 1;
   while (m - 5 * i >= 0) {
      m -= 5 * i++;
      if (i == n + 1) break;
   }

   cout << i - 1<< endl;
   
   


}
