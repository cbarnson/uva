// Problem #    : 10006
// Created on   : 2018-06-14 23:11:22

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

vi primes;
ll sz;
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
      primes.push_back((int)i);
    }
  }
}

bool isPrime(ll n) {
  if (n <= sz) {
    return p[n];
  }
  for (int i = 0; i < (int)primes.size(); i++) {
    if (n % primes[i] == 0) {
      return false;
    }
  }
  return true;
}

ll modexp(ll x, ll n, ll m) {
  if (n == 0) return 1;
  if (n & 1) return ((x % m) * (modexp(x, n - 1, m))) % m;

  ll y = modexp(x, n / 2, m);
  return (y * y) % m;
}

bool isCarmichael(ll x) {
  if (isPrime(x)) return false;
  for (ll i = 2; i < x; i++) {
    if (modexp(i, x, x) != i) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve(1000000);

  ll n;
  while (cin >> n) {
    if (n == 0) break;

    if (isCarmichael(n))
      cout << "The number " << n << " is a Carmichael number.\n";
    else
      cout << n << " is normal.\n";
  }

  return 0;
}
