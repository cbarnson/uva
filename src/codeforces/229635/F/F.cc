#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, m;
   cin >> n >> m;

   vector<dd> A(n);
   for (auto &x : A) cin >> x.first >> x.second;

   double ans; int f = 0;
   for (auto &x : A) {
     double y = (x.first / x.second) * (double)m;
     if (!f) ans = y, f = 1;
     else ans = min(ans, y);
   }

   cout << setprecision(8) << fixed << ans << endl;

}


