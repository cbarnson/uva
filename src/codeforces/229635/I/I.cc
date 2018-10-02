#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;



int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   bitset<1000010> bs;
   bs.reset();
   for (int i = 0; i <= 1000; i++) {
     bs[i * i] = 1;
   }

   int n;
   cin >> n;

   int ans, f = 0;
   FR(i, n) {
     int x; cin >> x;
     if (x < 0)
       ans = (!f ? x : max(ans, x)), f = 1;
     else if (x >= 0 && !bs[x])
       ans = (!f ? x : max(ans, x)), f = 1;
   }
   cout << ans << endl;
   

}


