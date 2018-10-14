// Problem #    : 58A
// Created on   : 2018-10-14 09:28:53
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

   string h = "hello";
   int i = 0;
   for (int j = 0; j < (int)s.length(); j++) {
      if (s[j] == h[i]) i++;
      if (i == 5) break;
   }

   if (i == 5) cout << "YES" << endl;
   else cout << "NO" << endl;


}
