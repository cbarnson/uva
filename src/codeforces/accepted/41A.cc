// Problem #    : 41A
// Created on   : 2018-10-14 11:12:16
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
   reverse(begin(b), end(b));
   if (a == b) {
      cout << "YES" << endl;
   } else
      cout << "NO" << endl;
   
   


}
