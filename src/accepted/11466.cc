// Problem #    : 11466
// Created on   : 2018-06-15 18:00:24

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
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;

vi primes;
bitset<10000010> p;
ll sz;

void sieve(ll m) {
  sz = m + 1;
  p.set();
  p[0] = p[1] = 0;
  for (ll i = 2; i <= sz; i++) {
    if (p[i]) {
      for (ll j = i * i; j <= sz; j += i) {
        p[j] = 0;
      }
      primes.push_back(i);
    }
  }
}

bool isPrime(ll n) {
  if (n <= sz) {
    return p[n];
  }
  for (int i = 0; i < (int)primes.size(); i++)
    if (n % primes[i] == 0) return false;
  return true;
}

vi factors(ll n) {
  vi ans;
  ll i = 0, pf = primes[i];
  while (pf * pf <= n) {
    while (n % pf == 0) {
      n /= pf;
      ans.push_back(pf);
    }
    pf = primes[++i];
  }
  if (n != 1) {
    ans.push_back(n);
  }
  return ans;
}

vi diffFactors(ll n) {
  vi ans;
  ll i = 0, pf = primes[i];
  while (pf * pf <= n) {
    int c = 0;
    while (n % pf == 0) {
      c = 1;
      n /= pf;
    }
    if (c) ans.push_back(pf);
    pf = primes[++i];
  }
  if (n != 1) {
    if (find(begin(ans), end(ans), n) == ans.end()) ans.push_back(n);
  }
  return ans;
}

// slight optimization, do output evaluation inside rather than sending back
// vector
ll bigFactor(ll n) {
  vi ans;
  ll i = 0, pf = primes[i];
  while (pf * pf <= n) {
    int c = 0;
    while (n % pf == 0) {
      c = 1;
      n /= pf;
    }
    if (c) ans.push_back(pf);
    pf = primes[++i];
  }
  if (n != 1) {
    if (find(begin(ans), end(ans), n) == ans.end()) ans.push_back(n);
  }

  if ((int)ans.size() > 1) return ans.back();
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve(10000000);

  ll n;
  while (cin >> n) {
    if (n == 0) break;
    if (n < 0) n *= -1;
    if (n < 4 || isPrime(n)) {
      cout << -1 << endl;
    } else {
      cout << bigFactor(n) << endl;

      // vi ans = diffFactors(n);
      // cout << (((int)ans.size() > 1) ? ans.back() : -1) << endl;
    }
  }

  return 0;
}
