// Problem #    : 479A
// Created on   : 2018-10-14 11:39:01
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
   vi A = { a + b + c, a + b * c, (a + b) * c, a * b * c, a * b + c, a * (b + c) };
   int mx = *max_element(begin(A), end(A));
   cout << mx << endl;
}
