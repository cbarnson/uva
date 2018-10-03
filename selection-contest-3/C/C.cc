#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<ll> A(n);
  for (auto &x : A)
    cin >> x;
  sort(begin(A), end(A));

  ll diff = 0;
  for (int i = 0; i < n; i++) {
    ll j = i + 1;
    ll x = A[i] - j;
    if (x < 0)
      x *= -1LL;
    diff += x;
  }
  cout << diff << endl;
}
