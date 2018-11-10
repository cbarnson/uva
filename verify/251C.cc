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

ll BFS(ll from, ll to) {
  if (from == to) return 0LL;

  queue<ii> q;
  q.emplace(0LL, from);
  while (!q.empty()) {
    auto f = q.front();
    q.pop();

    ll dist = f.first, val = f.second;

    if (val < 0) {
      assert(0);
    }
    if (val == to) {
      ll result = dist;
      return result;
    }

    q.emplace(f.first + 1, f.second - 1);

    for (ll i = 2; i <= k; i++) {
      if ((val % i) > 1) {
        ll new_dist = dist + 1LL;
        ll new_val = val - (val % i);
        q.emplace(new_dist, new_val);
      }
    }
  }
  assert(0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll hi, lo;
  cin >> hi >> lo >> k;

  ll L = LCM_k();

  if (L > hi) {
    cout << BFS(hi, lo) << endl;
    return 0;
  }

  // L <= hi
  ll Ln = hi - (hi % L);
  ll ans = BFS(hi, Ln);

  if (Ln > lo) {
    ll L1 = Ln - ((Ln - lo) / L) * L;
    if (Ln > L1 && L1 >= lo) {
      ll cnt = (Ln - L1) / L;
      ll i_val = BFS(L1 + L, L1);

      ans += (cnt * i_val) + BFS(L1, lo);
      cout << ans << endl;
      return 0;
    }

    ans += BFS(Ln, lo);
    cout << ans << endl;
  }
}
