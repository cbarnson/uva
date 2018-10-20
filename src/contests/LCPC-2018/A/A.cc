#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i) 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);


   ll n, l;
   cin >> n >> l;

   ll s = 0;
   for (int i = 0; i < n; i++) {
      ll x; cin >> x;
      s += x;
      if (s >= l) break;
   }

   cout << s - l << endl;

}
