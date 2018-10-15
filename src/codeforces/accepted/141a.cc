// Problem #    : 141a
// Created on   : 2018-10-14 16:30:05
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   string a, b, c;
   cin >> a >> b >> c;
   a += b;
   
   multiset<char> mx(a.begin(), a.end()), my(c.begin(), c.end());
   if (mx.size() == my.size() && equal(mx.begin(), mx.end(), my.begin()))
      cout << "YES" << endl;
   else
      cout << "NO" << endl;
}
