// Problem #    : 519a
// Created on   : 2018-10-25 20:00:02
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   string s = "qrbnpk";
   vi r = { 9, 5, 3, 3, 1, 0 };

   int w = 0, b = 0;
   char c;
   while (cin >> c) {
      if (c == '.') continue;

      int i = s.find(tolower(c));
      (isupper(c) ? w : b) += r[i];
   }
   if (w < b) cout << "Black" << endl;
   else if (w > b) cout << "White" << endl;
   else cout << "Draw" << endl;
   


}
