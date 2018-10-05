#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n, a, b;

// bool f(int x) {
//   int aa = a, bb = b, nn = n - 2;
//   int mi = min(aa, bb);
//   while (nn > 0) {
//     if (aa - x >= x)
//       aa -= x, n--, mi = min(mi, min(aa, x));
//     else if (bb - x >= x)
//       bb -= x, n--;

//   }
//   return true;
// }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> a >> b;
  int lo = 1, hi = 1;
  while (f(hi)) hi *= 2;
  while (hi - lo > 1) {
    int mid = lo + (hi - lo) / 2;
    (f(mid) ? lo : hi) = mid;
  }
  while (!f(hi)) hi--;
  cout << hi << endl;
}
