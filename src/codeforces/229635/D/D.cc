#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int x, y;
   cin >> x >> y;

   if (y == 0 || x < (y-1)) {
      cout << "No" << endl;
      return 0;
   }

   if ((x - y + 1) % 2 == 0) {
      cout << "Yes" << endl;
   } else {
      cout << "No" << endl;
   }

}


