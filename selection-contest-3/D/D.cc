#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

ll f(int n) { return n > 0 ? (ll)log10((double)n) + 1 : 1; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  ll cnt = 0;
  while (n > 0) {

    ll x = f(n);
    ll y = 1;
    while (y * 10 <= n) {
      y *= 10;
    }
    cnt += (n - y + 1) * (ll)x;
    n = y - 1;
  }
  cout << cnt << endl;
}
