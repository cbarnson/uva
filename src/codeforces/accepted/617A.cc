// Problem #    : 617A
// Created on   : 2018-10-14 12:26:07
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   vi A = { 5, 4, 3, 2, 1 };
   int n;
   cin >> n;

   int i = 0, cnt = 0;
   while (n > 0) {
      cnt += (n / A[i]), n %= A[i];
      i++;
   }
   cout << cnt << endl;
   


}
