// Problem #    : 516
// Created on   : 2018-06-15 21:24:25

// all CPP header files
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

vi primes;
ll sz;
bitset<10000010> p;

void sieve(ll m) {
  sz = m + 1;
  p.set();
  p[0] = p[1] = 0;
  for (ll i = 2; i <= sz; i++) {
    if (p[i]) {
      for (ll j = i * i; j <= sz; j += i) p[j] = 0;
      primes.push_back(i);
    }
  }
}

bool isPrime(ll n) {
  if (n <= sz) return p[n];
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  sieve(1000000);

  string s;
  while (getline(cin, s) && s != "0") {
    stringstream ss(s);
    ll n, p, x = 1;
    while (ss >> n >> p) {
      x *= pow(n, p);
    }

    x -= 1;
    vi fac = factors(x);
    multiset<int, greater<int>> m(fac.begin(), fac.end());
    for (auto i = m.begin(); i != m.end(); i = m.upper_bound(*i)) {
      if (i != m.begin()) cout << " ";
      cout << *i << " " << m.count(*i);
    }
    cout << endl;
  }

  return 0;
}
