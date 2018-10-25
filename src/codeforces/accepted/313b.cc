// Problem #    : 313b
// Created on   : 2018-10-25 11:14:28
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   string s;
   cin >> s;

   vi a((int)s.size(), 0);
   for (int i = 1; i < a.size(); i++) {
      if (s[i] == s[i - 1]) a[i] = 1;
   }

   vi b(s.size());
   partial_sum(begin(a), end(a), begin(b));

   int m;
   cin >> m;

   FR(i, m) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      cout << b[r] - b[l] << endl;
   }
      
   


}
