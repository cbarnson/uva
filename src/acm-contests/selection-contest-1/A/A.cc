#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;

vector<ii> A(150010, ii(0, 0));

int main() {
  int n;
  cin >> n;

  ll a, b, c;
  FR(i, n) {
    cin >> A[i].first >> A[i].second;
    if (!i) {
      c = A[i].first * A[i].second;
    } else {
      c = __gcd(c, A[i].first * A[i].second);
    }
  }

  FR(i, n) {
    ll d = __gcd(c, A[i].first);
    c = d == 1 ? __gcd(c, A[i].second) : d;
  }
  cout << (c == 1 ? -1 : c) << endl;
}