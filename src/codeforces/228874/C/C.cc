#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int l, r, a;
   cin >> l >> r >> a;

   int d = abs(l - r);
   if (a < d)
      cout << 2 * (a + min(l, r)) << endl;
   else
      cout << 2 * (max(l, r) + (a == d ? 0 : ((a - d) / 2))) << endl;
}


