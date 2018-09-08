// Problem #    : e
// Created on   : 2018-09-08 12:11:39

#include <bits/stdc++.h>

#define ALL(c) (c).begin(), (c).end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())

using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int c[] = { 1, 6, 1, 2, 2, 3, 1, 4, 0, 1 };

int main() {

   char a, b;
   while (cin >> a >> b) {
      int aa = c[(int)(a - '0')] + 1, bb = c[(int)(b - '0')] + 1;      
      int ans = aa * bb;
      cout << ans << endl;
   }
   
   return 0;
}
