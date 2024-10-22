// Problem #    : 466a
// Created on   : 2018-10-18 17:47:50
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, m, a, b;
   cin >> n >> m >> a >> b;

   int x = n * a;
   int y = (n / m) * b + (n % m) * a;
   int z = ((n + m - 1) / m) * b;
   
   cout << min(x, min(y, z)) << endl;
   
}
