// Problem #    : 546A
// Created on   : 2018-10-14 10:36:38
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   ll k, n, w;
   cin >> k >> n >> w;

   ll s = k * ((w * (w + 1)) / 2);
   cout << max(s - n, 0LL) << endl;
   


}
