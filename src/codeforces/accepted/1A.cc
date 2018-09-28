// Problem #    : 1A
// Created on   : 2018-09-27 21:08:14
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   ll n, m, a;
   cin >> n >> m >> a;

   cout << ((n + a - 1) / a) * ((m + a - 1) / a) << endl;
   


}
