// Problem #    : 476a
// Created on   : 2018-10-23 08:17:01
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;   

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, m;
   cin >> n >> m;

   int lo = (n + 1) / 2;
   int x = (lo + m - 1) / m * m;
   if (x > n) cout << -1 << endl;
   else cout << x << endl;
}
