// Problem #    : 271A
// Created on   : 2018-10-14 11:16:44
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

bool f(int i) {
   string s = to_string(i);
   sort(begin(s), end(s));
   auto j = unique(begin(s), end(s));
   return (j - begin(s)) == (int)s.length();
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int y;
   cin >> y;
   
   int x = y + 1;
   while (!f(x)) x++;

   cout << x << endl;
   


}
