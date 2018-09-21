#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const double eps = 1e-10;

double A[1005];
int n;

bool f(double x) {
   for (int i = 1; i < n; i++) {
      if (((A[i] - A[i-1]) / 2) > x)
	 return false;
   }
   return true;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int l;
   cin >> n >> l;

   REP(i, n) {
      cin >> A[i];
   }

   sort(A, A+n);
   double lo = 0.0, hi = 0.0;
   while (!f(hi)) hi = (hi < 1 ? 1 : hi * 2);
   while (hi - lo > eps) {
      double mid = lo + (hi - lo) / 2;
      (f(mid) ? hi : lo) = mid;
   }

   cout << setprecision(10) << fixed << max(A[0] - 0.0, max(hi, (double)l - A[n-1])) << endl;

   

}


