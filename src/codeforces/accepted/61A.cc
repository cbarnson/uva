// Problem #    : 61A
// Created on   : 2018-10-14 13:44:10
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   string a, b;
   cin >> a >> b;

   FR(i, (int)a.length()) {
      if (a[i] != b[i]) cout << 1;
      else cout << 0;
   }
   cout << endl;
   


}
