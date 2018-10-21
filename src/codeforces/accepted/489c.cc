// Problem #    : 489c
// Created on   : 2018-10-21 11:45:26
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int d, s;
   cin >> d >> s;

   if (s == 0 && d > 1) {
      cout << -1 << " " << -1 << endl;
      return 0;
   } else if (s == 0 && d == 1) {
      cout << 0 << " " << 0 << endl;
      return 0;
   }
   
   string a = "";
   while (s > 0) {
      int x = min(s, 9);
      s -= x;
      a += (char)(x + '0');
   }
   
   if (a.size() > d) {
      cout << -1 << " " << -1 << endl;
      return 0;
   }

   
   a += string(d - a.size(), '0');
   string b = a;
   reverse(b.begin(), b.end());
   if (b.front() == '0') {
      int i = b.find_first_not_of("0");
      b[i] = b[i] - '1' + '0';
      b[0] = b[0] + '1' - '0';
   }

   cout << b << " " << a << endl;
}
