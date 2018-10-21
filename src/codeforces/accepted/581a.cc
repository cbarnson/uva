// Problem #    : 581a
// Created on   : 2018-10-21 09:47:08
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   
   int a, b;
   cin >> a >> b;

   int x = min(a, b);
   a -= x, b -= x;

   int y = (a / 2) + (b / 2);
   cout << x << " " << y << endl;


}
