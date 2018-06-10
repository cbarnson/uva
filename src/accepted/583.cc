// Problem #    : 583
// Created on   : 2018-06-09 23:11:06

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef vector<vector<int>> vec2d;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

ll sz;
vector<ll> vp;
bitset<10000010> p;

void sieve(ll m) {
  sz = m + 1;
  p.set();
  p[0] = p[1] = 0;
  for (ll i = 2; i <= sz; i++) {
    if (p[i]) {
      for (ll j = i * i; j <= sz; j += i) {
        p[j] = 0;
      }
      vp.push_back(i);
    }
  }
}

bool isPrime(ll x) {
  if (x <= sz) {
    return p[x];
  }
  for (int i = 0; i < (int)vp.size(); i++) {
    if (x % vp[i] == 0) {
      return false;
    }
  }
  return true;
}

vector<ll> primeDivisors(ll n) {
  vector<ll> ans;
  ll i = 0, pf = vp[i];
  while (pf * pf <= n) {
    while (n % pf == 0) {
      n /= pf;
      ans.push_back(pf);
    }
    pf = vp[++i];
  }
  if (n != 1) {
    ans.push_back(n);
  }
  sort(ans.begin(), ans.end());
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // note: when sieve(sqrt(2147483647)), get runtime error
  // safer to use 1,000,000 here to avoid such issues
  sieve(1000000);

  ll n;
  while (cin >> n) {
    if (n == 0) {
      break;
    }

    ll f = (n < 0) ? -1 : 1;
    cout << n << " = ";
    if (n < 0) {
      cout << "-1 x ";
    }
    if (isPrime(f * n)) {
      cout << f * n << endl;
    } else {
      vector<ll> fac = primeDivisors(f * n);
      for (int i = 0; i < (int)fac.size(); i++) {
        cout << fac[i];
        if (i == (int)fac.size() - 1) {
          cout << endl;
        } else {
          cout << " x ";
        }
      }
    }
  }

  return 0;
}
