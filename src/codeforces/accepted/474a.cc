// Problem #    : 474a
// Created on   : 2018-10-23 08:57:57
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   string key = "qwertyuiopasdfghjkl;zxcvbnm,./";
   char c; cin >> c; int y = (c == 'R' ? -1 : 1);   
   string s; cin >> s;

   for (auto &x : s) {
      cout << key[y + key.find(x)];
   }
   cout << endl;
   
   


}
