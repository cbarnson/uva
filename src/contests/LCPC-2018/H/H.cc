#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i) 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cout << fixed << setprecision(8);
   double h, w, d;
   cin >> h >> w >> d;

   double cosW = (h * h + d * d - w * w);
   if (cosW < (-2.0 * h * d) || cosW > (2.0 * h * d)) {
      cout << "No" << endl;
      return 0;
   }

   cout << "Yes" << endl;
   cout << 0.0 << " " << 0.0 << endl;
   cout << h << " " << 0.0 << endl;
   
   double x = cosW / (2.0 * h);
   cout << x << " " << sqrt(d*d - x*x) << endl;
}
