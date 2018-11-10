// Problem #  : 251C
// Created on : 2018-Nov-09 20:00:02
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#if __has_include("default_cf.h")
#include "default_cf.h"
#define DEBUG 1
#endif

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

ll LCM(ll a, ll b) { return a * (b / __gcd(a, b)); }

ll k;

ll LCM_k() {
  ll ans = 2;
  for (ll i = 2; i <= k; i++) {
    ans = LCM(ans, i);
  }
  return ans;
}

ll Steps(ll from, ll to) {
  ll cnt = 0;
  while (from > to) {
    ll mx = -1;
    for (ll i = 2; i <= k && i <= from; i++) {
      ll j = from % i;
      ll k = mx == -1 ? 1 : (from % mx);
      if (j > k) mx = i;
    }
    if (mx != -1) {
      assert(mx > 1);
      ll j = from % mx;
      assert(j > 0);
      from = from - (from % mx), cnt++;
    } else
      from--, cnt++;
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll hi, lo;
  cin >> hi >> lo >> k;

  ll L = LCM_k();

  if (L > hi) {
    cout << Steps(hi, lo) << endl;
    return 0;
  }

  ll Ln = hi - (hi % L);
  // DB(Ln, L, hi, lo);

  ll ans;
  if (Ln <= hi && Ln >= lo && ((Ln - lo) >= L)) {
    ll i = (Ln - lo) / L;
    ll j = (Ln - lo) % L;
    ans = Steps(hi, Ln) + (i * Steps(Ln, Ln - L)) + Steps(lo + j, lo);
  } else if (Ln <= hi && Ln >= lo && ((Ln - lo) < L)) {
    ans = Steps(hi, Ln) + Steps(Ln, lo);
  } else {
    ans = Steps(hi, lo);
  }
  cout << ans << endl;
}
