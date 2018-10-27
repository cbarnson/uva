// Problem #    : 478b
// Created on   : 2018-10-26 20:37:22
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   ll n, m;
   cin >> n >> m;

   ll x = n - m;
   ll mx = (x * (x + 1)) / 2;

   ll y = n / m, z = n % m;
   ll mi = m * ((y * (y - 1)) / 2) + z * y;

   cout << mi << " " << mx << endl;
   


}
