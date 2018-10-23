// Problem #    : 599a
// Created on   : 2018-10-23 09:46:01
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int a, b, c;
   cin >> a >> b >> c;

   int x = a + a + b + b;
   int y = a + a + c + c;
   int z = b + b + c + c;
   int w = a + b + c;

   cout << min(min(x, y), min(z, w)) << endl;
   


}
