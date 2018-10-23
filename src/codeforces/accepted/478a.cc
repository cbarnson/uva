// Problem #    : 478a
// Created on   : 2018-10-23 09:11:13
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   vi A(5);
   for (auto &x : A) cin >> x;
   int s = accumulate(begin(A), end(A), 0);
   if (s >= 5 && s % 5 == 0)
      cout << s / 5 << endl;
   else
      cout << -1 << endl;
   


}
