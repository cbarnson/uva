// Problem #    : 96A
// Created on   : 2018-09-29 09:00:31
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

   auto i = s.find(string(7, '1'));
   auto j = s.find(string(7, '0'));

   if (i != string::npos || j != string::npos)
      cout << "YES" << endl;
   else
      cout << "NO" << endl;
   


}
