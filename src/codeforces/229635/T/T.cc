#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, k;
  cin >> n >> k;
  vi A(n);

  ll sum = 0;
  for (auto &x : A) {
    cin >> x;
    sum += x;
  }

  double s = (double)sum / (double)n;
  ll cnt = 0;
  while ((ll)(s + 0.5) < k) {
    s = sum * n + sum + (k * n) - sum;
    s /= (double)(n * n + n);
    sum += k;
    cnt++, n++;
  }
  cout << cnt << endl;
}