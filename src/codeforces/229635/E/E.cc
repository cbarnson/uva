#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int t, n, k;
   cin >> t;
   while (t--) {
      cin >> n >> k;
      vi A(k);
      for (auto &x : A) cin >> x;

      int ans = max(A.front(), n - A.back());
      vi B(k);
   }

}


