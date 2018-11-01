// Problem #  : 621A
// Created on : 2018-Nov-01 12:19:05
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  ll s = 0;
  vector<ll> a;
  FR (i, n) {
    ll x;
    cin >> x;
    if (~x & 1)
      s += x;
    else
      a.emplace_back(x);
  }
  cout << s + accumulate(begin(a), end(a), 0LL) -
              (a.size() & 1 ? *min_element(begin(a), end(a)) : 0)
       << endl;
}
