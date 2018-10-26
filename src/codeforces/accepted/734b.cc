// Problem #    : 734b
// Created on   : 2018-10-25 20:07:12
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int a[4] = {};
   FR(i, 4) cin >> a[i];

   int y = min(a[0], min(a[2], a[3]));
   int ans = 256 * y;
   a[0] -= y;
   ans += 32 * (min(a[0], a[1]));

   cout << ans << endl;
   


}
